// SOPA DE LETRAS



// El programa construye y resuelve un conjunto de sopas de letras a partir de
// un diccionario de palabras dado.

// Entrada: consiste de una serie de elementos:
//          1) una secuencia de palabras en español (codificada con caracteres 
//             ASCII del rango ['A', 'Z']) acabada con el string "end", 
//             las cuales representan el diccionario de palabras.
//          2) una secuencia cuyos elementos se definen con estos atributos, 
//             en este orden: dos naturales (num_fil, num_col) que representan 
//             el tamaño de la sopa de letras, un natural 'num_h' seguido de 
//             'num_h' huecos que representan los huecos de la sopa de letras 
//             a rellenar con palabras del diccionario. Es decir, estos 
//             atributos representan una sopa de letras a construir y resolver.
//             Si el par (num_fil, num_col) == (0, 0), entonces a continuación 
//             debe haber un natural 'num_s' más grande que cero, seguido 
//             de 'num_s' strings, cuyos carácteres son ASCII del rango 
//             ['A', 'Z'] U {'*'} y cuyo tamaño es más grande o igual a 4.
//
//             Nota: un hueco se representa en el canal de entrada de la 
//             siguiente manera: 'fila' 'columna' 'orientacion' 'longitud'
//
//             Pre: (num_fil, num_col) == (0, 0) o 'num_fil' y 'num_col' son 
//                  naturales más grandes que cero; 'fila' y 'columna' son 
//                  naturales más grandes o igual a cero; 
//                  'orientacion' = {"H", "HR", "V", "VR", "D", "DR", "B", 
//                  "BR"}, es decir, un string cuyo valor es uno del conjunto 
//                  anterior; 'num_h' y 'longitud' son naturales más grandes 
//                  que cero. Ver las definiciones de 'hueco' y 'orientacion' 
//                  para ver el significado de sus valores.
//
// Salida: por cada elemento de la secuencia de entrada, se imprime: 
//         1) la sopa de letras construida; 
//         2) una lista de las palabras encontradas en la sopa, donde cada 
//            palabra es acompañada con la posición inicial de su primer 
//            carácter en la sopa y su orientación en esta misma (ver 
//            definición de la clase 'match'); 
//         3) una lista de las palabras no encontradas (que es un subconjunto 
//            de las palabras que se añadieron a los huecos indicados en el 
//            canal de entrada), donde cada palabra es complementada igual que 
//            en la lista anterior. En caso que se hayan encontrado todas las 
//            palabras, se imprimirá el string "solucion correcta" y no la 
//            lista de palabras no encontradas.
//
//         Cada uno de los tres puntos anteriores es separado por una linea 
//         de diez guiones, predecida y sucedida por una linea en blanco.
//         Cada salida de cada elemento de la secuencia de entrada es separada 
//         por una linea de 60 barras diagonales '/', predecida y sucedida por 
//         dos lineas en blanco.





#include <iostream>
#include <list>
#include <string>
#include "eda-error.hh"
#include "eda-util.hh"

#include "diccionario.hh"
#include "sopa-letras.hh"
#include "hueco.hh"
#include "match.hh"
#include "builder.hh"
#include "solver.hh"
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using namespace util;
using namespace builder;
using namespace solver;




// Imprime los resultados de una construcción y resolución de una sopa de 
// letras.
// Pre: 'sopa' no es una sopa de letras vacía; 'pal_noenc' es una lista de las 
//      palabras no encontradas en 'sopa' y que fueron previamente insertadas 
//      en ella; 'pal_enc' es una lista de las palabras encontradas en 'sopa' 
//      y no es vacia.
// Post/salida: son impresos en el canal estándar de salida los siguientes 
//              elementos, separados por una linea de diez guiones entre ellos 
//              (predecida y sucedida por una linea en blanco): 'sopa', 
//              'pal_enc', 'pal_noenc'. En caso que 'pal_noenc' sea vacia, se 
//              imprime el string "solucion correcta".
void imprimir_resultados(const sopa_letras& sopa, const list<match>& pal_enc,
                         const list<match>& pal_noenc) noexcept {
    
    cout << sopa << endl;
    cout << '\n' << string(10, '-') << '\n' << endl;

    imprimir_lista<match>(pal_enc);
    cout << '\n' << string(10, '-') << '\n' << endl;
    
    if (not pal_noenc.empty()) imprimir_lista<match>(pal_noenc);
    else cout << "solucion correcta" << endl;
}




int main() {
    diccionario dic;    
    cin >> dic;         

    nat num_fil, num_col;
    bool primero = true;       
    while (cin >> num_fil >> num_col) {
        try {
            sopa_letras sopa(num_fil, num_col);
            if (num_fil == 0 and num_col == 0) cin >> sopa;
            list<hueco> huecos;
            leer_lista<hueco>(huecos);


            list<match> pal_ins;      // palabras insertadas en 'sopa'
            build(dic, huecos, pal_ins, sopa);
            list<match> pal_enc;      // palabras encontradas en 'sopa'
            solve(sopa, dic, pal_enc);


            if (not primero) {
                cout << "\n\n" << string(60, '/') << "\n\n" << endl;
            }
            else primero = false;
            restar_lista<match>(pal_ins, pal_enc);
            imprimir_resultados(sopa, pal_enc, pal_ins);
        }
        catch (const error& e) {
            cout << e << endl;
        }
    }
}