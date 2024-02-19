#include <iostream>

using namespace std;

int main() {
    // Declaración de variables
    double radio, diametro, circunferencia, area;
    const double pi = 3.14159;

    // Solicitar al usuario que ingrese el radio del círculo
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;

    // Calcular el diámetro, la circunferencia y el área
    diametro = 2 * radio;
    circunferencia = 2 * pi * radio;
    area = pi * radio * radio;

    // Imprimir los resultados
    cout << "El diametro del circulo es: " << diametro << endl;
    cout << "La circunferencia del circulo es: " << circunferencia << endl;
    cout << "El area del circulo es: " << area << endl;

    return 0;
}
