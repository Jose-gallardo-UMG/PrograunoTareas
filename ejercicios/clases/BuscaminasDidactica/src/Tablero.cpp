#include "Tablero.h"//inclutye metodos de la clase tablero
#include <sstream>//para manipulación de cadenas.
#include <iostream>

using namespace std;

Tablero::Tablero()//constuctor vacio
{
}
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador)//constructor que inicia con los parametros altura, ancho y el modo desarrolador
{
    //Crea un tablero de celdas con las dimensiones dadas y las inicializa como celdas sin mina.
    this->alturaTablero = alturaTablero;
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;
    int x, y;
    for (y=0; y < this->alturaTablero; y++)
    {
        vector<Celda> fila;
        for (x=0; x < this->anchoTablero; x++)
        {
            fila.push_back((Celda(x, y, false)));
        }
        this->contenidoTablero.push_back(fila);
    }
}
//Métodos get y set para obtener y establecer la altura y el ancho del tablero.
int Tablero::getAlturaTablero()
{
    return this->alturaTablero;
}
int Tablero::setAlturaTablero(int alturaTablero)
{
    this->alturaTablero = alturaTablero;
}
int Tablero::getAnchoTablero()
{
    return this->anchoTablero;
}
int Tablero::setAnchoTablero(int anchoTablero)
{
    this->anchoTablero = anchoTablero;
}
//Métodos get y set para obtener y establecer el modo desarrollador del tablero.
bool Tablero::getModoDesarrollador()
{
    return this->modoDesarrollador;
}
bool Tablero::setModoDesarrollador(bool modoDesarrollador)
{
    this->modoDesarrollador = modoDesarrollador;
}
//Retorna la representación de una celda en función de si contiene una mina, está descubierta o el modo desarrollador está activado.
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)
{
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);
    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        if (celdaTemporal.getMina())
        {
            return "*";
        }
        else
        {
            int cantidadCelda=this->minasCercanas(coordenadaY,coordenadaX);
            string cantidadCeldaString = " ";
            stringstream ss;
            ss << cantidadCelda;
            ss >> cantidadCeldaString;
            return cantidadCeldaString;
        }
    }
    else
    {
        return "?";
        //return ".";
    }
}
//Calcula el número de minas adyacentes a una celda dada.
int Tablero::minasCercanas(int filaTablero, int columnaTablero)
{
        int contadorTablero = 0;
        int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero;
        if (filaTablero <= 0)
		{
			filaInicioTablero = 0;
		}
		else
		{
			filaInicioTablero = filaTablero - 1;
		}

		if (filaTablero + 1 >= this->alturaTablero)
		{
			filaFinTablero = this->alturaTablero - 1;
		}
		else
		{
			filaFinTablero = filaTablero + 1;
		}

		if (columnaTablero <= 0)
		{
			columnaInicioTablero = 0;
		}
		else
		{
			columnaInicioTablero = columnaTablero - 1;
		}
		if (columnaTablero + 1 >= this->anchoTablero)
		{
			columnaFinTablero = this->anchoTablero - 1;
		}
		else
		{
			columnaFinTablero = columnaTablero + 1;
		}
		int m;
		for (m = filaInicioTablero; m <= filaFinTablero; m++)
		{
			int l;
			for (l = columnaInicioTablero; l <= columnaFinTablero; l++)
			{
				if (this->contenidoTablero.at(m).at(l).getMina())
				{
					contadorTablero++;
				}
			}
		}
		return contadorTablero;
}
//Métodos imprimirSeparadorEncabezado, imprimirSeparadorFilas y imprimirEncabezado
//Imprimen los separadores y encabezados para visualizar el tablero de manera ordenada.
void Tablero::imprimirSeparadorEncabezado()
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			cout << "----";
			if (m + 2 == this->anchoTablero)
			{
				cout << "-";
			}
		}
		cout << "\n";
	}

	void Tablero::imprimirSeparadorFilas()
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			if (m <= 1)
			{
				cout << "|---";
			}
			else
			{
				cout << "+---";
			}
			if (m == this->anchoTablero)
			{
				cout << "+";
			}
		}
		cout << "\n";
	}

	void Tablero::imprimirEncabezado()
	{
		this->imprimirSeparadorEncabezado();
		cout << "|   ";
		int l;
		for (l = 0; l < this->anchoTablero; l++)
		{
			cout << "| " << l + 1 << " ";
			if (l + 1 == this->anchoTablero)
			{
				cout << "|";
			}
		}
		cout << "\n";
	}
//Imprime el tablero completo, mostrando el estado de cada celda.
	void Tablero::imprimir()
	{
		this->imprimirEncabezado();
		this->imprimirSeparadorEncabezado();
		int x, y;
		for (y = 0; y < this->alturaTablero; y++)
		{
			cout << "| " << y + 1 << " ";
			for (x = 0; x < this->anchoTablero; x++)
			{
				cout << "| " << this->getRepresentacionMina(x, y) << " ";
				if (x + 1 == this->anchoTablero)
				{
					cout << "|";
				}
			}
			cout << "\n";
			this->imprimirSeparadorFilas();
		}
	}

	//Métodos colocarMina, descubrirMina y contarCeldasSinMinasYSinDescubrir
	//Permiten colocar una mina en una celda específica, descubrir una celda y contar el número de celdas sin minas y sin descubrir en el tablero.
    bool Tablero::colocarMina(int x, int y)
	{
		return this->contenidoTablero.at(y).at(x).setMina(true);
	}
    bool Tablero::descubrirMina(int x, int y)
	{
		this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);
		Celda celda = this->contenidoTablero.at(y).at(x);
		if (celda.getMina())
		{
			return false;
		}
		return true;
	}
	int Tablero::contarCeldasSinMinasYSinDescubrir()
	{
		int x, y, contador = 0;
		for (y = 0; y < this->alturaTablero; y++)
		{
			for (x = 0; x < this->anchoTablero; x++)
			{
				Celda celdaTemporal = this->contenidoTablero.at(y).at(x);
				if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
				{
					contador++;
				}
			}
		}
		return contador;
	}
