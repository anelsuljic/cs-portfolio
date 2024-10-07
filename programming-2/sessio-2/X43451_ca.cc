//#include "vectorIOEstudiant.hh"
#include "Estudiant.hh"
#include <vector>

void arrodonir_nota(Estudiant &est)
/* Pre: est te nota */
/* Post: est passa a tenir la nota arrodonida a la decima mes propera */
{
    est.modificar_nota(int(10.0 * (est.consultar_nota() + 0.05)) / 10.0);
}

void arrodonir_vector(vector<Estudiant>& v)
/* Pre: cert */
/* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
   a la decima mes propera */
{
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        if (v[i].te_nota()) arrodonir_nota(v[i]);
    }
}

/*int main()
{
    vector<Estudiant> vest;
    llegir(vest);
    arrodonir_vector(vest);
    escriure(vest);
}*/