#include <iostream>
#include <list>

using namespace std;

typedef pair<int, int> Parells;

bool es_invalidat(list<int> &llista, const int &num)
// Pre: cert
// Post: si "llista" conte com a minim un element igual a "num", aquest queda 
// eliminat i el resultat es cert. Altrament, el resultat es fals.
{
    bool trobat = false;
    list<int>::iterator it = llista.begin();
    list<int>::const_iterator end = llista.end();

    while (not trobat and it != end) {
        if (*it == num) {
            trobat = true;
            it = llista.erase(it);
        } else ++it;
    }

    return trobat;
}

void actualitzar_estadistiques(int num, int &min, int &max)
// Pre: cert
// Post: min i max contenen el valor de num si aquest es mes petit o mes gran 
// que min i max, respectivament
{
    if (min == -1 and max == -1) min = max = num;
    else if (num < min) min = num;
    else if (num > max) max = num;
}

void recalc_min_max(const list<int> &llista, int &min, int &max)
// Pre: cert
// Post: el resultat es el minim i maxim de "llista"
{
    min = max = -1;

    list<int>::const_iterator it = llista.begin();
    list<int>::const_iterator end = llista.end();

    while (it != end) {
        int num = *it;
        if (max == -1 and min == -1) max = min = num;
        else if (num > max) max = num;
        else if (num < min) min = num;

        ++it;
    }
}
 
int main()
// El programa calcula les estadistiques d'una sequencia de parells d'enters, 
// composada per <codi, nombre>, on, per a cada parell processat, s'ha 
// d'escriure el minim, el maxim i la mitjana de la llista, respectivament. 
// Si el codi es -1, el "nombre" passa a ser vàlid (s'insereix a la llista); si 
// es -2, el "nombre" passa a ser invàlid (s'esborra de la llista, si existeix)
// Entrada: una sequencia de parells <codi, nombre>, acabada en 0 0
// Sortida: el minim, maxim i mitjana dels elements de la llista. Si no n'hi ha 
// cap, s'escriu 0
{
    list<int> llista;
    
    Parells p;
    cin >> p.first >> p.second;

    int min = -1;
    int max = -1;
    double sum = 0;
    while (p.first != 0 and p.second != 0) {
        if (p.first == -1) {
            llista.insert(llista.end(), p.second);
            actualitzar_estadistiques(p.second, min, max);
            sum += p.second;
        } else if (p.first == -2 and es_invalidat(llista, p.second)) {
            if (p.second == min or p.second == max) {
                recalc_min_max(llista, min, max);
            }
            sum -= p.second;
        }
        if (not llista.empty()) {
            cout << min << ' ' << max << ' ' << sum / llista.size() << endl;
        } else cout << 0 << endl;

        cin >> p.first >> p.second;
    }
}