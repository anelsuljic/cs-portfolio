#include <iostream>
#include <list>

using namespace std;

void seleccio(const list<double>& l, list<double>& sel)
/* Pre: l no es buida, sol es buida */
/* Post: sel es el resultat de treure d'l els elements febles en mitjana */
{
    list<double>::const_iterator it = l.begin();
    sel.insert(sel.end(), *it);
    double suma = *it;
    int n = 1;
    ++it;    
    // Inv: it apunta a qualssevol element de l, excepte el primer, o es igual 
    // a l.end(); suma conté la suma dels elements de l[:it); sel = "elements 
    // de l més grans o iguals a la mitjana dels seus antecessors"; n = "nombre 
    // d'elements de l[:it)"
    while (it != l.end()) {
        if (*it >= suma / n) sel.insert(sel.end(), *it);
        suma += *it;
        ++n;
        ++it;
    }
}

/*void llegir(list<double> &l)
{
    double elem;
    while (cin >> elem) {
        l.insert(l.end(), elem);
    }
}

void escriure(const list<double> &l)
{
    for (list<double>::const_iterator it = l.begin(); it != l.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
} */

/* Obté una llista d'elements no febles en mitjana, a partir d'una altra llista de nombres reals. En element es feble en mitjana si es més petit que la mitjana dels anteriors */
//int main()
/* Entrada: una llista de nombres reals */
/* Sortida: una llista com la de l'entrada pero sense els elements febles */
/*{
    list<double> l;
    llegir(l);
    list<double> sel;
    seleccio(l, sel);
    escriure(sel);
}*/