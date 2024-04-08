#ifndef CELDA_H
#define CELDA_H
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//Fecha: 17 marzo 2023

class Celda//crea la clase celda que es para las celdas del juego
{
    public://declaracion de los miembros publicos las celdas, contiene un constructor con los parametros para las coordenadas y el estado de mina de la celda
        Celda();
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();
        bool setMina(bool estadoMina);//usando metodo establece el estado de la mina
        bool getMina();//usando metodo obtener el estado de la mina
        bool setMinaDescubierta(bool minaDescubierta);//usando metodo establece el estado de la mina
        bool getMinaDescubierta();//usando metodo obtiene el estado de la mina
        void imprimirCelda();//metodo que se usa para imprimir la celda
    protected:

    private://metodos privados
        int coordenadaX, coordenadaY;
        bool mina, minaDescubierta;
};

#endif // CELDA_H
