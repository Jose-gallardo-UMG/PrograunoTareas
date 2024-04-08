#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"
//Se incluyen los archivos encabezados juego y config
using namespace std;

int main()
{
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;
    //se definen las dimensiones del tablero, el numero de minas, el modo desarrollador y las vidas del jugador

    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    //crea un objetvo de la clase config
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());

    srand(getpid());
    int opciones;
    bool repetir = true;
    do//inicia un bucle do-while
    {
        //Muestra un menu donde tiene 3 opciones que son configuracion, inicio y fin del juego
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuaracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        //con un switch case le dice al programa que hacer cuando el usuario eliga cualquiera de las 3 opciones
        switch (opciones)
        {
        case 1://llama al metodo "menuconfiguracion" del objeto "configuracionJuego" y habre el menu para configurar el juego
            {
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 2://crea un nuevo objeto juegotemporal con la configuracion actual o por default si no hicieron cambios e inicia con el metodo iniciar()
            {
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juegoTemporal.iniciar();

                system("pause");
                break;
            }
        case 3: repetir = false;//en caso de elegir la ultima opcion el juego se cierra
                break;
        }
    } while (repetir);//el juego se repetira si el juegador elige una opcion que no sea la 3
    system("cls");
    return 0;
}
