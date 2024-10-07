#include <iostream>
#include <stack>
#include "BinTree.hh"

using namespace std;

void cami_preferent_i(const BinTree<int> &a, stack<int> &c, int &elems)
/* Pre: c es buida */
/* Post: c es el cami preferent d'a; elems es el nombre d'elements d'a */
{
    if (not a.empty()) {
        if (a.left().empty() and a.right().empty()) {
            c.push(a.value());
            elems = 1;
        } else {
            BinTree<int> left = a.left();
            int num_esq;
            cami_preferent_i(left, c, num_esq);
            /* HI1: c conté el camí preferent de left i num_esq es el nombre 
            d'elements de left */
            BinTree<int> right = a.right();
            stack<int> d;
            int num_dre;
            cami_preferent_i(right, d, num_dre);
            /* HI2: d conté el camí preferent de right i num_dre es el nombre 
            d'elements de right */

            if (num_esq < num_dre) c = d;
            c.push(a.value());
            elems = num_dre + num_esq + 1;
        }
    } else elems = 0;
}

void cami_preferent(const BinTree<int>& a, stack<int>& c)
/* Pre: c es buida */
/* Post: c conte el cami preferent d'a; si no es buit, el primer element
   del cami es al cim de c */
{
    int elems;
    cami_preferent_i(a, c, elems);
}

/*void escriure(stack<int> &c)
{
    while (not c.empty()) {
        cout << ' ' << c.top();
        c.pop();
    }
    cout << endl;
}

void read_bintree_int(BinTree<int> &t, int marca)
{
    int x;
    cin >> x;

    if (x != marca) {
        BinTree<int> l;
        read_bintree_int(l, marca);
        BinTree<int> r;
        read_bintree_int(r, marca);
        t = BinTree<int>(x, l, r);
    }
}*/ 

/* Calcula el camí preferent d'un arbre d'enters */
//int main()
/* Entrada: un BinTree d'enters */
/* Sortida: una pila amb el camí preferent */
/*{
    BinTree<int> T;
    read_bintree_int(T, 0);

    stack<int> c;
    cami_preferent(T, c);

    escriure(c);
}*/