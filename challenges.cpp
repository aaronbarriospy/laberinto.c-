INCLUIR la herramienta de entrada/salida (para poder imprimir en pantalla)
USAR el espacio de nombres estándar (para no escribir std:: todo el tiempo)

DEFINIR una constante de tipo caracter llamada MURO con el valor '#'
DEFINIR una constante de tipo caracter llamada RUTA con el valor '*'

INICIO DE LA FUNCIÓN PRINCIPAL (el jefe del programa):
    IMPRIMIR el texto: "Iniciando sistema de laberinto..." y dar un salto de línea
    IMPRIMIR el texto: "El símbolo del muro es: " seguido de la constante MURO y un salto de línea
    RETORNAR 0 (para avisar que el programa terminó con éxito)
FIN DE LA FUNCIÓN PRINCIPAL


#include <iostream>
using namespace std;

const char muro = '#';
const char ruta = '*';

int main() {
    cout << "Iniciando sistema de laberinto..." << '\n';
    cout << 'El simbolo del muro es: ' << muro << '\n';
    return 0;
}

(Las librerías y el main ya sabes cómo ponerlos, así que ponlos tú)

INICIO DE LA FUNCIÓN PRINCIPAL:
    CREAR una lista de enteros (int) llamada 'dx' que contenga estos cuatro números: {0, 1, 0, -1}
    CREAR una variable entera (int) llamada 'paso' y darle el valor de 1.
    
    IMPRIMIR el texto: "Para moverme a la derecha, mi cambio en X es: "
    IMPRIMIR el valor que está guardado en la lista 'dx' en la posición 'paso'
    IMPRIMIR un salto de línea
    
    RETORNAR 0
FIN DE LA FUNCIÓN PRINCIPAL

#include <iostream>
using namespace std;
const char muro = '#';
const char ruta = '*';

int main() {
    cout << "Iniciando sistema de laberinto..." << '\n';
    cout << "El simbolo del muro es: " << muro << '\n';

int dx[] = {0, 1, 0, -1};
int paso = 1;

cout << "Para moverme a la derecha, mi cambio en X es:";
cout << dx[paso];
cout << '\n';

return 0;
}

(Pon tus librerías, constantes y abre el main como ya sabes hacerlo)

INICIO DE LA FUNCIÓN PRINCIPAL:
    CREAR una variable de tipo caracter (char) llamada 'celda_actual' y guarda adentro el símbolo '#'
    
    PREGUNTAR: SI 'celda_actual' es exactamente igual a la constante 'muro' {
        IMPRIMIR: "¡Cuidado! Chocaste con un muro." y un salto de línea
    }
    SI NO {
        IMPRIMIR: "El camino esta libre, avanza." y un salto de línea
    }
    
    RETORNAR 0
FIN DE LA FUNCIÓN PRINCIPAL

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


(Borra lo que está dentro de tu main, y deja solo las librerías y constantes arriba)

INICIO DE LA FUNCIÓN PRINCIPAL:
    CREAR la lista: int dx[] = {0, 1, 0, -1};
    CREAR la lista: int dy[] = {-1, 0, 1, 0};
    
    BUCLE FOR: Empezar con un numero entero 'i' igual a 0; repetir mientras 'i' sea menor que 4; sumar de 1 en 1 a 'i' (se escribe i++) {
        
        IMPRIMIR: "Direccion numero: " seguido de 'i' y un salto de línea
        IMPRIMIR: "Cambio en X: " seguido del valor de dx en la posición [i] y un salto de línea
        IMPRIMIR: "Cambio en Y: " seguido del valor de dy en la posición [i] y un salto de línea
        IMPRIMIR: "---" y un salto de línea
        
    }
    
    RETORNAR 0
FIN DE LA FUNCIÓN PRINCIPAL

#include <iostream>
using namespace std;
const char muro = '#';
const char ruta = '*';

int main() {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    for (int i = 0; i < 4; i++) {
        cout << "Direccion numero: " << i << '\n';
        cout << "Cambio en X: " << dx[i] << '\n';
        cout << "Cambio en Y: " << dy[i] << '\n';
        cout << "---" << '\n';

    }
    return 0;
}


(Tus librerías y constantes arriba)

INICIO DE LA FUNCIÓN PRINCIPAL:
    CREAR una cuadrícula de 3x3 llamada 'mapa' llena de muros. Se escribe exactamente así:
    char mapa[3][3] = {
        {'#', '#', '#'},
        {'#', '#', '#'},
        {'#', '#', '#'}
    };
    
    // Ahora vamos a "cavar" un hueco en el medio.
    // La celda del medio está en la fila 1, columna 1.
    CAMBIAR el valor de mapa[1][1] para que sea igual a la constante 'ruta' (o sea, el asterisco).
    
    IMPRIMIR: "Mi mapa se ve asi:" y un salto de linea
    
    // Imprimimos la fila del medio para ver si funcionó
    IMPRIMIR: el valor de mapa[1][0]
    IMPRIMIR: el valor de mapa[1][1]
    IMPRIMIR: el valor de mapa[1][2]
    IMPRIMIR un salto de linea
    
    RETORNAR 0
FIN DE LA FUNCIÓN PRINCIPAL

#include <iostream>
using namespace std;
const char muro = '#';
const char ruta = '*';

int main() {
    char mapa[3][3] = {
        {'#', '#', '#'},
        {'#', '#', '#'},
        {'#', '#', '#'}
    };
    mapa[1][1] = ruta;
    cout << "Mi mapa se ve asi:" << '\n';
    cout << mapa[1][0] << mapa[1][1] << mapa[1][2] << '\n';
    return 0;
}