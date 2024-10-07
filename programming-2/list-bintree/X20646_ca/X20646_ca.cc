#include "BinTreeIOParInt.hh"

void cerca(const int &elem, const BinTree<ParInt> &arbre, bool &trobat, 
           int profunditat)
// Pre: cert
// Post: si elem forma part d'arbre, s'escriu al canal de sortida el parell
// complet, seguit de la seva profunditat. En cas contrari s'escriu -1
{
    if (not arbre.empty()) {
        ParInt arrel = arbre.value();
        if (elem == arrel.primer()) {
            trobat = true;
            cout << elem << ' ' << arrel.segon() << ' ' << profunditat << endl;
        } else {
            cerca(elem, arbre.left(), trobat, profunditat + 1);
            if (not trobat) cerca(elem, arbre.right(), trobat, profunditat + 1);
        }
    }
}

int main()
// El programa realitza una cerca de nombres enters en un arbre de parells
// d'enters
// Entrada: un arbre binari de parells en preordre, sense repeticions 
// respecte al primer element de cada parell, i una seqüència d’enters per 
// cercar
// Sortida: per a cada enter, la sortida és -1 si l’enter no és a la primera 
// posició d’un parell a l’arbre, altrament, cal treure l’element, el seu 
// company i la profunditat en què es troba
{
    BinTree<ParInt> arbre;
    read_bintree_parint(arbre);

    int elem;
    while (cin >> elem) {
        bool trobat = false;
        cerca(elem, arbre, trobat, 0);
        if (not trobat) cout << -1 << endl;
    }
}