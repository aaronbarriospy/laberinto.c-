#include <iostream>   // Permite usar cout para imprimir en la consola (nuestra visualización ASCII).
#include <vector>     // Estructura de datos dinámica, más segura y flexible que los arrays tradicionales de C.
#include <cstdlib>    // Necesario para las funciones rand() y srand() que dan la aleatoriedad.
#include <ctime>      // Necesario para time(), usado para inicializar la semilla aleatoria.
#include <chrono>     // Librería moderna de C++ para medir el tiempo de ejecución con alta precisión.
#include <string>     // Para manipular cadenas de texto fácilmente.

using namespace std;  // Nos evita escribir "std::" antes de cada cout, vector, string, etc.

// ---------------------------------------------------------
// 1. CONFIGURACIÓN VISUAL (CONSTANTES)
// ---------------------------------------------------------
// Usamos constantes para que si en el futuro quieres cambiar los emojis o caracteres,
// solo tengas que hacerlo en un lugar y no buscar por todo el código.
const char WALL = '#';   // Representa un muro infranqueable.
const char PATH = ' ';   // Representa un espacio por el que podemos caminar.
const char ROUTE = '*';  // Representa el camino correcto que encuentra nuestro algoritmo.
const char START = 'E';  // La Entrada del laberinto.
const char EXIT = 'S';   // La Salida del laberinto.

// ---------------------------------------------------------
// 2. VECTORES DE DIRECCIÓN (TRUCO DE MAGIA MATEMÁTICO)
// ---------------------------------------------------------
// En lugar de hacer 4 "if" kilométricos para ir Arriba, Derecha, Abajo e Izquierda,
// usamos estos dos arrays. Si estamos en (x, y) y queremos movernos, sumamos dx[i] y dy[i].
// Índice 0: ( 0, -1) -> Moverse hacia Arriba.
// Índice 1: ( 1,  0) -> Moverse hacia la Derecha.
// Índice 2: ( 0,  1) -> Moverse hacia Abajo.
// Índice 3: (-1,  0) -> Moverse hacia la Izquierda.
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// ---------------------------------------------------------
// 3. LA CLASE PRINCIPAL DEL SISTEMA
// ---------------------------------------------------------
class MazeSystem {
private:
    int width, height;             // Ancho y alto del laberinto.
    vector<vector<char>> grid;     // Una matriz bidimensional (vector de vectores) que guarda nuestro mapa.

    // Función auxiliar que responde: "¿Esta coordenada (x,y) está dentro de los bordes del mapa?"
    bool isValid(int x, int y) {
        // Retorna verdadero (true) solo si x e y son mayores a 0 y menores al límite.
        // Esto evita que rompamos los muros exteriores del laberinto.
        return (x > 0 && x < width - 1 && y > 0 && y < height - 1);
    }

    // ---------------------------------------------------------
    // GENERACIÓN: Algoritmo "Recursive Backtracker" (DFS)
    // ---------------------------------------------------------
    void generateDFS(int x, int y) {
        grid[y][x] = PATH; // El primer paso: pisamos la celda actual y la convertimos en un camino libre.

        int dirs[] = {0, 1, 2, 3}; // Creamos una lista con las 4 direcciones posibles.
        
        // Bucle para desordenar (mezclar) las direcciones aleatoriamente.
        // Si no hacemos esto, el laberinto siempre tendría forma de "escalera" o un patrón repetitivo.
        for (int i = 0; i < 4; i++) {
            int r = rand() % 4;         // Elegimos un número al azar entre 0 y 3.
            swap(dirs[i], dirs[r]);     // Intercambiamos la dirección actual con la elegida al azar.
        }

        // Ahora intentamos avanzar en las 4 direcciones, pero en el orden aleatorio que acabamos de crear.
        for (int i = 0; i < 4; i++) {
            // ¡OJO AQUÍ! Multiplicamos por 2. 
            // En la generación de laberintos, saltamos una celda de por medio (nx, ny).
            // Esa celda que saltamos es el "muro" que luego decidiremos si derribar o no.
            int nx = x + dx[dirs[i]] * 2;
            int ny = y + dy[dirs[i]] * 2;

            // Si la celda destino a la que saltamos está dentro del mapa y TODAVÍA es un muro...
            if (isValid(nx, ny) && grid[ny][nx] == WALL) {
                // ...entonces derribamos el muro que quedó en medio de nuestro salto.
                // Lo calculamos sumando solo 1 vez la dirección desde nuestra posición original (x, y).
                grid[y + dy[dirs[i]]][x + dx[dirs[i]]] = PATH; 
                
                // Llamamos a la misma función (Recursividad) desde la nueva posición para seguir escarbando.
                generateDFS(nx, ny); 
            }
        }
    }

    // ---------------------------------------------------------
    // RESOLUCIÓN: Algoritmo Backtracking (Ensayo y Error Lógico)
    // ---------------------------------------------------------
    bool solveBacktracking(int x, int y) {
        // 1. CASO BASE (Condición de victoria):
        // Si nuestras coordenadas actuales coinciden con la meta (esquina inferior derecha)...
        if (x == width - 2 && y == height - 2) {
            grid[y][x] = ROUTE; // Marcamos la meta como parte de la ruta.
            return true;        // Gritamos "¡Lo encontré!" hacia atrás en la cadena recursiva.
        }

        // 2. REGLA DE AVANCE:
        // Solo podemos pisar esta celda si es un camino vacío (PATH) o es la entrada (START).
        if (grid[y][x] == PATH || grid[y][x] == START) {
            
            // Marcamos esta celda temporalmente como parte de la ruta correcta con un '*'.
            // (A menos que sea la 'E' de entrada, para no borrar la letra).
            if (grid[y][x] != START) grid[y][x] = ROUTE; 

            // Exploramos las 4 direcciones adyacentes posibles paso a paso.
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i]; // Aquí NO multiplicamos por 2, caminamos normal.
                int ny = y + dy[i];

                // Entramos a la celda adyacente. Si esa celda eventualmente nos lleva a la salida (retorna true)...
                if (solveBacktracking(nx, ny)) {
                    return true; // ...entonces esta celda también es el camino correcto. Retornamos true.
                }
            }

