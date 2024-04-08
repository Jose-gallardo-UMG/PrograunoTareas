#ifndef TABLERO_H
#define TABLERO_H//incluye el archivo encabezado TABLERO_H
#include <iostream>
#include <vector>//libreria para usar vectores
#include "Celda.h"//incluye la clase celda

using namespace std;


class Tablero//declarar la clase Tablero
{
    public://miembros publicos
        Tablero();//constructor que no hace nada
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);//constructor con los parametros de altura, ancho y el modo desarrollador
        int getAlturaTablero();//obtiene la altura el tablero
        int setAlturaTablero(int alturaTablero);//establece la altura del tablero
        int getAnchoTablero();//obtiene el ancho del tablero
        int setAnchoTablero(int anchoTablero);//establece el ancho del tablero
        //metodo para imprimir el tablero y sus elementos
        bool getModoDesarrollador();
        bool setModoDesarrollador(bool modoDesarrollador);
        void imprimirSeparadorEncabezado();
        void imprimirSeparadorFilas();
        void imprimirEncabezado();
        void imprimir();
        //metodos para colocar minas y descrubir celdas sin minas y sin descubrir
        bool colocarMina(int x, int y);
        bool descubrirMina(int x, int y);
        int contarCeldasSinMinasYSinDescubrir();

    protected://no hay nada protegido

    private://miembros protegidos
        int alturaTablero, anchoTablero;//declara variables de la altura y anchura del tablero
        bool modoDesarrollador;//Indica si el modo desarrollador está activado o desactivado.
        vector<vector<Celda> > contenidoTablero;

        string getRepresentacionMina(int x, int y);//Almacena el contenido del tablero como una matriz de celdas.
        int minasCercanas(int fila, int columna);
};

#endif // TABLERO_H
