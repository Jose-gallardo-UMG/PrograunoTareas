//#include <iostream>

//using namespace std;

//int main()
//{
   //unsigned int aprobados = 0;
   //unsigned int reprobados = 0;
   //unsigned int contadorEsudiantes = 1;

   //while (contadorEsudiantes <= 10){
       //cout<<"Escriba el resultado (1 = aprobado , 2 = reprobado): ";
       //int resultado = 0;
       //cin >>resultado;

       //if (resultado== 1)
           //aprobados = aprobados +1;
       //else
            //reprobados  = reprobados +1;

       //contadorEsudiantes = contadorEsudiantes  + 1;
//}
       //cout<< "aprobados"<<aprobados<<"\nReprobados "<< reprobados<<endl;
       //if(aprobados > 8)
       //cout<<"bono para el instructor"<<endl;
//}


#include <iostream>

using namespace std;

int main() {
    unsigned int aprobados = 0;
    unsigned int reprobados = 0;
    unsigned int contadorEstudiantes = 1;

    while (contadorEstudiantes <= 10) {
        int resultado;
        do {
            cout << "Escriba el resultado (1 = aprobado, 2 = reprobado): ";
            cin >> resultado;

            // Validar si el resultado ingresado es 1 o 2
            if (resultado != 1 && resultado != 2) {
                cout << "¡Valor incorrecto! Por favor, ingrese 1 o 2." << endl;
            }
        } while (resultado != 1 && resultado != 2); // Continuar solicitando entrada hasta que se ingrese 1 o 2

        // Actualizar los contadores de aprobados y reprobados
        if (resultado == 1) {
            aprobados++;
        } else {
            reprobados++;
        }

        contadorEstudiantes++;
    }

    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;

    if (aprobados > 8) {
        cout << "Bono para el instructor" << endl;
    }

    return 0;
}

