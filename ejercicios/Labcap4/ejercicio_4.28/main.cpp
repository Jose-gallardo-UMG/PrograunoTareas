#include <iostream>

using namespace std;

int main() {
    for (int fila = 1; fila <= 8; ++fila) {
        for (int columna = 1; columna <= 8; ++columna) {
            // Verifica si la fila es par o impar para decidir si imprimir un asterisco o un espacio
            if (fila % 2 == 0) {
                cout << " *";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}
