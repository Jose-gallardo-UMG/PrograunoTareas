#include <iostream>
#include <string>
using namespace std;

class Empleado {
public:
    // Constructor que inicializa los datos miembros
    Empleado(string primerNombre, string apellidoPaterno, int salarioMensual) {
        establecerPrimerNombre(primerNombre);
        establecerApellidoPaterno(apellidoPaterno);
        establecerSalarioMensual(salarioMensual);
    }

    // Función para establecer el primer nombre del empleado
    void establecerPrimerNombre(string nombre) {
        mPrimerNombre = nombre;
    }

    // Función para obtener el primer nombre del empleado
    string obtenerPrimerNombre() {
        return mPrimerNombre;
    }

    // Función para establecer el apellido paterno del empleado
    void establecerApellidoPaterno(string apellido) {
        mApellidoPaterno = apellido;
    }

    // Función para obtener el apellido paterno del empleado
    string obtenerApellidoPaterno() {
        return mApellidoPaterno;
    }

    // Función para establecer el salario mensual del empleado
    void establecerSalarioMensual(int salario) {
        if (salario >= 0) {
            mSalarioMensual = salario;
        } else {
            mSalarioMensual = 0;
            cout << "Error: El salario mensual no puede ser negativo. Se establecio en 0." << endl;
        }
    }

    // Función para obtener el salario mensual del empleado
    int obtenerSalarioMensual() {
        return mSalarioMensual;
    }

    // Función para obtener el salario anual del empleado
    int obtenerSalarioAnual() {
        return mSalarioMensual * 12;
    }

    // Función para aplicar un aumento del 10% al salario mensual del empleado
    void aplicarAumento() {
        mSalarioMensual *= 1.1; // Aumento del 10%
    }

private:
    string mPrimerNombre;
    string mApellidoPaterno;
    int mSalarioMensual;
};

int main() {
    string nombre1, apellido1, nombre2, apellido2;
    int salarioMensual1, salarioMensual2;

    // Solicitar información del primer empleado
    cout << "Ingrese el primer nombre del empleado 1: ";
    cin >> nombre1;
    cout << "Ingrese el apellido paterno del empleado 1: ";
    cin >> apellido1;
    cout << "Ingrese el salario mensual del empleado 1: ";
    cin >> salarioMensual1;

    // Solicitar información del segundo empleado
    cout << "Ingrese el primer nombre del empleado 2: ";
    cin >> nombre2;
    cout << "Ingrese el apellido paterno del empleado 2: ";
    cin >> apellido2;
    cout << "Ingrese el salario mensual del empleado 2: ";
    cin >> salarioMensual2;

    // Crear dos objetos Empleado
    Empleado empleado1(nombre1, apellido1, salarioMensual1);
    Empleado empleado2(nombre2, apellido2, salarioMensual2);

    // Mostrar el salario anual de cada empleado
    cout << "Salario anual de " << empleado1.obtenerPrimerNombre() << " " << empleado1.obtenerApellidoPaterno() << ": Q" << empleado1.obtenerSalarioAnual() << endl;
    cout << "Salario anual de " << empleado2.obtenerPrimerNombre() << " " << empleado2.obtenerApellidoPaterno() << ": Q" << empleado2.obtenerSalarioAnual() << endl;

    // Aplicar un aumento del 10% al salario mensual de cada empleado
    empleado1.aplicarAumento();
    empleado2.aplicarAumento();

    // Mostrar el salario anual actualizado de cada empleado
    cout << "Salario anual de " << empleado1.obtenerPrimerNombre() << " " << empleado1.obtenerApellidoPaterno() << " despues del aumento: Q" << empleado1.obtenerSalarioAnual() << endl;
    cout << "Salario anual de " << empleado2.obtenerPrimerNombre() << " " << empleado2.obtenerApellidoPaterno() << " despues del aumento: Q" << empleado2.obtenerSalarioAnual() << endl;

    return 0;
}
