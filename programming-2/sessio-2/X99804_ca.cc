#include "Estudiant.hh"
#include <vector>
#include <algorithm>
#define NDEBUG
#include <cassert>

//versio 1

//int main()
/* Entrada: dos enters, M i N, que representen el nombre d'estudiants i el 
   nombre d'assignatures, respectivament; un enter S que es el cardinal del 
   subconjunt d'assignatures, seguit dels elements del subconjunt; una 
   sequencia d'estudiants {dni, N notes} */
/* Sortida: una sequencia d'estudiants amb el seu dni i la nota mitjana de 
   totes les notes del subconjunt de cardinal S */
/*{
    int num_est, num_assig, card_subconj; //M, N i S, respectivament
    cin >> num_est >> num_assig >> card_subconj;
    //per seleccionar les assignatures
    vector<bool> assig(num_assig, false);  
    for (int i = 0; i < card_subconj; ++i) {
        int elem;
        cin >> elem;
        assig[elem - 1] = true;
    }
    //tractament sequencia
    for (int j = 0; j < num_est; ++j) {
        int dni;
        cin >> dni;
        double suma = 0;
        for (int k = 0; k < num_assig; ++k) {
            double nota;
            cin >> nota;
            if (assig[k]) suma += nota;
        }
        cout << dni << ' ' << suma / card_subconj << endl;
    }
}*/

//versio 2

bool cmp(const Estudiant &est1, const Estudiant &est2)
/* Pre: est1 i est2 son estudiants amb nota */
/* Post: el resultat es cert si la nota d'est1 es mes gran que la nota d'est2 
   i, en cas d'empat de notes, es cert si, i nomes si, el dni d'est1 es mes 
   petit que el dni d'est2. En cas contrari, el resultat es fals */
{
    bool res = false;
    if (est1.consultar_nota() == est2.consultar_nota()) {
        res = est1.consultar_DNI() < est2.consultar_DNI();
    }
    else res = est1.consultar_nota() > est2.consultar_nota();

    return res;
}

void escriure(const vector<Estudiant> &vest)
/* Pre: cert */
/* Post: son escrit al canal estandard de sortida tots els elements de vest 
   {dni, nota} */
{
    int size = vest.size();
    for (int i = 0; i < size; ++i) {
        vest[i].escriure();
    }
}

int main()
/* Entrada: dos enters, M i N, que representen el nombre d'estudiants i el 
   nombre d'assignatures, respectivament; un enter S que es el cardinal del 
   subconjunt d'assignatures, seguit dels elements del subconjunt; una 
   sequencia d'estudiants {dni, N notes} */
/* Sortida: una sequencia d'estudiants amb el seu dni i la nota mitjana de 
   totes les notes del subconjunt de cardinal S, ordenada decreixentment per 
   nota i, en cas d'empat de notes, ordenada creixentment pel dni */
{
    int num_est, num_assig, card_subconj; //M, N i S, respectivament
    cin >> num_est >> num_assig >> card_subconj;
    //per seleccionar les assignatures
    vector<bool> assig(num_assig, false);  
    for (int i = 0; i < card_subconj; ++i) {
        int elem;
        cin >> elem;
        assig[elem - 1] = true;
    }
    //lectura dades estudiants
    vector<Estudiant> vest(num_est);
    for (int j = 0; j < num_est; ++j) {
        int dni;
        cin >> dni;
        vest[j] = Estudiant(dni);
        //calcula la mitjana d'aquest estudiant
        double suma = 0;
        for (int k = 0; k < num_assig; ++k) {
            double nota;    //0 <= nota <= 10 
            cin >> nota;
            if (assig[k]) suma += nota;
        }
        assert(suma / card_subconj >= 0 and suma / card_subconj <= 10 and 
               "El resultat ha de ser entre 0 i 10");
        vest[j].afegir_nota(suma / card_subconj);
    }
    //ordenacio i escriptura de resultats
    sort(vest.begin(), vest.end(), cmp);
    escriure(vest);
}