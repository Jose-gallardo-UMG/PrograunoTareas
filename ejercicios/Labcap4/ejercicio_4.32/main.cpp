#include <iostream>

using namespace std;

int main() {
    // Declaraci�n de variables
    double lado1, lado2, lado3;

    // Solicitar al usuario que ingrese los lados del tri�ngulo
    cout << "Ingrese el primer lado del tri�ngulo: ";
    cin >> lado1;
    cout << "Ingrese el segundo lado del tri�ngulo: ";
    cin >> lado2;
    cout << "Ingrese el tercer lado del tri�ngulo: ";
    cin >> lado3;

    // Verificar si los lados dados pueden formar un tri�ngulo
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        cout << "Los lados dados pueden formar un tri�ngulo." << endl;
    } else {
        cout << "Los lados dados no pueden formar un tri�ngulo." << endl;
    }

    return 0;
}
