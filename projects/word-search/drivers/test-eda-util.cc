// Realiza una serie de pruebas para comprobar que las operaciones del modulo
// 'eda-util' funcionan correctamente.



#include <iostream>
#include <string>
#include <list>

#include "eda-util.hh"
using std::cout;
using std::endl;
using std::string;
using std::list;
using namespace util;


int main() {
    nat num_elems;
    cin >> num_elems;

    for (nat i = 0; i < num_elems; ++i) {
        // Inv: 0 <= i <= num_elems; el canal de salida contiene los 
        //      resultados de los 'i-1' elementos ya tratados.

        if (i != 0) cout << string(20, '/') << endl << endl;

        list<int> l1, l2;
        leer_lista<int>(l1);
        leer_lista<int>(l2);
        cout << "Antes:" << endl << endl;
        imprimir_lista<int>(l1);
        cout << string(10, '-') << endl;
        imprimir_lista<int>(l2);
        cout << endl;

        restar_lista<int>(l1, l2);
        // l1 = l1 - l2

        cout << "Despues:" << endl << endl;;
        imprimir_lista<int>(l1);
        cout << string(10, '-') << endl;
        imprimir_lista<int>(l2);
        cout << endl;
    }

    cout << "Comprobando \'min\' y \'valor_aleatorio\'" << endl;
    cout << min<nat>(40, 456) << endl;
    cout << valor_aleatorio<nat>(0, 100) << endl;
}