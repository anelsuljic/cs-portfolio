#include "LlistaIOParInt.hh"

void calcula_aparicions(const int &num, const list<ParInt> &llista, 
                        int &aparicions, int &suma)
// Pre: cert
// Post: "aparicions" conté el nombre d'aparicions de num com a primer element
// dels parells de "llista" i "suma" conté la suma dels seus companys
{
    suma = aparicions = 0;
    
    list<ParInt>::const_iterator it;
    list<ParInt>::const_iterator end = llista.end();
    for (it = llista.begin(); it != end; ++it) {
        if (num == it->primer()) {
            ++aparicions;
            suma += it->segon();
        }
    }
}

int main()
// El programa calcula el nombre d'aparicions d'un nombre n com a primer
// element dels parells d'una llista de parells d'enters i la suma dels
// seus companys
// Entrada: una sequencia de parells d'enters, acabada en 0 0; i un
// nombre enter, n
// Sortida: escriu el nombre n, seguit de les seves aparicions i la suma dels
// seus companys
{
    list<ParInt> llista;
    LlegirLlistaParInt(llista);
    int num;
    cin >> num;

    int aparicions, suma;
    calcula_aparicions(num, llista, aparicions, suma);

    cout << num << ' ' << aparicions << ' ' << suma << endl;
}