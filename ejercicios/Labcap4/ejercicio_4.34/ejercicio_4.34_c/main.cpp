#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Declaraci�n de variables
    int precision;
    double x, e = 1;
    unsigned long long factorial = 1;

    // Solicitar al usuario la precisi�n deseada de e
    cout << "Ingrese la precisi�n deseada de e (n�mero de t�rminos de la suma): ";
    cin >> precision;

    // Solicitar al usuario el valor de x
    cout << "Ingrese el valor de x para e^x: ";
    cin >> x;

    // Calcular la suma de la serie para estimar e^x
    for (int i = 1; i <= precision; ++i) {
        factorial *= i;
        e += pow(x, i) / factorial;
    }

    // Imprimir el valor calculado de e^x
    cout << "El valor calculado de e^" << x << " es: " << e << endl;

    return 0;
}
