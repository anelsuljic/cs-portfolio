// ABC

// El programa llegeix tres nombres enters (A, B, C) diferents i els escriu al 
// canal de sortida estàndar segons l'ordre indicat amb una comanda llegida 
// del canal d'entrada. Es compleix que A < B < C. En cas que els nombres no 
// es llegeixin en aquest ordre, el programa s'encarregarà de fer complir la 
// propietat anterior.

// Entrada: consisteix en dues parts. La primera part consisteix en una linia
//          indicant els tres nombres enters, tots tres separats per un espai 
//          i complint que A,B,C < 100. La segona part consisteix en un string 
//          de tres caràcters, que indica l'ordre d'escriptura dels tres 
//          nombres. Cada caràcter de l'string ha de tenir un d'aquests 3 
//          caràcters: 'A', 'B', 'C'. No poden haver-hi caràcters repetits.
// Sortida: escriu al canal de sortida cada un dels tres nombres llegits del 
//          canal d'entrada segons l'ordre indicat, separats per un espai 
//          entre ells.

// Exemple d'entrada i sortida:
//
// Ent: 6 4 2
//      CAB
// Sor: 6 2 4


#include <iostream>
using namespace std;


const int NUM_LLETRES = 3;


int main()
{
    int a, b, c;    // a,b,c < 100.
    cin >> a >> b >> c;

    // Reordena els nombres, en cas que sigui necessari.
    if (a > b) {
        int aux = a;
        a = b;
        b = aux;
    }
    if (a > c) {
        int aux = a;
        a = c;
        c = aux;
    }
    if (b > c) {
        int aux = b;
        b = c;
        c = aux;
    }

    int comptador = 0;
    while (comptador < NUM_LLETRES) {
        // Inv: s'han imprès pel canal de sortida tots el nombres tractats
        //      fins al moment, sense repeticions.

        char lletra;    // només pot ser 'A', 'B', 'C'
        cin >> lletra;

        // Ha d'haver espais entre els nombres impresos
        if (comptador != 0) cout << ' ';
        
        if (lletra == 'A') cout << a;
        else if (lletra == 'B') cout << b;
        else if (lletra == 'C') cout << c;
 
        ++comptador;
    }
    
    cout << endl;
}