#include <iostream>

using namespace std;

int main() {
    // Declaraci�n de variables
    double radio, diametro, circunferencia, area;
    const double pi = 3.14159;

    // Solicitar al usuario que ingrese el radio del c�rculo
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;

    // Calcular el di�metro, la circunferencia y el �rea
    diametro = 2 * radio;
    circunferencia = 2 * pi * radio;
    area = pi * radio * radio;

    // Imprimir los resultados
    cout << "El diametro del circulo es: " << diametro << endl;
    cout << "La circunferencia del circulo es: " << circunferencia << endl;
    cout << "El area del circulo es: " << area << endl;

    return 0;
}
