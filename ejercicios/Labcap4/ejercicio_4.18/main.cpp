#include <iostream>

using namespace std;

int main() {
    // Inicializar las variables para los valores de la tabla
    int n = 1;
    int diez_n = 10;
    int cien_n = 100;
    int mil_n = 1000;

    // Imprimir la primera línea de la tabla
    cout << "N\t10N\t100N\t1000N\n";

    // Imprimir una línea en blanco
    cout << "\n";

    // Inicializar el contador para el bucle while
    int contador = 1;

    // Usar un bucle while para imprimir las siguientes líneas de la tabla
    while (contador <= 5) {
        // Imprimir los valores de la fila actual de la tabla
        cout << n << "\t" << diez_n << "\t" << cien_n << "\t" << mil_n << "\n";

        // Actualizar los valores para la próxima fila de la tabla
        n++;
        diez_n += 10;
        cien_n += 100;
        mil_n += 1000;

        // Incrementar el contador
        contador++;
    }

    return 0;
}
