//#include "listIOint.hh"

//const int MARCA_SEQUENCIA = 1000;

#include <iostream>
#include <list>

using namespace std;

void inter(list<int>& uno, const list<int>& dos )
/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
{
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();

    list<int>::const_iterator uno_end = uno.end();
    list<int>::const_iterator dos_end = dos.end();
    while (it1 != uno_end and it2 != dos_end) {
        if (*it1 < *it2) it1 = uno.erase(it1);
        else if (*it1 > *it2) ++it2;
        else {
            ++it1;
            ++it2;
        }
    }
    while (it1 != uno_end) {
        it1 = uno.erase(it1);
    }    
}

/*int main()
// El programa calcula la interseccion de dos listas de enteros
{
    list<int> uno, dos;
    llegir_llista_int(uno, MARCA_SEQUENCIA);
    llegir_llista_int(dos, MARCA_SEQUENCIA);
    inter(uno, dos);
    escriure_llista_int(uno);
}*/