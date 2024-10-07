#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l)
{
    Estudiant est;
    est.llegir();

    list<Estudiant>::const_iterator end = l.end(); //per no fer mes d'una crida
    while (est.consultar_DNI() != 0) {
        l.insert(end, est);
        est.llegir();
    }
}
void EscriureLlistaEstudiant(const list<Estudiant>& l)
{
    list<Estudiant>::const_iterator it;
    list<Estudiant>::const_iterator end = l.end();

    for (it = l.begin(); it != end; ++it) {
        it->escriure();
    }
}