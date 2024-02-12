#include <iostream>

using namespace std;

int main()
{
    int x;

    cout << "\n" << endl;
    cout << "  Comprobador de un numero par o impar" << endl;
    cout << "\n" << endl;
    cout << "Escriba un numero: " << endl;
    cin >> x;
    cout << "\n" << endl;

    if ((x%2) == 0)
    {cout << "  El numero " << x << " es un numero par" << endl;}
    else if(x%2 ==! 0)
    {cout << "  El numero " << x << " es un numero impar" << endl;}

    return 0;
}
