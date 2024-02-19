#include <iostream>

using namespace std;

int main() {
    // Definir variables
    int numero_cuenta;
    double saldo_inicial, cargos_totales, creditos_totales, limite_credito, nuevo_saldo;

    // Instrucción repetitiva para recibir entrada de datos
    cout << "Introduzca el numero de cuenta (-1 para salir): ";
    cin >> numero_cuenta;

    while (numero_cuenta != -1) {
        cout << "Introduzca el saldo inicial: ";
        cin >> saldo_inicial;

        cout << "Introduzca los cargos totales: ";
        cin >> cargos_totales;

        cout << "Introduzca los creditos totales: ";
        cin >> creditos_totales;

        cout << "Introduzca el limite de credito: ";
        cin >> limite_credito;

        // Calcular el nuevo saldo
        nuevo_saldo = saldo_inicial + cargos_totales - creditos_totales;

        // Verificar si se excedió el límite de crédito
        if (nuevo_saldo > limite_credito) {
            // Mostrar la información del cliente y un mensaje de exceso de crédito
            cout << "El nuevo saldo es " << nuevo_saldo << endl;
            cout << "Cuenta: " << numero_cuenta << endl;
            cout << "Limite de credito: " << limite_credito << endl;
            cout << "Saldo: " << nuevo_saldo << endl;
            cout << "Se excedio el limite de su credito" << endl;
        }

        // Volver a solicitar el número de cuenta para continuar o terminar el programa
        cout << "Introduzca el numero de cuenta (-1 para salir): ";
        cin >> numero_cuenta;
    }

    return 0;
}
