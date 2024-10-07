#include "diccionario.hh"
#include "eda-util.hh"
#include "eda-error.hh"
#include <iostream>
#include <string>
#include <list>
using std::cin; 
using std::cout;
using std::endl;
using std::string;
using std::list;
using util::imprimir_lista;


int main() {
    try {
        diccionario d;
        if (d.es_vacio()) cout << "Es vacio, aun" << endl;
        cin >> d;

        string s;
        cin >> s;
        cout << "Prefijo de \'s\': " << d.prefijo(s) << endl;
        string nueva_palabra;
        cin >> nueva_palabra;
        while (nueva_palabra != "end") {
            d.inserta(nueva_palabra);
            cout << "Prefijo de \'s\': " << d.prefijo(s) << endl;
            cin >> nueva_palabra;
        }

        list<string> l;
        d.satisfacen_patron("A*T**", l);
        if (l.empty()) cout << "No hay patron \"A*T**\"" << endl;
        else imprimir_lista<string>(l);

        l.clear();
        d.satisfacen_patron("***************", l);
        if (l.empty()) cout << "No hay patron \"***************\"" << endl;
        else imprimir_lista<string>(l);
        string pref = d.prefijo("ZOO");
        if (pref.empty()) cout << "No hay prefijo" << endl;
        else cout << pref << endl;

        cout << "Escribe d:" << endl;
        cout << d;

        // Operaciones para comprobar excepciones.

        //d.inserta("ldsl");
        //string pref = d.prefijo("gghghsg");
        //cout << pref << endl;
        //d.satisfacen_patron("fkshflks", l);
    }
    catch (const error& e) {
        cout << e << endl;
    }
}