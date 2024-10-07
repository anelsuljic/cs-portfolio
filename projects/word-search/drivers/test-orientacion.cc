// Realiza una serie de pruebas para comprobar que la clase orientación 
// funciona correctamente.


#include <iostream>
#include <string>

#include "orientacion.hh"
using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {
    // Llamada a 'orientacion(int o = NO_OR)'
    orientacion o;
    cout << o.tostring() << endl;

    // Llamada a 'orientacion(int o)' y 
    // 'orientacion& operator=(const orientacion& orient)'.
    o = orientacion(5);
    cout << o.tostring() << endl;

    // Llamada a 'orientacion(const orientacion& orient)'
    orientacion o1 = o;
    cout << "Valor de o1: " << o1.tostring() << endl;

    // Llamada a 'orientacion(const string& s)'
    string s;
    cin >> s;
    orientacion o2(s);
    cout << "Primer valor de o2: " << o2.tostring() << endl;
    cin >> s;
    o2 = orientacion(s);
    cout << "Segundo valor de o2: " << o2.tostring() << endl;


    // Provando 'operator int()' y 'orientacion& operator++()'.
    cout << "Imprimiendo todos los valores posibles:" << endl;
    for (orientacion x = orientacion::H; x < orientacion::NO_OR; ++x) {
        cout << x.tostring() << endl;
    }
}