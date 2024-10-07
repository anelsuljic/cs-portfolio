#include "solution.hh"

void esborra_tots(list<Estudiant> &t, int x)
{
    list<Estudiant>::iterator it = t.begin();
    list<Estudiant>::const_iterator end = t.end();

    while (it != end) {
        if (x == it->consultar_DNI()) it = t.erase(it);
        else ++it;
    }
}