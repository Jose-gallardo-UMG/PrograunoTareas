#include <iostream>

using namespace std;

class persona{

public:
    int edad;
    persona(int pEdad){
        edad = pEdad;
    }

    void pensamiento(){
        cout<<obtenerpensamiento()<<endl;
    }

private:

    int nivelsocial;
    int nivelinteligencia;
    int nivelsuerte;
    string obtenerpensamiento(){

        nivelsocial = 0;
        nivelinteligencia = 10;
        nivelsuerte = 100;

        if (nivelsocial + nivelsuerte > 100){

            return "estoy pensando algo bueno y me causa felicidad";

        }
        else if(nivelsuerte >nivelinteligencia){
            return "tengo mucha suerte";

        }
        else if(edad > 18){

            return "soy adulto";
        }
        else{
            return "no estoy pensando nada";
        }

    }

};
int main()
{
    persona Roberto(19);
    Roberto.pensamiento();
    return 0;
}
