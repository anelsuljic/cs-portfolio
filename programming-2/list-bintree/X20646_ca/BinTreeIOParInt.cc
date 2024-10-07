#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a)
{
    ParInt dada;

    if (dada.llegir()) {
        BinTree<ParInt> left;
        read_bintree_parint(left);
        BinTree<ParInt> right;
        read_bintree_parint(right);

        a = BinTree<ParInt>(dada, left, right);
    }
}

void write_bintree_parint(const BinTree<ParInt>& a)
{
    if (not a.empty()) {
        ParInt arrel = a.value();
        write_bintree_parint(a.left());
        arrel.escriure();
        write_bintree_parint(a.right());    
    }
}