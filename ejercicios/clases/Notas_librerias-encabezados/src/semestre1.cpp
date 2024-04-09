#include "semestre1.h"

semestre1::semestre1()
{

}

semestre1::semestre1(string nombre1, string nombre2, string nombre3, string nombre4, string nombre5)
{
    this -> nombre1=nombre1;
    this -> nombre2=nombre2;
    this -> nombre3=nombre3;
    this -> nombre4=nombre4;
    this -> nombre5=nombre5;
}

void semestre1::datos()
{
    generaDatos();
}
