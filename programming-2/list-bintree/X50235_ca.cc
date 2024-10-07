#include "BinTreeIOint.hh"

bool poda_subarbre(BinTree<int> &a, int x)
// Pre: a = A
// Post: el resultat es cert si k forma part d'A. En cas que sigui cert, a es 
// com A, pero sense l'element k i els seu successors. En cas contrari, el 
// resultat es fals i a = A
{
    bool res = false;
    if (not a.empty()) {
        BinTree<int> left = a.left();
        BinTree<int> right = a.right();
        if (a.value() == x) {
            res = true;
            a = BinTree<int>();
        } else if (poda_subarbre(left, x)) {
            res = true;
            a = BinTree<int>(a.value(), left, right);
        } else if (poda_subarbre(right, x)) {
            res = true;
            a = BinTree<int>(a.value(), left, right);
        }
    }

    return res;
}

/*int main()
// Entrada: un arbre binari d’enters a, sense repeticions, i un enter x
// Sortida: un valor booleà que indica si x hi és l’arbre. En cas afirmatiu, 
// s’han eliminat de l’arbre l’element x i tots els successors
{
    BinTree<int> arbre;
    read_bintree_int(arbre, 0);

    int x;
    cin >> x;
    
    if (poda_subarbre(arbre, x)) {
        cout << x << " es a l'arbre" << endl << endl;

        write_bintree_int(arbre);
    } else cout << x << " no es a l'arbre" << endl;
}*/