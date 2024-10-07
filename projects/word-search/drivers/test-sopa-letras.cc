#include <iostream>
#include "eda-error.hh"

#include "sopa-letras.hh"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main() {
    try {   
        nat n_fil, n_col;
        cin >> n_fil >> n_col;
        // Probamos 'sopa_letras(nat num_fil, nat num_col)' y 'operator<<'.
        sopa_letras s(n_fil, n_col);
        cout << "Sopa limpia:\n";
        cout << s << "\n\n" << endl;

        string word, o;
        nat fil, col;
        while (cin >> word >> fil >> col >> o) {
            try { 
                // Probamos 'inserta_cadena' y 'cadena'.
                s.inserta_cadena(word, fil, col, orientacion(o));
                cout << s.cadena(fil, col, word.size(), orientacion(o)) << endl;
            }
            catch (const error& e) {
                cerr << word << ' ' << fil << ' ' << col << ' ' << o << endl;
                throw;
            }
        }

        cout << "\n\n\n";

        cout << "Sin reemplazar asteriscos:\n" << string(10, '-') << endl;  
        cout << s << "\n\n\n" << endl;
        cout << (s.es_inicializada() ? "Si" : "No") << endl;

        s.reemplazar_asteriscos();
        cout << "Despues de reemplazar asteriscos:\n" << string(10, '-') 
             << endl;
        cout << s << "\n\n\n" << endl;
        cout << (s.es_inicializada() ? "Si" : "No") << endl;

        cout << s.cadena(9, 2, 4, orientacion("H")) << endl;
        cout << s.cadena(9, 2, 3, orientacion("HR")) << endl;
        cout << s.cadena(9, 2, 3, orientacion("V")) << endl;
        cout << s.cadena(9, 2, 10, orientacion("VR")) << endl;
        cout << s.cadena(9, 2, 3, orientacion("D")) << endl;
        cout << s.cadena(9, 2, 3, orientacion("DR")) << endl;
        cout << s.cadena(9, 2, 4, orientacion("B")) << endl;
        cout << s.cadena(9, 2, 3, orientacion("BR")) << endl;

        s.inserta_fila(string(n_col, '*'));
        cout << "\n\n\n" << s << "\n\n" << endl;

        cout << s.num_filas() << endl;
        cout << s.num_columnas() << endl;
        cout << sopa_letras::max_filas() << endl;
        cout << sopa_letras::max_cols() << endl;

        sopa_letras s2;
        s2.inserta_fila(string(n_col, '*'));
        cout << "\n\n\n" << s2 << endl;
    }
    catch (const error& e) {
        cerr << e << endl;
    }
}