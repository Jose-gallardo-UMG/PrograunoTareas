#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Declarando Variables
    string nombre;
    double num1, num2;


    //Solicitando nombre al usuario
    cout << "Por favor ingresar su nombre: ";
    getline(cin, nombre);


    //Dar bienvenida al usuario
    cout << "Bienvenido " << nombre << ", a continuacion se le pedira ingresar los valores de los dos numeros " << endl;


    //Solicitando los datos al usuario
    cout << "Ingresar el primer numero: ";
    cin >> num1;

    cout << "Ingresar el segundo numero: ";
    cin >> num2;


    //Calculando la suma, producto, diferencia y cociente de los dos numeros
    double suma = num1 + num2;
    double producto = num1 * num2;
    double diferencia = num1 - num2;
    double cociente = num1 / num2;


    //Imprimeindo datos
    cout << "La suma de " << num1 << " y " << num2 << " es: " << suma << endl;
    cout << "El producto de " << num1 << " y " << num2 << " es: " << producto << endl;
    cout << "La Diferencia de " << num1 << " y " << num2 << " es: " << diferencia << endl;
    cout << "La cociente de " << num1 << " y " << num2 << " es: " << cociente << endl;

    return 0;
}
