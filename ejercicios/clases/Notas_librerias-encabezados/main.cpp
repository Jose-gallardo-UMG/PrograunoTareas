#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "semestre1.h"
#include "semestre2.h"
#include "semestre3.h"

using namespace std;

int main()
{
    string nom1, nom2, nom3, nom4, nom5;
    char continuar;
    srand(getpid());

    do {
        cout << "\n";
        cout << "     Notas de los alumnos de la Universidad Mariano Galvez" << endl;
        cout << "\n";

        cout << "         Ingrese el nombre del alumno No.1: ";
        cin >> nom1;
        cout << "\n";
        cout << "         Ingrese el nombre del alumno No.2: ";
        cin >> nom2;
        cout << "\n";
        cout << "         Ingrese el nombre del alumno No.3: ";
        cin >> nom3;
        cout << "\n";
        cout << "         Ingrese el nombre del alumno No.4: ";
        cin >> nom4;
        cout << "\n";
        cout << "         Ingrese el nombre del alumno No.5: ";
        cin >> nom5;
        cout << "\n";

        system("cls");

        cout << "\n";
        cout << " Notas del primer semestre" << endl;

        semestre1 Nombres1(nom1, nom2, nom3, nom4, nom5);
        Nombres1.datos();
        cout << "\n";

        cout << "\n";
        cout << " Notas del segundo semestre" << endl;

        semestre2 Nombres2(nom1, nom2, nom3, nom4, nom5);
        Nombres2.datos();
        cout << "\n";

        cout << "\n";
        cout << " Notas del tercer semestre" << endl;

        semestre3 Nombres3(nom1, nom2, nom3, nom4, nom5);
        Nombres3.datos();
        cout << "\n";

        cout << "¿Desea continuar? (S/N): ";
        cin >> continuar;
        cout << endl;

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
