#include <iostream>

using namespace std;

int main()
{
    float x;
    float y;

    cout << "\n" << endl;
    cout << "  Comprobador del numero mas grande " << endl;
    cout << "\n" << endl;
    cout << "Escriba un numero: " << endl;
    cin >> x;
    cout << "Escriba otro numero: " << endl;
    cin >> y;

    if (x>y)
    {cout << "  El numero " << x << " es el numero mayor" << endl;}
    else if (y>x)
    {cout << "  El numero " << y << " es el numero mayor" << endl;}
    else
    {cout << "  Los numeros ingresados son los mismos" << endl;}

    return 0;
}
