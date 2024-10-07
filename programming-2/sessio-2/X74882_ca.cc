#include "Cjt_estudiants.hh"

void actual_conj(Cjt_estudiants &A, const Cjt_estudiants &B)
/* Pre: A i B tenen la mateixa mida; els estudiants d'A son els mateixos que 
   els de B */
/* Post: A conte tots els estudiants originals, pero amb la millor nota dels 
   dos conjunts */
{
    int mida = A.mida();
    for (int pos = 1; pos <= mida; ++pos) {
        Estudiant a = A.consultar_iessim(pos);
        Estudiant b = B.consultar_iessim(pos);

        if (a.te_nota() and b.te_nota()) {
            double nota_b = b.consultar_nota();
            if (nota_b > a.consultar_nota()) a.modificar_nota(nota_b);
        }
        else if (b.te_nota()) {
            a.afegir_nota(b.consultar_nota());
        }

        A.modificar_iessim(pos, a);
    } 
}

int main()
/* Llegeix dos conjunts d'estudiants (que contenen els mateixos estudiants amb 
   el mateix ordre, pero poden tenir notes diferents) i actualitza el primer conjunt, per tal que contingui la nota mes alta */
{
    Cjt_estudiants A, B;
    A.llegir();
    B.llegir();
    actual_conj(A, B);
    A.escriure();
}