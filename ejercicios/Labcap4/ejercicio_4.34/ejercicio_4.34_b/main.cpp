#include <iostream>

using namespace std;

int main() {
    // Declaración de variables
    int precision;
    double e = 1;
    unsigned long long factorial = 1;

    // Solicitar al usuario la precisión deseada de e
    cout << "Ingrese la precisión deseada de e (número de términos de la suma): ";
    cin >> precision;

    // Calcular la suma de la serie para estimar e
    for (int i = 1; i <= precision; ++i) {
        factorial *= i;
        e += 1.0 / factorial;
    }

    // Imprimir el valor estimado de e
    cout << "El valor estimado de e es: " << e << endl;

    return 0;
}
