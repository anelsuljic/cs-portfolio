#include <iostream>
#include <list>
#include "eda-util.hh"

#include "list-sort.hh"
using std::cout;
using std::endl;
using std::list;


typedef list<nat>::const_iterator list_itc;


// Rellena una lista con elementos aleatorios.
template <typename elem>
void generar_lista(list<elem>& lst, nat tam_lst) {
    for (nat i = 0; i < tam_lst; ++i) {
        // Inv: 'lst' contiene i-1 elementos de tipo 'elem' cuyo valor es 
        //      aleatorio.

        lst.insert(lst.end(), util::valor_aleatorio<elem>(0, tam_lst));
    }
}


int main() {
    nat tam_list = 1000;
    list<nat> lst;
    generar_lista<nat>(lst, tam_list);

    cout << "Sin ordenar:" << endl;
    list_itc it1 = lst.begin();
    bool ordenada = true;
    for (list_itc it2 = ++lst.begin(); it2 != lst.end(); ++it2) {
        // Inv: se han impreso los elementos de [lst.begin(), it2) y se ha 
        //      comprobado si [lst.begin(), it2) está ordenada crecientemente.
        
        if (it2 == ++lst.begin()) cout << *it1;
        cout << ' ' << *it2;

        if (*it2 < *it1) ordenada = false;
    }
    cout << endl;
    if (ordenada) cout << "\nORDENADA :)\n\n" << endl;
    else cout << "\nNO ORDENADA :(\n\n" << endl;


    list_sort::sort(lst);


    cout << "Ordenada:" << endl;
    it1 = lst.begin();
    ordenada = true;
    for (list_itc it2 = ++lst.begin(); it2 != lst.end(); ++it2) {
        // Inv: se han impreso los elementos de [lst.begin(), it2) y se ha 
        //      comprobado si [lst.begin(), it2) está ordenada crecientemente.
        
        if (it2 == ++lst.begin()) cout << *it1;
        cout << ' ' << *it2;

        if (*it2 < *it1) ordenada = false;
    }
    cout << endl;
    if (ordenada) cout << "\nORDENADA :)" << endl;
    else cout << "\nNO ORDENADA :(" << endl;
}