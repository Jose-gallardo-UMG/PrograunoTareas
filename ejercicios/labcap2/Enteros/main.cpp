#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nombre;
    int Entero1, Entero2;


    //Obteniendo nombre del usuario
    cout << "Por favor ingresar su nombre: ";
    getline(cin, nombre);


    //Dar bienvenida al usuario
    cout << "Bienvenido " << nombre << ", a continuacion se le pedira ingresar los valores de los dos numeros enteros para poder comparar cual es el mayor o si son iguales " << endl;


    //Pedir datos
    cout << "Ingresar el primer valor entero: ";
    cin >> Entero1;

    cout << "Ingresar el segundo valor entero: ";
    cin >> Entero2;


    //Inicio del ciclo IF
    if (Entero1 > Entero2) {
            cout << "El numero " << Entero1 << " es el mayor " << endl;

    } else if (Entero2 > Entero1) {
            cout << "El numero " << Entero2 << " es el mayor " << endl;

    } else {
            cout << "Estos numeros son iguales" << endl;

    }
    return 0;
}
