#include <iostream>
using namespace std;

class Cuenta {
public:
    //saldo inicial
    Cuenta(int saldoInicial) {
        if (saldoInicial >= 0) {
            saldo = saldoInicial;
        } else {
            saldo <= 0;
            cout << "Error: El saldo inicial no puede ser negativo. Se establecio el saldo en 0." << endl;
        }
    }

    //abonar un monto al saldo
    void abonar(int monto) {
        saldo += monto;
    }

    //cargar un monto del saldo
    void cargar(int monto) {
        if (monto <= saldo) {
            saldo -= monto;
        } else {
            cout << "El monto a cargar excede el saldo de la cuenta." << endl;
        }
    }

    // obtener el saldo actual
    int obtenerSaldo() {
        return saldo;
    }

private:
    int saldo; // Saldo de la cuenta
};

int main() {
    int saldoInicialCuenta1, saldoInicialCuenta2;
    cout << "Ingrese el saldo inicial de la cuenta 1: ";
    cin >> saldoInicialCuenta1;

    cout << "Ingrese el saldo inicial de la cuenta 2: ";
    cin >> saldoInicialCuenta2;

    //objetos
    Cuenta cuenta1(saldoInicialCuenta1);
    Cuenta cuenta2(saldoInicialCuenta2);

    int montoAbonoCuenta1, montoAbonoCuenta2, montoCargoCuenta1, montoCargoCuenta2;
    cout << "Ingrese el monto a abonar en la cuenta 1: ";
    cin >> montoAbonoCuenta1;
    cuenta1.abonar(montoAbonoCuenta1);

    cout << "Ingrese el monto a abonar en la cuenta 2: ";
    cin >> montoAbonoCuenta2;
    cuenta2.abonar(montoAbonoCuenta2);

    cout << "Ingrese el monto a cargar en la cuenta 1: ";
    cin >> montoCargoCuenta1;
    cuenta1.cargar(montoCargoCuenta1);

    cout << "Ingrese el monto a cargar en la cuenta 2: ";
    cin >> montoCargoCuenta2;
    cuenta2.cargar(montoCargoCuenta2);

    //saldos finales
    cout << "Saldo de cuenta1 despues de abonar y cargar: " << cuenta1.obtenerSaldo() << endl;
    cout << "Saldo de cuenta2 despues de abonar y cargar: " << cuenta2.obtenerSaldo() << endl;

    return 0;
}
