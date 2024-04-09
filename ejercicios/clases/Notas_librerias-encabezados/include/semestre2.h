#ifndef SEMESTRE2_H
#define SEMESTRE2_H
#include <iomanip>
#include <iostream>

using namespace std;

class semestre2
{
    public:
        semestre2();
        semestre2(string nombre1, string nombre2, string nombre3, string nombre4, string nombre5);
        void datos();

    protected:

    private:

        string nombre1, nombre2, nombre3, nombre4, nombre5;
        int nota1, nota2, nota3, i, j, matriz[5][4], totala = 0, totalb = 0, totalc = 0, totald = 0, totale = 0;

    void generaDatos()
    {

        for ( i=0 ; i<5 ; i++ )
        {
            matriz[i][0] = rand() % 20;
            matriz[i][3] = rand() % 20;
        }

        for ( i=0 ; i<5 ; i++ )
        {
            matriz[i][1] = rand() % 25;
        }

        for ( i=0 ; i<5 ; i++ )
        {
            matriz[i][2] = rand() % 25;
        }

        cout << "+--------+--------+--------+--------+--------+" << endl;
        cout << "| " << "Nombres" << setw(7) << "P.P" << setw(9) << "S.P" << setw(9) << "E.F" << setw(7) << "A" << "    |" << endl;
        cout << "+--------+--------+--------+--------+--------+" << endl;
        cout << "|" << setw(8) << nombre1 << "|" << setw(8) << matriz[0][0] << "|" << setw(8) << matriz[0][1] << "|" << setw(8) << matriz[0][2] << "|" << setw(8) << matriz[0][3] << "|" << endl;
        cout << "|" << setw(8) << nombre2 << "|" << setw(8) << matriz[1][0] << "|" << setw(8) << matriz[1][1] << "|" << setw(8) << matriz[1][2] << "|" << setw(8) << matriz[1][3] << "|" << endl;
        cout << "|" << setw(8) << nombre3 << "|" << setw(8) << matriz[2][0] << "|" << setw(8) << matriz[2][1] << "|" << setw(8) << matriz[2][2] << "|" << setw(8) << matriz[2][3] << "|" << endl;
        cout << "|" << setw(8) << nombre4 << "|" << setw(8) << matriz[3][0] << "|" << setw(8) << matriz[3][1] << "|" << setw(8) << matriz[3][2] << "|" << setw(8) << matriz[3][3] << "|" << endl;
        cout << "|" << setw(8) << nombre5 << "|" << setw(8) << matriz[4][0] << "|" << setw(8) << matriz[4][1] << "|" << setw(8) << matriz[4][2] << "|" << setw(8) << matriz[4][3] << "|" << endl;
        cout << "+--------+--------+--------+--------+--------+" << endl;

        totala = totala + matriz[0][0] + matriz[0][1] + matriz[0][2] + matriz[0][3];
        totalb = totalb + matriz[1][0] + matriz[1][1] + matriz[1][2] + matriz[1][3];
        totalc = totalc + matriz[2][0] + matriz[2][1] + matriz[2][2] + matriz[2][3];
        totald = totald + matriz[3][0] + matriz[3][1] + matriz[3][2] + matriz[3][3];
        totale = totale + matriz[4][0] + matriz[4][1] + matriz[4][2] + matriz[4][3];

        cout << "\n";
        if ( (totala>totalb) && (totala>totalc) && (totala>totald) && (totala>totale) )
        {
            cout << " El alumno " << nombre1 << " tubo la mayor nota con: " << totala << " puntos." << endl;
        }
        else if ( (totalb>totala) && (totalb>totalc) && (totalb>totald) && (totalb>totale) )
        {
            cout << " El alumno " << nombre2 << " tubo la mayor nota con: " << totalb << " puntos." <<  endl;
        }
        else if ( (totalc>totala) && (totalc>totalb) && (totalc>totald) && (totalc>totale) )
        {
            cout << " El alumno " << nombre3 << " tubo la mayor nota con: " << totalc << " puntos." << endl;
        }
        else if ( (totald>totala) && (totald>totalb) && (totald>totalc) && (totald>totale) )
        {
            cout << " El alumno " << nombre4 << " tubo la mayor nota con: " << totald << " puntos." << endl;
        }
        else if ( (totale>totala) && (totale>totalb) && (totale>totalc) && (totale>totald) )
        {
            cout << " El alumno " << nombre5 << " tubo la mayor nota con: " << totale << " puntos." << endl;
        }

        cout << "\n";
        //Calculo del menor puntaje

            if ( (totala<totalb) && (totala<totalc) && (totala<totald) && (totala<totale) )
        {
            cout << " El alumno " << nombre1 << " tubo la menor nota con: " << totala << " puntos." << endl;
        }
        else if ( (totalb<totala) && (totalb<totalc) && (totalb<totald) && (totalb<totale) )
        {
            cout << " El alumno " << nombre2 << " tubo la menor nota con: " << totalb << " puntos." << endl;
        }
        else if ( (totalc<totala) && (totalc<totalb) && (totalc<totald) && (totalc<totale) )
        {
            cout << " El alumno " << nombre3 << " tubo la menor nota con: " << totalc << " puntos." << endl;
        }
        else if ( (totald<totala) && (totald<totalb) && (totald<totalc) && (totald<totale) )
        {
            cout << " El alumno " << nombre4 << " tubo la menor nota con: " << totald << " puntos." << endl;
        }
        else if ( (totale<totala) && (totale<totalb) && (totale<totalc) && (totale<totald) )
        {
            cout << " El alumno " << nombre5 << " tubo la menor nota con: " << totale << " puntos." << endl;
        }

    }
};

#endif
