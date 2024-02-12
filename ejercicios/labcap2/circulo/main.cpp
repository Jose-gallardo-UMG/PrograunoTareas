#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Declarando Variables
    string nombre;
    int rad;



    //Obteniendo nombre del usuario
    cout << "Por favor ingresar su nombre: ";
    getline(cin, nombre);


    //Dar bienvenida al usuario
    cout << "Bienvenido " << nombre << ", a continuacion se le pedira ingresar el radio para obtener el diametro, circuferencia y area del circulo" << endl;

    //Pedir datos
    cout << "Ingresar el valor del radio: ";
    cin >> rad;


    //Calcular el diametro de la circuferencia = 2 * radio
    int Diametro = 2 * rad;


    //Calcular la circuferencia = 2 * PI * radio
    double Circuferencia = 2 * 3.14159 * rad;


    //Calcular el area del circulo = PI * radio al cuadrado
    double Area = 3.14159 * rad * rad;


    //Imprimiendo datos
    cout << "El diametro es: " << Diametro << endl;
    cout << "La circuferencia es: " << Circuferencia << endl;
    cout << "El Area es: " << Area << endl;

    return 0;
}
