#include <iostream>
#include "BinTree.hh"
//#include "BinTreeIOint.hh"

using namespace std;

void arbre_graus_desequilibri_i(const BinTree<int> &a, BinTree<int> &agd, 
                                int &alcaria)
// Pre: a = A;
// Post: cada node d'agd es igual a l'açaria del seu respectiu subarbre 
// esquerre menys l'alçaria del seu respectiu subarbre dret; alcaria es igual a 
// l'alçaria de a
{
    if (a.empty()) alcaria = 0;
    else if (a.left().empty() and a.right().empty()) {
        agd = BinTree<int>(0);
        alcaria = 1;
    }
    else {
        BinTree<int> left = a.left();
        BinTree<int> agd_left;
        int alc_left;
        arbre_graus_desequilibri_i(left, agd_left, alc_left);
        // HI1: els nodes d'agd_left son graus de desequilibri 
        BinTree<int> right = a.right();
        BinTree<int> agd_right;
        int alc_right;
        arbre_graus_desequilibri_i(right, agd_right, alc_right);
        // HI2: els nodes d'agd right son graus de desequilibri

        agd = BinTree<int>(alc_left - alc_right, agd_left, agd_right);
        if (alc_left > alc_right) alcaria = alc_left + 1;
        else alcaria = alc_right + 1;
    }    
}

void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd)
// Pre: a=A 
// Post: agd es un arbre amb la mateixa estructura que A on cada
// node conte el grau de desequilibri del subarbre d'A corresponent
{
    int alcaria;
    arbre_graus_desequilibri_i(a, agd, alcaria);
}

/*
// Converteix un BinTree d'enters a un BinTree de graus de desequilibri. El 
// grau de desequilibri d'un node es la diferència entre l'alçaria del seu fill 
// esquerre menys l'alçaria del seu fill dret.
int main()
// Entrada: un BinTree d'enters
// Sortida: un BinTree de graus de desequilibri amb l'estructura del BinTree de 
// l'entrada
{
    BinTree<int> T;
    read_bintree_int(T, 0);
    BinTree<int> agd;
    arbre_graus_desequilibri(T, agd);

    write_bintree_int(agd);
    cout << endl;
}*/