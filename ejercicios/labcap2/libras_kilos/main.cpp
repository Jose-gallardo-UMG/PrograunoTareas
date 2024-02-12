#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    double Peso, Altura, BMI;
    string nombre;
    char opcion;


    //Obteniendo nombre del usuario
    cout << "Por favor ingresar su nombre: ";
    getline(cin, nombre);


    //Dar bienvenida al usuario
    cout << "Bienvenido " << nombre << ", a continuacion se le pedira ingresar una opcion para luego determinar el BMI en libras o en kilogramos" << endl;


    //Obtener opcion elegida
    cout << "Ingrese si desea calcular su BMI en libras escriba (L) o si desea calcular el BMI en kilogramos escriba (K): ";
    cin >> opcion;


    //Inicio del ciclo if para saber la opcion elegida por el usuario
    if (opcion == 'L' || opcion == 'l'){

        //Pidiendo datos del usuario
        cout << "Ingrese su peso en libras: ";
        cin >> Peso;

        cout << "Ingrese su altura en pulgadas: ";
        cin >> Altura;

        //BMI en libras
        BMI = (Peso * 703) / (Altura * Altura);


    } else if (opcion == 'K' || opcion == 'k') {
        cout << "Ingrese su peso en kilogramos: ";
        cin >> Peso;

        cout << "Ingrese su altura en metros:  ";
        cin >> Altura;

        //BMI en kilogramos
        BMI = (Peso) / (Altura * Altura);

    } else {
       cout << "ERROR. Ingresar una opcion valida";
    }


    //Dar el BMI
    cout << "Su BMI es: " << fixed << setprecision(1) << BMI << endl;

    if (BMI < 18.5) {
        cout << "Su categoria de BMI es Bajo peso" << endl;


    } else if (BMI >= 18.5 && BMI <= 24.9) {
        cout << "Su categoria de BMI es Normal" << endl;


    } else if (BMI >= 25 && BMI <= 29.9) {
        cout << "Su categoria de BMI es Sobrepeso" << endl;


    } else {
        cout << "Obeso" << endl;
    }
    return 0;
}
