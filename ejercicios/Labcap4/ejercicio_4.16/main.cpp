#include <iostream>

using namespace std;

int main() {
    // Definir variables
    double horas_trabajadas, tarifa_por_horas, sueldo_bruto;

    // Instrucción repetitiva para recibir entrada de datos para cada empleado
    cout << "Introduzca las horas trabajadas (-1 para salir): ";
    cin >> horas_trabajadas;

    while (horas_trabajadas != -1) {
        cout << "Introduzca la tarifa por horas del empleado ($00.00): ";
        cin >> tarifa_por_horas;

        // Calcular el sueldo bruto para el empleado
        if (horas_trabajadas <= 40) {
            sueldo_bruto = horas_trabajadas * tarifa_por_horas;
        } else {
            sueldo_bruto = (40 * tarifa_por_horas) + ((horas_trabajadas - 40) * 1.5 * tarifa_por_horas);
        }

        // Mostrar el sueldo bruto del empleado
        cout << "El salario es $" << sueldo_bruto << endl;

        // Solicitar la entrada de datos para el próximo empleado o salir del programa
        cout << "Introduzca las horas trabajadas (-1 para salir): ";
        cin >> horas_trabajadas;
    }

    return 0;
}
