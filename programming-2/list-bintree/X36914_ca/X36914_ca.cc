#include "LlistaIOEstudiant.hh"

void calcula_aparicions(const int &dni, const list<Estudiant> &llista, 
                        int &aparicions)
// Pre: dni > 0
// Post: "aparicions" conté el nombre d'aparicions de "dni" a "llista"
{
    aparicions = 0;

    list<Estudiant>::const_iterator it = llista.begin();
    list<Estudiant>::const_iterator end = llista.end();
    while (it != end) {
        if (it->consultar_DNI() == dni) ++aparicions;

        ++it;
    }
}

int main()
// El programa calcula el nombre d'aparicions d'un estudiant en una llista 
// d'estudiants
// Entrada: una sequencia d'estudiants <dni, nota>, on dni > 0, acabada en 0 0,
// i un estudiant (nomes el seu dni)
// Sortida: escriu el dni de l'estudiant a cercar, seguit del seu nombre 
// d'aparicions a la llista
{
    list<Estudiant> seq;
    LlegirLlistaEstudiant(seq);
    int dni;
    cin >> dni;

    int aparicions;
    calcula_aparicions(dni, seq, aparicions);

    cout << dni << ' ' << aparicions << endl;
}