#include "Juego.h"//incluye la clase juego
#include <fstream>//entradas y salidas
#include <unistd.h>//para usar metodo rand

int Juego::aleatorio_en_rango(int minimo, int maximo)// Genera un número aleatorio dentro de un rango dado.
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

	int Juego::filaAleatoria()//Genera una fila aleatoria dentro del tablero.
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	int Juego::columnaAleatoria()//Genera una columna aleatoria dentro del tablero.
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}

	Juego::Juego(Tablero tablero, int cantidadMinas)//Constructor que inicializa el juego con un tablero y una cantidad de minas  y coloca las minas aleatoriamente en el tablero.
	{
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->colocarMinasAleatoriamente();
	}

	void Juego::colocarMinasAleatoriamente()//Coloca las minas aleatoriamente en el tablero hasta alcanzar la cantidad de minas especificada.
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas)
		{
			x = this->columnaAleatoria();
			y = this->filaAleatoria();
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}

	int Juego::solicitarFilaUsuario()//Solicitan al usuario que ingrese la fila y la columna donde desea realizar su jugada.
	{
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;
		return fila - 1;
	}

	int Juego::solicitarColumnaUsuario()
	{
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;
		return columna - 1;
	}

	bool Juego::jugadorGana()//Verifica si el jugador ha ganado el juego, contando las celdas sin minas y sin descubrir.
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Juego::iniciar()//Inicia el juego y continúa hasta que el jugador gane o pierda
	{
		int fila, columna;
		while (true)
		{
			this->tablero.imprimir();
			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
			//En cada iteración, imprime el tablero, solicita la jugada del usuario, y verifica si el jugador ha ganado o perdido.
			if (!respuestaAUsuario)
			{
				cout << "Perdiste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}

			if (this->jugadorGana())
			{
				cout << "Ganaste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
				//Si el jugador gana o pierde, imprime un mensaje correspondiente y muestra el tablero con todas las minas descubiertas.
			}
		}
	}
