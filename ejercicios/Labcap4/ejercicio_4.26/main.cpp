#include <iostream>

using namespace std;

bool esPalindromo(int numero) {
    int original = numero;
    int reverso = 0;

    while (numero > 0) {
        int digito = numero % 10;
        reverso = reverso * 10 + digito;
        numero = numero / 10;
    }

    return original == reverso;
}

int main() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    if (esPalindromo(numero)) {
        cout << "El numero " << numero << " es un palindromo." << endl;
    } else {
        cout << "El numero " << numero << " no es un palindromo." << endl;
    }

    return 0;
}
