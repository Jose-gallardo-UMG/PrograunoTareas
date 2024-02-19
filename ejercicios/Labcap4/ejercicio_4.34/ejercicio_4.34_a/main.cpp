#include <iostream>

using namespace std;

int main() {
    // Declaración de variables
    int n;
    unsigned long long factorial = 1;

    // Solicitar al usuario que ingrese un entero no negativo
    cout << "Ingrese un entero no negativo: ";
    cin >> n;

    // Calcular el factorial de n
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Imprimir el factorial calculado
    cout << "El factorial de " << n << " es: " << factorial << endl;

    return 0;
}
