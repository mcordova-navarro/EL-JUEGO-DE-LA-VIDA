#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

class Celula {
private:
    int estado;

public:
    Celula(int estado = 0) : estado(estado) {}
    int obtenerEstado() const { return estado; }
    void establecerEstado(int nuevoEstado) { estado = nuevoEstado; }

};



class Celulas {
private:
    int filas;
    int columnas;
    vector<vector<Celula>> matriz;

    int contarVecinos(int fila, int columna) const {
        int vecinos = 0;
        for (int i = fila - 1; i <= fila + 1; i++) {
            for (int j = columna - 1; j <= columna + 1; j++) {
                if (i >= 0 && i < filas && j >= 0 && j < columnas && !(i == fila && j == columna)) {
                    vecinos += matriz[i][j].obtenerEstado();
                }
            }
        }
        return vecinos;
    }

public:
    Celulas(int filas, int columnas) : filas(filas), columnas(columnas), matriz(filas, vector<Celula>(columnas)) {}

    void imprimirCuadricula() const {
        // Limpiar la pantalla
        (void)system("cls");

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (matriz[i][j].obtenerEstado() == 1) {
                    cout << "0 ";
                } else {
                    cout << "_ ";
                }
            }
            cout << "\n";
        }
    }

    void actualizarCuadricula() {
        // Crear una nueva matriz vacía
        vector<vector<Celula>> nuevaMatriz(filas, vector<Celula>(columnas));

        // Actualizar cada célula según las reglas del juego
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                int vecinos = contarVecinos(i, j);
                if (matriz[i][j].obtenerEstado() == 1) {
                    // Reglas para células vivas
                    if (vecinos < 2 || vecinos > 3) {
                        nuevaMatriz[i][j].establecerEstado(0);
                    } else {
                        nuevaMatriz[i][j].establecerEstado(1);
                    }
                } else {
                    // Reglas para células muertas
                    if (vecinos == 3) {
                        nuevaMatriz[i][j].establecerEstado(1);
                    } else {
                        nuevaMatriz[i][j].establecerEstado(0);
                    }
                }
            }
        }

        // Actualizar la matriz actual
        matriz = nuevaMatriz;
    }

    void inicializarCuadriculaAleatoria() {
        srand(time(0));
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j].establecerEstado(rand() % 2);
            }
        }
    }

    void setBlinker() {
        // Asignar los valores para dibujar un rectángulo de 3*1 en el centro
        matriz[filas / 2 - 1][columnas / 2].establecerEstado(1);
        matriz[filas / 2][columnas / 2].establecerEstado(1);
        matriz[filas / 2 + 1][columnas / 2].establecerEstado(1);
    }

    void setBeacon() {
        // Asignar los valores para dibujar un beacon en el centro
        matriz[filas/2 - 2][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 - 2][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2][columnas/2].establecerEstado(1);
        matriz[filas/2][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 + 1].establecerEstado(1);
    }

    void setPulsar() {
        // Asignar los valores para dibujar un pulsar en el centro
        matriz[filas/2 - 6][columnas/2 - 4].establecerEstado(1);
        matriz[filas/2 - 6][columnas/2 - 3].establecerEstado(1);
        matriz[filas/2 - 6][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 - 6][columnas/2 + 2].establecerEstado(1);
        matriz[filas/2 - 6][columnas/2 + 3].establecerEstado(1);
        matriz[filas/2 - 6][columnas/2 + 4].establecerEstado(1);
        matriz[filas/2 - 4][columnas/2 - 6].establecerEstado(1);
        matriz[filas/2 - 4][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 - 4][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 - 4][columnas/2 + 6].establecerEstado(1);
        matriz[filas/2 - 3][columnas/2 - 6].establecerEstado(1);
        matriz[filas/2 - 3][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 - 3][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 - 3][columnas/2 + 6].establecerEstado(1);
        matriz[filas/2 - 2][columnas/2 - 6].establecerEstado(1);
        matriz[filas/2 - 2][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 - 2][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 - 2][columnas/2 + 6].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 - 4].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 - 3].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 + 2].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 + 3].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 + 4].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 4].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 3].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 + 2].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 + 3].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 + 4].establecerEstado(1);
        matriz[filas/2 + 2][columnas/2 - 6].establecerEstado(1);
        matriz[filas/2 + 2][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 + 2][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 + 2][columnas/2 + 6].establecerEstado(1);
        matriz[filas/2 + 3][columnas/2 - 6].establecerEstado(1);
        matriz[filas/2 + 3][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 + 3][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 + 3][columnas/2 + 6].establecerEstado(1);
        matriz[filas/2 + 4][columnas/2 - 6].establecerEstado(1);
        matriz[filas/2 + 4][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 + 4][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 + 4][columnas/2 + 6].establecerEstado(1);
        matriz[filas/2 + 6][columnas/2 - 4].establecerEstado(1);
        matriz[filas/2 + 6][columnas/2 - 3].establecerEstado(1);
        matriz[filas/2 + 6][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 + 6][columnas/2 + 2].establecerEstado(1);
        matriz[filas/2 + 6][columnas/2 + 3].establecerEstado(1);
        matriz[filas/2 + 6][columnas/2 + 4].establecerEstado(1);
    }

    void setPenta() {
        // Asignar los valores para dibujar un penta-decatlon en el centro
        matriz[filas/2][columnas/2-5].establecerEstado(1);
        matriz[filas/2][columnas/2-4].establecerEstado(1);
        matriz[filas/2-1][columnas/2-3].establecerEstado(1);
        matriz[filas/2+1][columnas/2-3].establecerEstado(1);
        matriz[filas/2][columnas/2-2].establecerEstado(1);
        matriz[filas/2][columnas/2-1].establecerEstado(1);
        matriz[filas/2][columnas/2].establecerEstado(1);
        matriz[filas/2][columnas/2+1].establecerEstado(1);
        matriz[filas/2-1][columnas/2+2].establecerEstado(1);
        matriz[filas/2+1][columnas/2+2].establecerEstado(1);
        matriz[filas/2][columnas/2+3].establecerEstado(1);
        matriz[filas/2][columnas/2+4].establecerEstado(1);
    }

    void setGlider() {
        // Asignar los valores para dibujar un glider en el centro
        matriz[filas/2 - 1][columnas/2].establecerEstado(1);
        matriz[filas/2][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 + 1].establecerEstado(1);
    }

    void setLight() {
        // Asignar los valores para dibujar un light weight spaceship en el centro
        matriz[filas/2 - 2][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 - 2][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2 -3].establecerEstado(1);
        matriz[filas/2][columnas/2 - 3].establecerEstado(1);
        matriz[filas/2][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 3].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2].establecerEstado(1);
    }

    void setGosper() {
        // Asignar los valores para dibujar un gosper glider gun en la esquina superior izquierda
        matriz[filas/2 - 4][24].establecerEstado(1);
        matriz[filas/2 - 3][22].establecerEstado(1);
        matriz[filas/2 - 3][24].establecerEstado(1);
        matriz[filas/2 - 2][12].establecerEstado(1);
        matriz[filas/2 - 2][13].establecerEstado(1);
        matriz[filas/2 - 2][20].establecerEstado(1);
        matriz[filas/2 - 2][21].establecerEstado(1);
        matriz[filas/2 - 2][34].establecerEstado(1);
        matriz[filas/2 - 2][35].establecerEstado(1);
        matriz[filas/2 - 1][11].establecerEstado(1);
        matriz[filas/2 - 1][15].establecerEstado(1);
        matriz[filas/2 - 1][20].establecerEstado(1);
        matriz[filas/2 - 1][21].establecerEstado(1);
        matriz[filas/2 - 1][34].establecerEstado(1);
        matriz[filas/2 - 1][35].establecerEstado(1);
        matriz[filas/2][0].establecerEstado(1);
        matriz[filas/2][1].establecerEstado(1);
        matriz[filas/2][10].establecerEstado(1);
        matriz[filas/2][16].establecerEstado(1);
        matriz[filas/2][20].establecerEstado(1);
        matriz[filas/2][21].establecerEstado(1);
        matriz[filas/2 + 1][0].establecerEstado(1);
        matriz[filas/2 + 1][1].establecerEstado(1);
        matriz[filas/2 + 1][10].establecerEstado(1);
        matriz[filas/2 + 1][14].establecerEstado(1);
        matriz[filas/2 + 1][16].establecerEstado(1);
        matriz[filas/2 + 1][17].establecerEstado(1);
        matriz[filas/2 + 1][22].establecerEstado(1);
        matriz[filas/2 + 1][24].establecerEstado(1);
        matriz[filas/2 + 2][10].establecerEstado(1);
        matriz[filas/2 + 2][16].establecerEstado(1);
        matriz[filas/2 + 2][24].establecerEstado(1);
        matriz[filas/2 + 3][11].establecerEstado(1);
        matriz[filas/2 + 3][15].establecerEstado(1);
        matriz[filas/2 + 4][12].establecerEstado(1);
        matriz[filas/2 + 4][13].establecerEstado(1);
    }
    void setCuadrado() {
        // Asignar los valores para dibujar un cuadrado de 2*2 en el centro
        matriz[filas/2 - 1][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2].establecerEstado(1);
        matriz[filas/2][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2][columnas/2].establecerEstado(1);
    }

    void setBeehive() {
        // Asignar los valores para dibujar un beehive en el centro
        matriz[filas/2 - 1][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 - 1][columnas/2].establecerEstado(1);
        matriz[filas/2][columnas/2 - 2].establecerEstado(1);
        matriz[filas/2][columnas/2 + 1].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2 - 1].establecerEstado(1);
        matriz[filas/2 + 1][columnas/2].establecerEstado(1);
    }

    void limpiarMatriz() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j].establecerEstado(0);
            }
        }
    }
};


