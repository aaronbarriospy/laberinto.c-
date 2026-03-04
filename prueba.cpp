#include <iostream>
using namespace std;
const char muro = '#';
const char ruta = '*';

int main() {
    cout << "Iniciando sistema de laberinto" << '\n';
    cout << "El simbolo del muro es: " << muro << '\n';

int dx[] = {0, 1, 0, -1};
int paso = 1;
cout << "Para moverme a la derecha, mi cambio en X es: ";
cout << dx[paso];
cout << '\n';

char celda_actual = '#';
if (celda_actual == muro){
    cout << "Cuidado! Chocaste con un muro" << '\n';
}
else {
    cout << "El camino esta libre, avanza." << '\n';
}
return 0;
}