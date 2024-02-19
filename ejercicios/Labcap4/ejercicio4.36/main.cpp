#include <iostream>

using namespace std;

// Función para encriptar un número entero de cuatro dígitos
int encriptar(int numero) {
    //declarar las variables por cada digito (4 en este caso)
    int digito1;
    int digito2;
    int digito3;
    int digito4;

    // Hacer el encriptado segun las instrucciones en el ejercicio
    digito1 = (numero / 1000 + 7) % 10;
    digito2 = ((numero / 100) % 10 + 7) % 10;
    digito3 = ((numero / 10) % 10 + 7) % 10;
    digito4 = (numero % 10 + 7) % 10;

    // regresar el numero incriptado
    return digito3 * 1000 + digito4 * 100 + digito1 * 10 + digito2;
}

// Función para desencriptar un número entero de cuatro dígitos encriptado
int desencriptar(int encriptado) {
    //declarar las variables por cada digito (4 en este caso)
    int digito1;
    int digito2;
    int digito3;
    int digito4;

    // Extraer los dígitos individuales del número encriptado haciendo lo opuesto de la encriptacion
    digito1 = (encriptado / 1000 - 7 + 10) % 10;  // Restamos 7 y sumamos 10 para evitar resultados negativos (se divide por 1000 para obtener el primer digito)
    digito2 = ((encriptado / 100) % 10 - 7 + 10) % 10;// Restamos 7 y sumamos 10 para evitar resultados negativos (se divide por 100 para obtener el segundo digito)
    digito3 = ((encriptado / 10) % 10 - 7 + 10) % 10;// Restamos 7 y sumamos 10 para evitar resultados negativos (se divide por 10 para obtener el tercer digito)
    digito4 = (encriptado % 10 - 7 + 10) % 10;// Restamos 7 y sumamos 10 para evitar resultados negativos (se divide por 10 para obtener el cuarto digito)

    // Desencriptar el número encriptado
    return digito3 * 1000 + digito4 * 100 + digito1 * 10 + digito2;
}


int main() {
    // Declaración de variables
    int numeroOriginal;
    int numeroEncriptado;
    int numeroDesencriptado;

    // Solicitar al usuario que ingrese el número entero de cuatro dígitos
    cout << "Ingrese un numero entero de cuatro digitos: ";
    cin >> numeroOriginal;

    // Encriptar el número ingresado con la funcion encriptar
    numeroEncriptado = encriptar(numeroOriginal);
    cout << "El numero encriptado es: " << numeroEncriptado << endl;

    // Desencriptar el número encriptado con la funcion desencriptar
    numeroDesencriptado = desencriptar(numeroEncriptado);
    cout << "El numero desencriptado (numero original) es: " << numeroDesencriptado << endl;

    return 0;
}
