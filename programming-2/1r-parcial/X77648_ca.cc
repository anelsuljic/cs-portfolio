#include <iostream>
#include "BinTree.hh"
//#include "BinTreeIOint.hh"

using namespace std;

int nodes_no_coincidents(const BinTree<int> &a, const BinTree<int> &b)
/* Pre: cert */
/* Post: el resultat indica el nombre de posicions no coincidents dels nodes 
   d'a i b*/
{
    int res = 0;
    if (not a.empty() and b.empty()) {
        ++res;
        if (not a.left().empty() or not a.right().empty()) ++res;
    } else if (a.empty() and not b.empty()) {
        ++res;
        if (not b.left().empty() or not b.right().empty()) ++res;
    } else if (not a.empty() and not b.empty()) {
        res = nodes_no_coincidents(a.left(), b.left()) + 
              nodes_no_coincidents(a.right(), b.right());
        /* HI1: nodes_no_coincidents(a.left(), b.left()) retorna el nombre de 
           posicions no coincidents dels nodes dels subarbres esquerre d'a i b 
        */
        /* HI2: nodes_no_coincidents(a.right(), b.right()) retorna el nombre de 
           posicions no coincidents dels nodes dels subarbres dret d'a i b */
    }

    return res;
}

bool quasi_coincidents (const BinTree<int> &a, const BinTree<int> &b)
/* Pre: cert */
/* Post: el resultat indica si a i b son quasi coincidents */
{
    return nodes_no_coincidents(a, b) <= 1;
}

/*int main() 
{
    BinTree<int> A, B;
    read_bintree_int(A, 0);
    read_bintree_int(B, 0);

    if (quasi_coincidents(A, B)) cout << "true" << endl;
    else cout << "false" << endl;
}*/