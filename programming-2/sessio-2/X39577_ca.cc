#include "Estudiant.hh"
#include <vector>

int main()
/* Entrada: dos enters, M i N, que representen el nombre d'estudiants i el 
   nombre d'assignatures, respectivament; un enter S que es el cardinal del subconjunt d'assignatures, seguit dels elements del subconjunt; una sequencia d'estudiants {dni, N notes} */
/* Sortida: una sequencia d'estudiants amb el seu dni i la nota mitjana de 
   totes les notes del subconjunt de cardinal S */
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
}