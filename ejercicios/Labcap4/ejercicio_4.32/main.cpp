#include <iostream>

using namespace std;

int main() {
    // Declaración de variables
    double lado1, lado2, lado3;

    // Solicitar al usuario que ingrese los lados del triángulo
    cout << "Ingrese el primer lado del triángulo: ";
    cin >> lado1;
    cout << "Ingrese el segundo lado del triángulo: ";
    cin >> lado2;
    cout << "Ingrese el tercer lado del triángulo: ";
    cin >> lado3;

    // Verificar si los lados dados pueden formar un triángulo
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        cout << "Los lados dados pueden formar un triángulo." << endl;
    } else {
        cout << "Los lados dados no pueden formar un triángulo." << endl;
    }

    return 0;
}