            // 3. EL "BACKTRACK" (EL RETROCESO):
            // Si el bucle "for" terminó y ninguna de las 4 direcciones nos llevó a la salida,
            // significa que nos metimos en un callejón sin salida.
            // Así que DESHACEMOS nuestra pisada, borramos el '*' y volvemos a poner un espacio vacío.
            if (grid[y][x] != START) grid[y][x] = PATH;
        }
        
        // Si chocamos con un muro o la celda ya estaba visitada, retornamos falso para que el código busque otro lado.
        return false;
    }

public:
    // Constructor de la clase: Se ejecuta automáticamente al crear un "MazeSystem".
    MazeSystem(int w, int h) {
        // Los laberintos basados en este algoritmo requieren que el ancho y alto sean números impares
        // para que los muros y caminos encajen perfectamente. Si pasamos un número par, le sumamos 1.
        width = (w % 2 == 0) ? w + 1 : w;
        height = (h % 2 == 0) ? h + 1 : h;
        
        // Llenamos toda la matriz de la cuadrícula con muros ('#') desde el principio.
        grid.assign(height, vector<char>(width, WALL));
    }

    // Método público para iniciar la generación.
    void generateMaze() {
        srand(time(NULL)); // Inicializamos la semilla aleatoria usando el reloj de la computadora.
        generateDFS(1, 1); // Empezamos a escarbar el laberinto desde la coordenada (1,1).
        
        grid[1][1] = START;                 // Ponemos la letra 'E' en la entrada.
        grid[height - 2][width - 2] = EXIT; // Ponemos la letra 'S' en la salida.
    }

    // Método público para iniciar la resolución.
    void solveMaze() {
        solveBacktracking(1, 1); // Empezamos a buscar la salida desde (1,1).
        
        // El backtracking podría sobrescribir la E y la S con el asterisco '*',
        // así que por estética visual, las volvemos a dibujar al terminar.
        grid[1][1] = START; 
        grid[height - 2][width - 2] = EXIT; 
    }

    // Imprime la matriz en la consola fila por fila, columna por columna.
    void displayMaze() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cout << grid[y][x] << ' '; // Imprimimos el caracter seguido de un espacio para que no se vea aplastado.
            }
            cout << '\n'; // Salto de línea al terminar una fila.
        }
        // Imprime una línea separadora bonita debajo del laberinto.
        cout << string(width * 2, '-') << '\n';
    }
};

// ---------------------------------------------------------
// 4. EL PUNTO DE ENTRADA DEL PROGRAMA (MAIN)
// ---------------------------------------------------------
int main(int argc, char* argv[]) {
    // argc = Cantidad de argumentos pasados por consola.
    // argv = Los valores de esos argumentos.
    
    int width = 21;  // Tamaño por defecto si el usuario no especifica nada.
    int height = 21; 

    // Requisito: "El laberinto se define con parámetros externos".
    // Si el usuario ejecuta el programa pasándole números (ej: ./laberinto 15 15), argc será mayor o igual a 3.
    // (argv[0] es el nombre del programa, argv[1] el ancho, argv[2] el alto).
    if (argc >= 3) {
        width = stoi(argv[1]);  // Convierte el texto recibido del ancho a un número entero (String TO Integer).
        height = stoi(argv[2]); // Convierte el texto recibido del alto a un número entero.
    }

    cout << "Inicializando Laberinto Maestro (" << width << "x" << height << ")...\n";
    MazeSystem maze(width, height); // Creamos el objeto laberinto.

    // --- REQUISITO: MEDICIÓN DE TIEMPO DE GENERACIÓN ---
    auto startGen = chrono::high_resolution_clock::now(); // Marca de tiempo inicial.
    maze.generateMaze();                                  // Generamos el laberinto.
    auto endGen = chrono::high_resolution_clock::now();   // Marca de tiempo final.
    // Calculamos la diferencia en milisegundos.
    chrono::duration<double, milli> genTime = endGen - startGen; 

    cout << "Laberinto Generado:\n";
    maze.displayMaze(); // Mostramos cómo quedó vacío.

    // --- REQUISITO: MEDICIÓN DE TIEMPO DE RESOLUCIÓN ---
    auto startSolve = chrono::high_resolution_clock::now();
    maze.solveMaze();                                     // Algoritmo buscando la salida.
    auto endSolve = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> solveTime = endSolve - startSolve;

    cout << "Laberinto Resuelto:\n";
    maze.displayMaze(); // Mostramos el camino resuelto con asteriscos.

    // Imprimimos las estadísticas de optimización que pide el entregable.
    cout << "Tiempo de generacion: " << genTime.count() << " ms\n";
    cout << "Tiempo de resolucion: " << solveTime.count() << " ms\n";

    return 0; // Termina el programa exitosamente.
}