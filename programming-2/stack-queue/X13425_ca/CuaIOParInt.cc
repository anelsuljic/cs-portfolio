#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c)
{
    ParInt elem;
    while (elem.llegir()) {
        c.push(elem);
    }
}

void escriureCuaParInt(queue<ParInt> c)
{
    int mida = c.size();
    for (int i = 0; i < mida; ++i) {
        c.front().escriure();
        c.pop();
    }
}