int main() {
    // Definir el tiempo de espera entre generaciones en milisegundos
    int espera = 200;

    int filas;
    int columnas;
    char continuar;
    int opcion;
    
    cout << "Ingrese el alto y ancho deseado: ";
    cin >> filas >> columnas;
    // Limpiar la pantalla
    (void)system("cls");



    // Crear una instancia de la clase Celulas
    Celulas celulas(filas, columnas);

    

    do {
        // Etiqueta para volver al menú principal
        mainMenu:

        cout << "Bienvenido al juego, elija una opcion:\n";
        cout << " 1. Osciladores\n 2. Naves espaciales\n 3. Caniones\n 4. Vidas estaticas\n 5. Mapeo randomizado\n\n";
        cin >> opcion;
        cout << "\n";
        // Limpiar la pantalla
        (void)system("cls");

        switch (opcion) {
            case 1:
                int oscilador;
                cout << "Elige un tipo de oscilador: \n";
                cout << " 1. Blinker\n 2. Beacon\n 3. Pulsar\n 4. Penta-Decathlon\n 5. Volver al menu principal\n\n ";
                cin >> oscilador;
                cout << "\n";
                switch(oscilador){
                    case 1: celulas.setBlinker();
                        break;
                    case 2: celulas.setBeacon();
                        break;
                    case 3: celulas.setPulsar();
                        break;
                    case 4: celulas.setPenta();
                        break;
                    case 5: 
                        // Limpiar la pantalla
                        (void)system("cls"); 
                        goto mainMenu;
                    default: cout << "Opcion invalida";
                }
                break;

            case 2:
                int nave;
                cout << "Elige un tipo de nave espacial: \n";
                cout << " 1. Glider\n 2. Light-Weight-Spaceship\n 3. Volver al menu principal\n\n ";
                cin >> nave;
                cout << "\n";
                switch(nave){
                    case 1: celulas.setGlider();
                        break;
                    case 2: celulas.setLight();
                        break;
                    case 3: 
                        // Limpiar la pantalla
                        (void)system("cls");
                        goto mainMenu;
                    default: cout << "Opcion invalida";
                }
                break;

            case 3:
                int canon;
                cout << "Elige un tipo de canion: \n";
                cout << " 1. Gosper Glider Gun\n 2. Volver al menu principal\n\n";
                cin >> canon;
                cout << "\n";
                switch(canon){
                    case 1: celulas.setGosper();
                        break;
                    case 2: 
                        // Limpiar la pantalla
                        (void)system("cls");
                        goto mainMenu;
                    default: cout << "Opcion invalida";
                }
                break;

            case 4:
                int estatico;
                cout << "Elige un tipo de vida estatica: \n";
                cout << " 1. Cuadrados\n 2. Beehive\n 3. Volver al menu principal\n\n ";
                cin >> estatico;
                cout << "\n";
                switch(estatico){
                    case 1: celulas.setCuadrado();
                        break;
                    case 2: celulas.setBeehive();
                        break;
                    case 3: 
                        // Limpiar la pantalla
                        (void)system("cls");
                        goto mainMenu;
                    default: cout << "Opcion invalida";
                }
                break;

            case 5:
                // Inicializar la cuadrícula de manera aleatoria
                celulas.inicializarCuadriculaAleatoria();
                break;

            default:
                cout << "Opcion no valida";
        }

        // Limpiar la pantalla
        (void)system("cls");

        // Simular el juego de la vida hasta que el usuario presione Enter
        while (true) {
            // Actualizar la cuadrícula
            celulas.actualizarCuadricula();
            // Imprimir la cuadrícula actualizada
            celulas.imprimirCuadricula();
            // Esperar un tiempo
            this_thread::sleep_for(chrono::milliseconds(espera));

            // Verificar si se ha presionado Enter
            if (_kbhit()) {
                continuar = _getch();
                if (continuar == 13) {
                    // 13 es el código ASCII para Enter
                    celulas.limpiarMatriz();
                    break;  // Salir del bucle si se presiona Enter
                }
            }
        }

        cout << "¿Desea volver al menu principal? (S/N): ";
        cin >> continuar;
        // Limpiar la pantalla
        (void)system("cls");
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
