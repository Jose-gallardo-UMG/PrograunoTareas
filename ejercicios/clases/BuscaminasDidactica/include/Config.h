#ifndef CONFIG_H
#define CONFIG_H
//evita la inclusion multiple

class Config//declaracion de la calse config
{
    public://miembros publicos
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);//constructor con parametros de filas, columnas, minas, vidas del jugador y el modo desarrollador
        //Métodos para obtener y establecer las filas, columnas, minas, modo desarrollador y vidas del tablero.
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
        //Método para mostrar un menú de configuración al usuario.
        void menuConfiguracion();
    protected://no  hay nada protegido

    private://miembros privados

        int filasTablero;//Almacena el número de filas del tablero.
        int columnasTablero;//Almacena el número de columnas del tablero.
        int minasTablero;//Almacena el número de minas en el tablero.
        bool modoDesarrolladorTablero;// Indica si el modo desarrollador está activado o desactivado.
        int vidasTablero;// Almacena el número de vidas del jugador.
};

#endif // CONFIG_H
