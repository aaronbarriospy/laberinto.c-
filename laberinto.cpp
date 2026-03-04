#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;

// Caracteres ASCII para la representación
const char WALL = '#';
const char PATH = ' ';
const char ROUTE = '*';
const char START = 'E';
const char EXIT = 'S';

// Direcciones de movimiento (Arriba, Derecha, Abajo, Izquierda)
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

class MazeSystem {
private:
    int width, height;
    vector<vector<char>> grid;

    // Verifica si una coordenada está dentro de los límites
    bool isValid(int x, int y) {
        return (x > 0 && x < width - 1 && y > 0 && y < height - 1);
    }

    // Algoritmo de generación: Randomized Depth-First Search (Backtracking)
    void generateDFS(int x, int y) {
        grid[y][x] = PATH;

        // Mezclar direcciones para aleatoriedad
        int dirs[] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int r = rand() % 4;
            swap(dirs[i], dirs[r]);
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[dirs[i]] * 2;
            int ny = y + dy[dirs[i]] * 2;

            if (isValid(nx, ny) && grid[ny][nx] == WALL) {
                grid[y + dy[dirs[i]]][x + dx[dirs[i]]] = PATH; // Romper pared intermedia
                generateDFS(nx, ny);
            }
        }
    }

    // Algoritmo de resolución: Backtracking
    bool solveBacktracking(int x, int y) {
        // Caso base: Llegada a la salida
        if (x == width - 2 && y == height - 2) {
            grid[y][x] = ROUTE;
            return true;
        }

        if (grid[y][x] == PATH || grid[y][x] == START) {
            if (grid[y][x] != START) grid[y][x] = ROUTE; // Marcar camino

            // Intentar las 4 direcciones
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (solveBacktracking(nx, ny)) return true;
            }

            // Si ninguna dirección funciona, deshacer (Backtrack)
            if (grid[y][x] != START) grid[y][x] = PATH;
        }
        return false;
    }

public:
    MazeSystem(int w, int h) {
        // Ajustar a dimensiones impares para el algoritmo de laberintos
        width = (w % 2 == 0) ? w + 1 : w;
        height = (h % 2 == 0) ? h + 1 : h;
        grid.assign(height, vector<char>(width, WALL));
    }

    void generateMaze() {
        srand(time(NULL));
        generateDFS(1, 1);
        grid[1][1] = START; // Esquina superior izquierda
        grid[height - 2][width - 2] = EXIT; // Esquina inferior derecha
    }

    void solveMaze() {
        solveBacktracking(1, 1);
        grid[1][1] = START; // Restaurar marca de inicio por claridad visual
        grid[height - 2][width - 2] = EXIT; // Restaurar marca de salida
    }

    void displayMaze() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cout << grid[y][x] << ' ';
            }
            cout << '\n';
        }
        cout << string(width * 2, '-') << '\n';
    }
};

int main(int argc, char* argv[]) {
    // 1. Configuración de tamaño mediante parámetros externos
    int width = 21;
    int height = 21;

    if (argc >= 3) {
        width = stoi(argv[1]);
        height = stoi(argv[2]);
    }

    cout << "Inicializando Laberinto Maestro (" << width << "x" << height << ")...\n";
    MazeSystem maze(width, height);

    // 2. Medición de tiempo de Generación
    auto startGen = chrono::high_resolution_clock::now();
    maze.generateMaze();
    auto endGen = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> genTime = endGen - startGen;

    cout << "Laberinto Generado:\n";
    maze.displayMaze();

    // 3. Medición de tiempo de Resolución
    auto startSolve = chrono::high_resolution_clock::now();
    maze.solveMaze();
    auto endSolve = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> solveTime = endSolve - startSolve;

    cout << "Laberinto Resuelto:\n";
    maze.displayMaze();

    // 4. Reporte de Rendimiento
    cout << "Tiempo de generacion: " << genTime.count() << " ms\n";
    cout << "Tiempo de resolucion: " << solveTime.count() << " ms\n";

    return 0;
}