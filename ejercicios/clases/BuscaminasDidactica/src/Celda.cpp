#include "Celda.h"
#include <iostream>
//bibliotecas estandar para el programa
using namespace std;

Celda::Celda()//constructor que no hace nada
{
}
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)//constructor qu inicia las coordenadas y el estado de la mina con los valores y pone minadescubierto como falso
{
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;
    this->minaDescubierta = false;
}
int Celda::setCoordenadaX(int coordenadaX)//establece la coordenada x
{
    this->coordenadaX = coordenadaX;
}
int Celda::getCoordenadaX()//obtiene la coordenada x
{
    return this->coordenadaX;
}
int Celda::setCoordenadaY(int coordenadaY)//establece la coordenada y
{
    this->coordenadaY = coordenadaY;
}
int Celda::getCoordenadaY()//obtiene la coordenada y
{
    return this->coordenadaY;
}
bool Celda::setMina(bool estadoMina)//con una condicion establece que si ya hay una mina no puede poner otra
{
    if (this->getMina())
    {
        return false;
    }
    else{
        this->mina = estadoMina;
        return true;
    }
}
bool Celda::getMina()//obtiene el estado de la mina
{
    return this->mina;
}
bool Celda::setMinaDescubierta(bool minaDescubierta)//dice si la mina esta descubierta o no
{
    this->minaDescubierta = minaDescubierta;
}
bool Celda::getMinaDescubierta()//obtiene si la mina esta descubierta o no
{
    return this->minaDescubierta;
}
void Celda::imprimirCelda()//imprime las coordenadas de la celda y si tiene mina
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}


