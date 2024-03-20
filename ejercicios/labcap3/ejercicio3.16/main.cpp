#include <iostream>
#include <string>
using namespace std;

class FrecuenciasCardiacas {
public:
    FrecuenciasCardiacas(string nombre, string apellido, int mesNacimiento, int diaNacimiento, int anioNacimiento, int mesActual, int diaActual, int anioActual)
        : mNombre(nombre), mApellido(apellido), mMesNacimiento(mesNacimiento), mDiaNacimiento(diaNacimiento), mAnioNacimiento(anioNacimiento), mMesActual(mesActual), mDiaActual(diaActual), mAnioActual(anioActual) {}

    int obtenerEdad() {
        int edad = mAnioActual - mAnioNacimiento;
        if (mMesActual < mMesNacimiento || (mMesActual == mMesNacimiento && mDiaActual < mDiaNacimiento)) {
            edad--;
        }
        return edad;
    }

    int obtenerFrecuenciaCardiacaMaxima() {
        return 220 - obtenerEdad();
    }

    int obtenerFrecuenciaMinimaEsperada() {
        return obtenerFrecuenciaCardiacaMaxima() * 0.5;
    }

    int obtenerFrecuenciaMaximaEsperada() {
        return obtenerFrecuenciaCardiacaMaxima() * 0.85;
    }

private:
    string mNombre;
    string mApellido;
    int mMesNacimiento;
    int mDiaNacimiento;
    int mAnioNacimiento;
    int mMesActual;
    int mDiaActual;
    int mAnioActual;
};

int main() {
    string nombre, apellido;
    int mesNacimiento, diaNacimiento, anioNacimiento;
    int mesActual, diaActual, anioActual;

    cout << "Ingrese el primer nombre: ";
    cin >> nombre;
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    cout << "Ingrese el mes de nacimiento (1-12): ";
    cin >> mesNacimiento;
    cout << "Ingrese el dia de nacimiento: ";
    cin >> diaNacimiento;
    cout << "Ingrese el anio de nacimiento: ";
    cin >> anioNacimiento;

    cout << "Ingrese el mes actual: ";
    cin >> mesActual;
    cout << "Ingrese el dia actual: ";
    cin >> diaActual;
    cout << "Ingrese el anio actual: ";
    cin >> anioActual;

    FrecuenciasCardiacas persona(nombre, apellido, mesNacimiento, diaNacimiento, anioNacimiento, mesActual, diaActual, anioActual);

    cout << "\nInformacion de la persona:" << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Fecha de nacimiento: " << mesNacimiento << "/" << diaNacimiento << "/" << anioNacimiento << endl;

    int edad = persona.obtenerEdad();
    cout << "Edad: " << edad << " anios" << endl;

    int frecuenciaMaxima = persona.obtenerFrecuenciaCardiacaMaxima();
    cout << "Frecuencia cardiaca maxima: " << frecuenciaMaxima << " pulsos por minuto" << endl;

    int frecuenciaMinimaEsperada = persona.obtenerFrecuenciaMinimaEsperada();
    int frecuenciaMaximaEsperada = persona.obtenerFrecuenciaMaximaEsperada();
    cout << "Rango de frecuencia cardiaca esperada: " << frecuenciaMinimaEsperada << " - " << frecuenciaMaximaEsperada << " pulsos por minuto" << endl;

    return 0;
}
