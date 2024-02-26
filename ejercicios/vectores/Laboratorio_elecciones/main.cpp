//Libreria que se utilizan en esta codigo ( con libreria de limits para establecer el timite de rondas y candidatos
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
//Definicion de constantes utilizadas para el numero maximo y minimo
#define NUM_CANDIDATOS 5
#define NUM_AFILIADOS 50
#define NUM_RONDAS 5
//Las funciones mediantes las cuales se van a encargar de imprimir en la consola la salidas que necesito  con los respectivos calculos porsentuales a las votaciones
void imprimirEncabezadoRecuadro(string titulo);
void imprimirSeparadorRecuadro();
void imprimirRecuadro(string contenido);
void ingresarNombresCandidatos(string nombres[NUM_CANDIDATOS]);
void realizarVotacion(int votos[NUM_CANDIDATOS][NUM_RONDAS], string nombres[NUM_CANDIDATOS]);
void imprimirResultados(int votos[NUM_CANDIDATOS][NUM_RONDAS], string nombres[NUM_CANDIDATOS]);
void calcularResultados(int votos[NUM_CANDIDATOS][NUM_RONDAS], string nombres[NUM_CANDIDATOS]);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    string nombresCandidatos[NUM_CANDIDATOS];
    int votosCandidatos[NUM_CANDIDATOS][NUM_RONDAS];

    char decisionUsuario;
//ciclo do while para poder establecer lo que necesito que imprima dentro de la matriz, para mediante la consola se ingresa el nombre de los candidatos
    do
    {
        ingresarNombresCandidatos(nombresCandidatos);
        realizarVotacion(votosCandidatos, nombresCandidatos);

        imprimirRecuadro("Resultados de las votaciones");
        imprimirResultados(votosCandidatos, nombresCandidatos);
        calcularResultados(votosCandidatos, nombresCandidatos);

        cout << "¿Desea calcular otra elección? (s/n): ";
        cin >> decisionUsuario;

    } while (decisionUsuario == 's' || decisionUsuario == 'S');

    return 0;
}
//Las funcionalidades de cada uno de los void para la impresion de los datos el encabezado base
//Imprime el encabezado para el indice
void imprimirEncabezadoRecuadro(string titulo)
{
    int longitud = titulo.length() + 4;
    cout << "+" << setfill('-') << setw(longitud) << "+" << endl;
    cout << "| " << setw(longitud - 2) << titulo << " |" << endl;
    cout << "+" << setfill('-') << setw(longitud) << "+" << setfill(' ') << endl;
}
//Separadores de los recuadros para poder establecer en el recuadro del indice
void imprimirSeparadorRecuadro()
{
    cout << "+" << setfill('-') << setw(15) << "+" << setw(10) << setfill('-') << "+" << setw(10) << setfill('-') << "+" << setw(10) << setfill('-') << "+" << setw(10) << setfill('-') << "+" << setw(10) << setfill('-') << "+" << setfill(' ') << endl;
}
//Para el formato de recuadro para su uso y especificacion de cada dato dado
void imprimirRecuadro(string contenido)
{
    int longitud = contenido.length() + 4;
    cout << "+" << setfill('-') << setw(longitud) << "+" << endl;
    cout << "| " << setw(longitud - 2) << contenido << " |" << endl;
    cout << "+" << setfill('-') << setw(longitud) << "+" << setfill(' ') << endl;
}
//Pedir al usuario los cadidatos y su imprecion
void ingresarNombresCandidatos(string nombres[NUM_CANDIDATOS])
{
    imprimirEncabezadoRecuadro("CANDIDATOS PARTICIPANTES");

    for (int indice = 0; indice < NUM_CANDIDATOS; ++indice)
    {
        cout << "Candidato " << indice + 1 << ": ";
        cin >> nombres[indice];
    }
}
//La realizacion de las votaciones base-la ronda pasada sobre la anterior para hacer el recuento final y establecer dentro de la matriz
void realizarVotacion(int votos[NUM_CANDIDATOS][NUM_RONDAS], string nombres[NUM_CANDIDATOS])
{
    imprimirEncabezadoRecuadro("Realizar Votación");

    for (int ronda = 0; ronda < NUM_RONDAS; ++ronda)
    {
        cout << "\nVotación - Ronda " << ronda + 1 << ":\n";

        for (int candidato = 0; candidato < NUM_CANDIDATOS; ++candidato)
        {
            cout << "Votos De " << nombres[candidato] << " en esta ronda: ";
            cin >> votos[candidato][ronda];
        }
    }
}
//Realizar los resultados de impresion de las rondas que se fueron tomadas
void imprimirResultados(int votos[NUM_CANDIDATOS][NUM_RONDAS], string nombres[NUM_CANDIDATOS])
{
    imprimirEncabezadoRecuadro("Resultado Final de las elecciones");

    cout << "|" << setw(15) << "Candidato" << "|";

    for (int ronda = 0; ronda < NUM_RONDAS; ++ronda)
    {
        cout << setw(10) << "Ronda " << ronda + 1 << "|";
    }

    cout << endl;
    imprimirSeparadorRecuadro();

    for (int candidato = 0; candidato < NUM_CANDIDATOS; ++candidato)
    {
        cout << "|" << setw(15) << nombres[candidato] << "|";

        for (int ronda = 0; ronda < NUM_RONDAS; ++ronda)
        {
            cout << setw(10) << votos[candidato][ronda] << "|";
        }

        cout << endl;
        imprimirSeparadorRecuadro();
    }
}
//Denomina lo cual es el candidato con mayoria de votos y el perdedor
void calcularResultados(int votos[NUM_CANDIDATOS][NUM_RONDAS], string nombres[NUM_CANDIDATOS])
{
    imprimirEncabezadoRecuadro("Calcular Resultados");

    int totalVotos[NUM_CANDIDATOS];

    for (int candidato = 0; candidato < NUM_CANDIDATOS; ++candidato)
    {
        totalVotos[candidato] = 0;
    }

    int menorVotosGlobal = std::numeric_limits<int>::max();
    string candidatoGanador, candidatoMenosVotos;

    for (int ronda = 0; ronda < NUM_RONDAS; ++ronda)
    {
        int menorVotos = std::numeric_limits<int>::max();

        for (int candidato = 0; candidato < NUM_CANDIDATOS; ++candidato)
        {
            totalVotos[candidato] += votos[candidato][ronda];

            if (votos[candidato][ronda] < menorVotos)
            {
                menorVotos = votos[candidato][ronda];
                candidatoMenosVotos = nombres[candidato];
            }

            if (candidato > 0 && totalVotos[candidato] > totalVotos[candidato - 1])
            {
                candidatoGanador = nombres[candidato];
            }
        }

        if (menorVotos < menorVotosGlobal)
        {
            menorVotosGlobal = menorVotos;
        }
    }
//Resultado dado por variables de la tabla con ganador y postulado con menos votos
    cout << "Candidato ganador: " << candidatoGanador << " con un total de votos de " << totalVotos[NUM_CANDIDATOS - 1] << endl;
    cout << "Candidato con menos votos en una ronda: " << candidatoMenosVotos << " con un total de votos de " << menorVotosGlobal << endl;
}
