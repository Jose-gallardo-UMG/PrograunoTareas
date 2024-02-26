#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

#define NUMERO_EQUIPOS 6
#define MAX_GOLES 10

void ejecutarCampeonato();
int generarNumeroAleatorio(int minimo, int maximo);
void llenarMatriz(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS]);
void imprimirLineaSeparadora();
void imprimirTablaPartidos(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]);
void imprimirTablaGoles(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]);
int determinarEquipoGanador(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]);
int determinarEquipoRelegado(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]);

int main() {
    srand(time(nullptr));
    ejecutarCampeonato();
    return 0;
}

void ejecutarCampeonato() {
    int matriz_resultados[NUMERO_EQUIPOS][NUMERO_EQUIPOS] = {0};
    string equipos[NUMERO_EQUIPOS] = {"Barca", "Real", "Inter", "Bayer", "Paris", "Atletico"};
    char opcion;

    do {
        system("cls");
        llenarMatriz(matriz_resultados);
        imprimirTablaPartidos(matriz_resultados, equipos);
        imprimirTablaGoles(matriz_resultados, equipos);
        int equipo_ganador = determinarEquipoGanador(matriz_resultados, equipos);
        cout << "El equipo ganador del campeonato es: " << equipos[equipo_ganador] << endl;
        int equipo_relegado = determinarEquipoRelegado(matriz_resultados, equipos);
        cout << "El equipo que baja de categoría es: " << equipos[equipo_relegado] << endl;
        cout << "Desea calcular otro campeonato (s/n)? ";
        cin >> opcion;
        cin.ignore();
    } while (opcion == 's');
}

int generarNumeroAleatorio(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS]) {
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            if (i != j) {
                matriz[i][j] = generarNumeroAleatorio(0, MAX_GOLES);
                matriz[j][i] = generarNumeroAleatorio(0, MAX_GOLES);
            }
        }
    }
}

void imprimirLineaSeparadora(int tamano) {
    cout << "+------------------+";
    for (int i = 0; i < tamano; ++i) {
        cout << "------+";
    }
    cout << endl;
}

void imprimirTablaPartidos(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]) {
    cout << "Tabla de Partidos:" << endl;
    cout << setw(15) << "Equipos";
    cout << setw(10) << "PJ";
    cout << setw(10) << "PG";
    cout << setw(10) << "PE";
    cout << setw(10) << "PP";
    cout << endl;
    imprimirLineaSeparadora(NUMERO_EQUIPOS);
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        int partidos_jugados = 0;
        int partidos_ganados = 0;
        int partidos_empatados = 0;
        int partidos_perdidos = 0;
        cout << setw(15) << equipos[i];
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            partidos_jugados++;
            if (i != j) {
                if (matriz[i][j] > matriz[j][i]) {
                    partidos_ganados++;
                } else if (matriz[i][j] < matriz[j][i]) {
                    partidos_perdidos++;
                } else {
                    partidos_empatados++;
                }
            }
        }
        cout << setw(10) << partidos_jugados;
        cout << setw(10) << partidos_ganados;
        cout << setw(10) << partidos_empatados;
        cout << setw(10) << partidos_perdidos << endl;
    }
    imprimirLineaSeparadora(NUMERO_EQUIPOS);
}

void imprimirTablaGoles(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]) {
    cout << "Tabla de Goles:" << endl;
    cout << setw(15) << "Equipos";
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        cout << setw(10) << equipos[i];
    }
    cout << endl;
    imprimirLineaSeparadora(NUMERO_EQUIPOS);
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        cout << setw(15) << equipos[i];
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            cout << setw(10) << min(matriz[i][j] + matriz[j][i], MAX_GOLES);
        }
        cout << endl;
    }
    imprimirLineaSeparadora(NUMERO_EQUIPOS);
}

int determinarEquipoGanador(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]) {
    int mejor_puntaje = -1;
    int equipo_ganador = -1;
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        int puntaje = 0;
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            puntaje += matriz[i][j];
        }
        if (puntaje > mejor_puntaje) {
            mejor_puntaje = puntaje;
            equipo_ganador = i;
        }
    }
    return equipo_ganador;
}

int determinarEquipoRelegado(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]) {
    int peor_puntaje = MAX_GOLES * NUMERO_EQUIPOS * (NUMERO_EQUIPOS - 1);
    int equipo_relegado = -1;
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        int puntaje = 0;
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            puntaje += matriz[i][j];
        }
        if (puntaje < peor_puntaje) {
            peor_puntaje = puntaje;
            equipo_relegado = i;
        }
    }
    return equipo_relegado;
}
