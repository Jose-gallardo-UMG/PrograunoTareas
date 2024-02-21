// Ejemplo de utilizaci�n de matrices codigo heredado de C
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

#define NUMERO_ALUMNOS 5
#define NUMERO_NOTAS 4
#define MIN_CALIFICACION 0

// Funci�n para ejecutar el ciclo principal del programa
void llamaCiclo();

// Funci�n para generar un n�mero aleatorio dentro de un rango
int generarNumeroAleatorio(int minimo, int maximo);

// Funci�n para llenar la matriz de calificaciones con valores aleatorios
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);

// Funci�n para imprimir una l�nea separadora en la matriz
void imprimirMatrizLinea();

// Funci�n para imprimir la matriz de calificaciones
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], string nombreFacultad);

int main() {
    srand(time(nullptr)); // Inicializar la semilla para generar n�meros aleatorios
    llamaCiclo(); // Llamar a la funci�n principal del programa
    return 0;
}

void llamaCiclo() {
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;

    do {
        system("cls"); // Limpiar la pantalla (Windows)

        // Inicializar los promedios de las facultades
        float promedio_facultad_1 = 0;
        float promedio_facultad_2 = 0;
        float promedio_facultad_3 = 0;

        cout << "*** Comparativo de Facultades ***" << endl << endl;

        // Llenar y mostrar la matriz de la Facultad de Ingenier�a
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, "Facultad de Ingenieria");

        // Llenar y mostrar la matriz de la Facultad de Arquitectura
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, "Facultad de Arquitectura");

        // Llenar y mostrar la matriz de la Facultad de Administraci�n
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, "Facultad de Administracion");

        // Determinar la facultad con el mejor promedio
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3) {
            cout << " La facultad con el mejor promedio es : Facultad de Ingenieria Promedio: " << promedio_facultad_1 << endl;
        } else if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3) {
            cout << " La facultad con el mejor promedio es : Facultad de Arquitectura Promedio: " << promedio_facultad_2 << endl;
        } else if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1) {
            cout << " La facultad con el mejor promedio es : Facultad de Administracion Promedio: " << promedio_facultad_3 << endl;
        } else {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }

        // Solicitar al usuario si desea realizar otro c�lculo
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
    } while (opcion == 's');
}

int generarNumeroAleatorio(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]) {
    for (int i = 0; i < NUMERO_ALUMNOS; i++) {
        float suma = 0;
        for (int j = 0; j < NUMERO_NOTAS; j++) {
            // Generar calificaciones aleatorias para cada alumno y sumarlas
            if (j == 0 || j == 3) {
                matriz[i][j] = generarNumeroAleatorio(MIN_CALIFICACION, 20);
            } else if (j == 1) {
                matriz[i][j] = generarNumeroAleatorio(MIN_CALIFICACION, 25);
            } else if (j == 2) {
                matriz[i][j] = generarNumeroAleatorio(MIN_CALIFICACION, 35);
            }
            suma += matriz[i][j];
        }
        matriz[i][NUMERO_NOTAS] = suma; // Almacenar el total en la �ltima columna
    }
}

void imprimirMatrizLinea() {
    cout << "+--------";
    for (int i = 0; i < NUMERO_NOTAS + 1; i++) {
        cout << "+---------";
    }
    cout << "+\n";
}

float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], string nombreFacultad) {
    float promedioGeneral = 0;
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (int i = 0; i < NUMERO_NOTAS; i++) {
        cout << setw(9) << "Nota" << i + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (int i = 0; i < NUMERO_ALUMNOS; i++) {
        cout << "!" << setw(8) << "Alumno " << i + 1 << "!";
        float suma = 0;
        for (int j = 0; j < NUMERO_NOTAS; j++) {
            cout << setw(9) << matriz[i][j] << "!";
            suma += matriz[i][j];
        }
        float promedio = suma / NUMERO_NOTAS; // Calcular el promedio del alumno
        promedioGeneral += promedio; // Sumar el promedio al total general
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral /= NUMERO_ALUMNOS; // Calcular el promedio general
    cout << "Promedio general: " << promedioGeneral << endl << endl;
    return promedioGeneral;
}
