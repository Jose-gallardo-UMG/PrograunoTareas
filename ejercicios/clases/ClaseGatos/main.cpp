#include <iostream>

using namespace std;




class Gato {

public:
    string nombre;
    Gato(){
    nombre = "Felix";
    }
    Gato(string pnombre){
    nombre = pnombre;
    }
    void expesion(){
    cout <<nombre<<" dice MEOW."<<endl;

    }


};


int main()
{
    Gato miprimergato;
    cout << "Mi primer Gato se llama: "<< miprimergato.nombre<<endl;
    Gato misegundogato;
    cout << "Mi segundo Gato se llama: "<< misegundogato.nombre<<endl;

    Gato mitercergato("Garfield");
    cout << "Mi tercer Gato se llama: "<< mitercergato.nombre<<endl;
    miprimergato.expesion();
    misegundogato.expesion();
    mitercergato.expesion();
    return 0;

}
