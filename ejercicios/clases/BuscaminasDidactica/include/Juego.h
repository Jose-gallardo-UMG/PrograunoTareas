#ifndef JUEGO_H
#define JUEGO_H//incluye el archivo JUEGO_H
#include "Tablero.h"//incluye el archivo encabezado tablero.h

class Juego//crea una clase Juego
{
private://miembros privados
	Tablero tablero;//el tablero del juego
	int cantidadMinas;//almacenamiento de numero de minas

	int aleatorio_en_rango(int minimo, int maximo);//metodo para generar un numero aleatorio de un minimoy  maximo establecido
	int filaAleatoria();//metodo para generar una fila aleatoria
	int columnaAleatoria();//metodo para generar una columna aleatoria
public://miembros publicos
    Juego(Tablero tablero, int cantidadMinas);//constructor que recible el objeto tablero y la cantidad de minas
	void colocarMinasAleatoriamente();//metodo para colocar las minas aleatoriamente
	int solicitarFilaUsuario();//metodo para solicitar la fila
	int solicitarColumnaUsuario();//metodo para solicitar la columna
	bool jugadorGana();//metodo para ver si el jugador ha ganado
	void iniciar();//metodo para iniciar el juego
	void dibujarPortada(string nombreArchivo);//dibuja la portada del juego que tiene la variable nombreArchivo
};

#endif // JUEGO_H
