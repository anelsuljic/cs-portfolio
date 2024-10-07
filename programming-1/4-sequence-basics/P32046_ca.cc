//CONTROL C202F

//Feu un programa que llegeixi una seqüència de naturals, i que compti i 
//escrigui aquells que acabin amb les mateixes tres xifres que el primer 
//nombre de la seqüència.

//L’entrada és una seqüència no buida de naturals més grans o iguals que 100.
//Sortida: Cal escriure els nombres de l’entrada que acabin amb les mateixes 
//tres xifres que el primer nombre de la seqüència, així com quants d’aquests 
//nombres hi ha. Utilitzeu el format dels exemples.

#include <iostream>

using namespace std;

int main() {
    int primer, num; //nombres naturals
    cin >> primer;
    
    cout << "nombres que acaben igual que " << primer << ':' << endl;
    
    int total = 0;
    
    while (cin >> num) {
        //Comprova si els nombres acaben igual
        if (num % 1000 == primer % 1000) {
            ++total;
            
            cout << num << endl;
        }
    }
    
    cout << "total: " << total << endl;
}
