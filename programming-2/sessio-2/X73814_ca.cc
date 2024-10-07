#include "Estudiant.hh"
#include <vector>
//#include <iostream>

void llegir(vector<Estudiant> &vest)
/* Pre: hi ha preparats al canal estandard d'entrada un enter i una sequencia 
   d'estudiants (les dades son de la forma "dni nota") */
/* Post: vest conte totes les dades llegides a traves del canal 
   d'entrada */
{
    int size = vest.size();
    for (int i = 0; i < size; ++i)  {
        vest[i].llegir();
    }  
}

void escriure(const vector<Estudiant> &vest)
/* Pre: cert */
/* Post: tots els elements de vest s'han escrit al canal estandard de sortida */
{
    int size = vest.size();
    for (int i = 0; i < size; ++i) {
        vest[i].escriure();
    }
}

vector<Estudiant> simplificar_vec(const vector<Estudiant> &vest)
/* Pre: vest no es buit */
/* Post: el resultat conte els estudiants de vest amb la nota mes alta de totes
   les seves aparicions */
{
    vector<Estudiant> res(1, vest[0]);  //afegim directament el primer estudiant

    int size = vest.size();
    int lpres = res.size() - 1; //ultima posicio de res
    for (int i = 1; i < size; ++i) {
        if (vest[i].consultar_DNI() == res[lpres].consultar_DNI()) {
            if (vest[i].te_nota()) {
                double nota = vest[i].consultar_nota();
                if (res[lpres].te_nota() and res[lpres].consultar_nota() < 
                    nota) {
                    res[lpres].modificar_nota(nota);
                }
                else if (not res[lpres].te_nota()) res[lpres].afegir_nota(nota);
            }    
        }
        else {
            res.push_back(vest[i]);
            ++lpres;
        }
    }

    return res;
}

int main()
/* Entrada: una seqüència no buida d'estudiants {dni, nota}, amb o sense 
   repeticions */
/* Sortida: una seqüència d'estudiant {dni, nota} sense repeticions de dni */
{
    int size;
    cin >> size;
    vector<Estudiant> vest(size);
    llegir(vest);
    vector<Estudiant> res = simplificar_vec(vest);
    escriure(res);
}