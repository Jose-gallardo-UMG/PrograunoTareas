#ifndef CONFIG_H
#define CONFIG_H
//evita la inclusion multiple

class Config//declaracion de la calse config
{
    public://miembros publicos
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);//constructor con parametros de filas, columnas, minas, vidas del jugador y el modo desarrollador
        //M�todos para obtener y establecer las filas, columnas, minas, modo desarrollador y vidas del tablero.
        int getfilasTablero();
        int setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        int setminasTablero(int minasTablero);
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);
        //M�todo para mostrar un men� de configuraci�n al usuario.
        void menuConfiguracion();
    protected://no  hay nada protegido

    private://miembros privados

        int filasTablero;//Almacena el n�mero de filas del tablero.
        int columnasTablero;//Almacena el n�mero de columnas del tablero.
        int minasTablero;//Almacena el n�mero de minas en el tablero.
        bool modoDesarrolladorTablero;// Indica si el modo desarrollador est� activado o desactivado.
        int vidasTablero;// Almacena el n�mero de vidas del jugador.
};

#endif // CONFIG_H
