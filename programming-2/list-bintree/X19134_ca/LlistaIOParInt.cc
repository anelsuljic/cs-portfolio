#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l)
{
    ParInt p;
    list<ParInt>::const_iterator end = l.end();
    while (p.llegir()) {
        l.insert(end, p);
    }
}

void EscriureLlistaParInt(const list<ParInt>& l)
{
    list<ParInt>::const_iterator it;
    list<ParInt>::const_iterator end = l.end();
    for (it = l.begin(); it != end; ++it) {
        it->escriure();
    }
}