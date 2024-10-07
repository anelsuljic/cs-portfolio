#include <iostream>

#include "match.hh"
using std::cin;
using std::cout;
using std::endl;


int main() {
    match m1, m2;
    cout << m1 << endl;
    cout << m2 << endl;
    
    while (cin >> m1 >> m2) {
        if (m1 < m2) cout << "m1 menor que m2" << endl;
        else if (m1 > m2) cout << "m1 mas grande que m2" << endl;
        else if (m1 <= m2) cout << "m1 menor o igual que m2" << endl;  
    }
    m1 = match("HOLA", 0, 4, orientacion("V"));

    cout << m1.palabra() << endl;
    cout << m1.fila() << endl;
    cout << m1.columna() << endl;
    cout << m1.orient().tostring() << endl;
}