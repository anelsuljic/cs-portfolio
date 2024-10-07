//#include "BinTreeIOParInt.hh"
#include "BinTree.hh"
#include "ParInt.hh"

void sumak(BinTree<ParInt>& a, int k)
/* Pre: a = A */
/* Post: a es com a A amb k sumat al segon component de cada node */
{
    if (not a.empty()) {
        BinTree<ParInt> left = a.left();
        sumak(left, k);
        BinTree<ParInt> right = a.right();
        sumak(right, k);

        int elem = a.value().segon() + k;
        ParInt arrel(a.value().primer(), elem);
        a = BinTree<ParInt>(arrel, left, right);
    }
}

/*int main()
{
    BinTree<ParInt> arbre;
    read_bintree_parint(arbre);

    int num;
    cin >> num;
    
    sumak(arbre, num);
    
    write_bintree_parint(arbre);
} */