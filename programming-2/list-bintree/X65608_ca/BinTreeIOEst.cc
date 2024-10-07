#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a)
{
    Estudiant est;
    est.llegir();

    if (est.consultar_DNI() != 0 or est.consultar_nota()) {
        BinTree<Estudiant> left;
        read_bintree_est(left);
        BinTree<Estudiant> right;
        read_bintree_est(right);

        a = BinTree<Estudiant>(est, left, right);
    }
}

void write_bintree_est(const BinTree<Estudiant>& a)
{
    if (not a.empty()) {
        write_bintree_est(a.left());
        a.value().escriure();
        write_bintree_est(a.right());
    }
}