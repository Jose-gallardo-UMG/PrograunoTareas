#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

// Constructor que inicializa los valores de la configuración del juego con los parámetros proporcionados.
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}
void Config::menuConfiguracion()//metodo menu configuracion
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        //Muestra un menú de configuración que permite al usuario ver y cambiar los valores del juego.
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        //En cada iteración, muestra la configuración actual y permite al usuario seleccionar una opción para cambiarla./
        if (opciones!=6)
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }

        //Después de cada cambio, imprime un mensaje indicando que el valor ha sido actualizado.
        switch (opciones)
        {
        case 1:
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5:
            {
                this->setvidasTablero(valorIngresado);
                cout << "Vidas del Juego actualizadas" << endl;
                break;
            }
        case 6: repetir = false;
                break;
        }
        system("pause");
    } while (repetir);
}//El bucle continúa hasta que el usuario elija la opción para regresar al menú principal.

//Métodos para obtener y establecer os valores de las filas, columnas, minas, modo desarrollador y vidas del tablero.
//Los métodos "set" modifican los valores de los miembros de la clase según el valor proporcionado.
int Config::getfilasTablero()
{
    return this->filasTablero;
}

int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero;
}

int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}

int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero;
}

int Config::getminasTablero()
{
    return this->minasTablero;
}

int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero;
}

bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero;
}

bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero;
}

int Config::getvidasTablero()
{
    return this->vidasTablero;
}

int Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero=vidasTablero;
}


