#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <climits> // Necesario para usar INT_MAX

using namespace std;

#define NUMERO_EQUIPOS 6
#define MAX_GOLES 10
#define PARTIDOS_JUGADOS 10

void ejecutarCampeonato();
int generarNumeroAleatorio(int minimo, int maximo);
void llenarMatriz(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS]);
void imprimirLineaSeparadora(int num_columnas);
void imprimirTablaResultados(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]);
void imprimirTablaGolesIdaVuelta(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS], string titulo);
int determinarEquipoCampeon(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS]);
int determinarEquipoDescenso(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS]);

int main() {
    srand(time(nullptr));
    ejecutarCampeonato();
    return 0;
}

void ejecutarCampeonato() {
    int matriz_goles_ida[NUMERO_EQUIPOS][NUMERO_EQUIPOS] = {0};
    int matriz_goles_vuelta[NUMERO_EQUIPOS][NUMERO_EQUIPOS] = {0};
    int matriz_resultados[NUMERO_EQUIPOS][NUMERO_EQUIPOS] = {0};
    string equipos[NUMERO_EQUIPOS];
    char opcion;

    cout << "Ingrese los nombres de los equipos:" << endl;
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        cout << "Equipo " << i + 1 << ": ";
        getline(cin, equipos[i]);
    }

    do {
        system("clear");
        llenarMatriz(matriz_goles_ida);
        llenarMatriz(matriz_goles_vuelta);
        llenarMatriz(matriz_resultados);
        imprimirTablaResultados(matriz_resultados, equipos);
        imprimirTablaGolesIdaVuelta(matriz_goles_ida, equipos, "Tabla de Goles (Ida)");
        imprimirTablaGolesIdaVuelta(matriz_goles_vuelta, equipos, "Tabla de Goles (Vuelta)");
        int equipo_campeon = determinarEquipoCampeon(matriz_resultados);
        int equipo_descenso = determinarEquipoDescenso(matriz_resultados);
        cout << "El equipo ganador del campeonato es: " << equipos[equipo_campeon] << endl;
        cout << "El equipo que baja de categoría es: " << equipos[equipo_descenso] << endl;
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

void imprimirLineaSeparadora(int num_columnas) {
    cout << "+--------------";
    for (int i = 0; i < num_columnas; ++i) {
        cout << "----------";
    }
    cout << "+" << endl;
}

void imprimirTablaResultados(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS]) {
    cout << "Tabla de Resultados:" << endl;
    cout << setw(15) << "Equipos";
    cout << setw(10) << "PJ";
    cout << setw(10) << "PG";
    cout << setw(10) << "PE";
    cout << setw(10) << "PP";
    cout << setw(10) << "Puntos" << endl;
    imprimirLineaSeparadora(5);
    int puntos_equipo[NUMERO_EQUIPOS] = {0}; // Arreglo para almacenar los puntos de cada equipo
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        int partidos_ganados = 0;
        int partidos_empatados = 0;
        int partidos_perdidos = 0;
        int puntos = 0;
        cout << setw(15) << equipos[i];
        partidos_ganados = generarNumeroAleatorio(0, PARTIDOS_JUGADOS);
        partidos_empatados = generarNumeroAleatorio(0, PARTIDOS_JUGADOS - partidos_ganados);
        partidos_perdidos = PARTIDOS_JUGADOS - partidos_ganados - partidos_empatados;
        puntos = partidos_ganados * 3 + partidos_empatados;
        puntos_equipo[i] = puntos; // Almacenar los puntos del equipo
        cout << setw(10) << PARTIDOS_JUGADOS;
        cout << setw(10) << partidos_ganados;
        cout << setw(10) << partidos_empatados;
        cout << setw(10) << partidos_perdidos;
        cout << setw(10) << puntos << endl;
    }
    imprimirLineaSeparadora(5);
    cout << endl;
}

void imprimirTablaGolesIdaVuelta(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS], string equipos[NUMERO_EQUIPOS], string titulo) {
    cout << titulo << ":" << endl;
    cout << setw(15) << "Equipos";
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        cout << setw(10) << equipos[i];
    }
    cout << endl;
    imprimirLineaSeparadora(NUMERO_EQUIPOS);
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        cout << setw(15) << equipos[i];
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            cout << setw(10) << matriz[i][j];
        }
        cout << endl;
    }
    imprimirLineaSeparadora(NUMERO_EQUIPOS);
    cout << endl;
}

int determinarEquipoCampeon(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS]) {
    int mejor_puntaje = -1;
    int equipo_campeon = -1;
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        int partidos_ganados = 0;
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            if (i != j && matriz[i][j] > matriz[j][i]) {
                partidos_ganados++;
            }
        }
        int puntos = partidos_ganados * 3;
        if (puntos > mejor_puntaje) {
            mejor_puntaje = puntos;
            equipo_campeon = i;
        }
    }
    return equipo_campeon;
}

int determinarEquipoDescenso(int matriz[NUMERO_EQUIPOS][NUMERO_EQUIPOS]) {
    int peor_puntaje = INT_MAX;
    int equipo_descenso = -1;
    int puntos_equipo[NUMERO_EQUIPOS] = {0}; // Arreglo para almacenar los puntos de cada equipo
    for (int i = 0; i < NUMERO_EQUIPOS; ++i) {
        int partidos_perdidos = 0;
        for (int j = 0; j < NUMERO_EQUIPOS; ++j) {
            if (i != j && matriz[i][j] < matriz[j][i]) {
                partidos_perdidos++;
            }
        }
        int puntos = (PARTIDOS_JUGADOS - partidos_perdidos) * 3;
        puntos_equipo[i] = puntos; // Almacenar los puntos del equipo
        if (puntos < peor_puntaje) {
            peor_puntaje = puntos;
            equipo_descenso = i;
        }
    }
    return equipo_descenso;
}
