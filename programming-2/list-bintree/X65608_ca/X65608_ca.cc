
#include "BinTreeIOEst.hh"


void cerca(const int &dni, const BinTree<Estudiant> &arbre, bool &trobat,
           int &profunditat, double &nota)
// Pre: dni > 0; trobat = false;
// Post: trobat es cert si "dni" es igual a un dels dni's dels estudiants 
// d'"arbre". Altrament, es fals. Si trobat es cert, s'escriu al canal de 
// sortida el dni de l'estudiant, seguit de la profunditat on es troba, i 
// la seva nota. Si no te nota, el camp es igual a -1
{
    if (not arbre.empty()) {
        Estudiant arrel = arbre.value();

        if (dni == arrel.consultar_DNI()) {
            trobat = true;
            if (arrel.te_nota()) nota = arrel.consultar_nota();
            else nota = -1;
        } else {
            bool trobat_left = false;
            int prof_left = profunditat + 1;
            double nota_left;
            cerca(dni, arbre.left(), trobat_left, prof_left, nota_left);
            bool trobat_right = false;
            int prof_right = profunditat + 1;
            double nota_right;
            cerca(dni, arbre.right(), trobat_right, prof_right, nota_right);

            if (trobat_left and trobat_right) {
                trobat = true;
                if (prof_left <= prof_right) {
                    profunditat = prof_left;
                    nota = nota_left;
                } else {
                    profunditat = prof_right;
                    nota = nota_right;
                }
            } else if (trobat_left) {
                trobat = true;
                profunditat = prof_left;
                nota = nota_left;
            } else if (trobat_right) {
                trobat = true;
                profunditat = prof_right;
                nota = nota_right;
            }
        }
    }
}

int main()
// El programa realitza una cerca d'estudiants en un arbre d'estudiants
// Entrada: un arbre d'estudiants en preordre, seguit d'una sequencia de
// dni's
// Sortida: si l'estudiant forma part de l'arbre hi ha dues possibles sortides:
// <dni profunditat nota> si l'estudiant te nota o <dni profunditat -1> si
// l'estudiant no te nota. Si l'estudiant no forma part de l'arbre, la sortida
// es <dni -1>
{
    BinTree<Estudiant> arbre;
    read_bintree_est(arbre);

    int dni;
    while (cin >> dni) {
        bool trobat = false;
        int profunditat = 0;
        double nota;
        cerca(dni, arbre, trobat, profunditat, nota);
        if (trobat) {
            cout << dni << ' ' << profunditat << ' ' << nota << endl;
        }
        else cout << dni << ' ' << -1 << endl;
    }
}
