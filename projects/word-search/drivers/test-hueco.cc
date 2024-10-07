#include <iostream>
#include "eda-error.hh"

#include "hueco.hh"
using std::cin;
using std::cout;
using std::endl;


int main() {
    try {
        hueco h1, h2;
        cout << h1.fila() << ' ' << h1.columna() << ' ' 
             << h1.orient().tostring() << ' ' << h1.longitud() << endl;
        cout << h2.fila() << ' ' << h2.columna() << ' ' 
             << h2.orient().tostring() << ' ' << h2.longitud() << endl;
        nat num_elems;
        cin >> num_elems;
        for (nat i = 0; i < num_elems; ++i) {
            cin >> h1 >> h2;
            if (h1 < h2) cout << "h1 menor que h2" << endl;
            else cout << "h1 mayor o igual a h2" << endl;
        }
        h1 = hueco(3, 4, orientacion("HR"), 40);
        cout << h1.fila() << ' ' << h1.columna() << ' ' 
             << h1.orient().tostring() << ' ' << h1.longitud() << endl;
        hueco h3 = h1;
        cout << h3.fila() << ' ' << h3.columna() << ' ' 
             << h3.orient().tostring() << ' ' << h3.longitud() << endl;
    }
    catch (const error& e) {
        cout << e << endl;
    }
}