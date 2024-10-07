//CONTROL C202B

//El programa, donat un natural n≥ 2 seguit de n nombres reals x1, x2,…, xn,
//calcula la variança dels nombres fent servir la fórmula que surt al jutge.

//L’entrada és un natural n≥ 2 seguit de n nombres reals x1, x2,…, xn.
//Sortida: Cal escriure el valor de la variança dels n nombres donats amb
//exactament dos dígits desprès del punt decimal.

#include <iostream>

using namespace std;

int main() {
    int numelem; //nombre natural >= 2
    cin >> numelem;

    double sumatori_1 = 0;
    double sumatori_2 = 0;

    //Llegeix cada element
    for (int i = 0; i < numelem; ++i) {
        double elem; //nombres reals
        cin >> elem;

        //Realitza els dos sumatoris
        sumatori_1 += elem * elem;
        sumatori_2 += elem;
    }

    //Calcula el resultat final
    double resultat = sumatori_1 / (numelem - 1) - (sumatori_2 * sumatori_2)
                      / (numelem * (numelem - 1));

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << resultat << endl;
}
