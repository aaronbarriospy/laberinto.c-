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


#include <iostream>
using namespace std;

int main() {
    int balas_recogidas = 8;
    int balas_finales;

    // ESCRIBE TU CODIGO AQUI ABAJO:
    // balas_finales = ...
    balas_finales = (balas_recogidas % 2 == 0) ? balas_recogidas + 1 : balas_finales
    

    cout << "Bolas cargadas en el arma: " << balas_finales << '\n';
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int largo_trinchera = 10;
    const char BLOQUE = '=';
    
    vector<char> mi_trinchera;

    // ESCRIBE TU CODIGO AQUI ABAJO:
    // Dale la orden a 'mi_trinchera' usando .assign() para que tenga el largo y el bloque correcto.
    mi_trinchera.assign(largo_trinchera, BLOQUE);
    
    // Esto imprimira tu trinchera para comprobar si funciono
    cout << "Mi trinchera se ve asi: \n";
    for(int i = 0; i < largo_trinchera; i++) {
        cout << mi_trinchera[i];
    }
    cout << '\n';

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class CampoDeFuerza {
private:
    int tamano;
    vector<vector<char>> escudo;

public:
    // ESTE ES EL CONSTRUCTOR QUE DEBES COMPLETAR:
    CampoDeFuerza(int radio_deseado) {
        
        // 1. Usa el operador ternario para asegurar que 'tamano' sea un numero PAR.
        // (PISTA: Si radio_deseado % 2 != 0, entonces sumale 1)
        tamano = (radio_deseado % 2 != 0) ? radio_deseado + 1 : radio_deseado;
        
        // 2. Usa .assign() para rellenar la matriz 'escudo'.
        // Recuerda que es alto, vector<char>(ancho, simbolo)
        escudo.assign(tamano, <vector<char>(tamano, '0'));
        
    }
};

int main() {
    CampoDeFuerza miEscudo(5); // Le pasamos un 5 (impar), tu codigo deberia arreglarlo a 6.
    cout << "Escudo construido en la memoria con exito!\n";
    return 0;
}


#include <iostream>
using namespace std;

bool puedeEntrar(int edad, int tiene_vip) {
    // ESCRIBE TU CÓDIGO AQUÍ:
    // Retorna verdadero SOLO SI la edad es mayor o igual (>=) a 18 
    // Y (&&) si tiene_vip es exactamente igual (==) a 1.
    if (edad >= 18 && tiene_vip == 1) {
    return true;
    } else {
        return false;
    }
    
}

int main() {
    bool acceso = puedeEntrar(20, 1);
    
    if (acceso == true) {
        cout << "Bienvenido al club.\n";
    } else {
        cout << "Acceso denegado.\n";
    }
    return 0;
}

#include <iostream>
using namespace std;

bool tiroValido(int x, int limite_derecho) {
    // ESCRIBE TU CÓDIGO AQUÍ:
    // Retorna verdadero si x es mayor o igual a 0 Y menor que limite_derecho
    return (x >= 0 && x < limite_derecho);
}

int main() {
    int impacto = 5;
    if (tiroValido(impacto, 10)) {
        cout << "¡Tiro en el blanco!\n";
    } else {
        cout << "Tiro fallado, fuera de los limites.\n";
    }
    return 0;
}


#include <iostream>
using namespace std;

bool dentroDelTablero(int x, int y) {
    int tamano_tablero = 8;
    
    // ESCRIBE TU CÓDIGO AQUÍ:
    // Retorna verdadero SI:
    // 1. x es mayor o igual a 0 Y menor que tamano_tablero
    // 2. Y y es mayor o igual a 0 Y menor que tamano_tablero
    return (x >= 0 && x < tamano_tablero && y >= 0 && y < tamano_tablero);
}

int main() {
    int caballo_x = 3;
    int caballo_y = 8; // ¡Oops! Esto está fuera del tablero
    
    if (dentroDelTablero(caballo_x, caballo_y)) {
        cout << "Movimiento legal.\n";
    } else {
        cout << "¡El caballo se cayo de la mesa!\n";
    }
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    char celda_actual = 'V'; // Imagina que el robot pisó una ventana
    char COLOR_ROJO = 'R';
    char VENTANA = 'V';

    // ESCRIBE TU CÓDIGO AQUÍ:
    // SI celda_actual es DISTINTA (!=) a VENTANA, entonces
    // cambia el valor de celda_actual a COLOR_ROJO.
    if (celda_actual != VENTANA) {
        celda_actual = COLOR_ROJO;
    }
    cout << "El estado de la celda es: " << celda_actual << '\n';
    // Debería imprimir 'V', porque la protegiste y no la pintaste.
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Un caminito de 5 pasos, todos vacíos
    vector<char> bosque = {' ', ' ', ' ', ' ', ' '};
    int mi_posicion = 2; // Estoy parado en el medio

    // PASO 1: DEJAR LA MIGAJA
    // Cambia el valor de bosque en 'mi_posicion' por un asterisco '*'
   bosque[mi_posicion] = '*';
    
    cout << "Deje la migaja: [" << bosque[mi_posicion] << "]\n";

    // PASO 2: EL CALLEJÓN SIN SALIDA (BACKTRACKING)
    // Te das cuenta de que no hay salida. 
    // Vuelve a cambiar bosque en 'mi_posicion' por un espacio vacío ' '
   bosque[mi_posicion] = ' ';
    
    
    cout << "Recogi la migaja: [" << bosque[mi_posicion] << "]\n";

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    char INICIO = 'E';
    char RUTA = '*';
    char CAMINO = ' ';
    
    // Una mini cuadricula de 3x3
    vector<vector<char>> cuadricula = {
        {'#', '#', '#'},
        {'#', 'E', '#'}, // El inicio esta en x=1, y=1
        {'#', '#', '#'}
    };
    
    int x = 1;
    int y = 1;

    // ESCRIBE TU CODIGO AQUI:
    
    // 1. INTENTO DE AVANCE: 
    // SI cuadricula[y][x] NO ES IGUAL (!=) a INICIO...
    // ...entonces la cuadricula[y][x] recibe la RUTA;
    if (cuadricula[y][x] != INICIO) {
        cuadricula[y][x] = RUTA;
    }
    
    cout << "Al avanzar, la celda (1,1) tiene: " << cuadricula[y][x] << '\n';

    // 2. RETROCESO (BACKTRACKING):
    // SI cuadricula[y][x] NO ES IGUAL (!=) a INICIO...
    // ...entonces la cuadricula[y][x] recibe el CAMINO;
    if (cuadricula[y][x] != INICIO) {
        cuadricula[y][x] = CAMINO;
    }
    
    cout << "Al retroceder, la celda (1,1) tiene: " << cuadricula[y][x] << '\n';

    return 0;
}