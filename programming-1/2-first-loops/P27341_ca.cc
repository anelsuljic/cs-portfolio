//CONTROL C202D

//Per a cada parell d’enters a i b donats, el programa calcula i escriu la 
//suma de tots els cubs entre a i b.

//L’entrada és una seqüència de parells d’enters a i b.
//Per a cada parell de l’entrada, cal escriure, en una línia i segons el 
//format de l’exemple, el resultat de la suma a3 + (a + 1)3 + ⋯ + (b − 1)3 + 
//b3.

#include <iostream>

using namespace std;

int main() {
    int firstnum, secondnum; //nombres enters
    
    //Llegeix cada parella de nombres
    while (cin >> firstnum >> secondnum) {
        cout << "suma dels cubs entre " << firstnum << ' ' << 'i' << ' ' <<
             secondnum << ':';
        
        int sum = 0;
        
        //Fa la suma dels cubs
        for (int i = firstnum; i <= secondnum; ++i) {
            sum += i * i * i;
        }
        
        cout << ' ' << sum << endl;
    }
}
