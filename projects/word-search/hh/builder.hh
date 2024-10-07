// El módulo 'builder' define la función 'build', cuya finalidad principal
// es rellenar una sopa de letras a partir de un diccionario de palabras
// y una lista de huecos, los cuales indican la posición que dichas palabras 
// han de ocupar en la sopa. El resto de celdas se rellenaràn con carácteres 
// ASCII entre 'A' y 'Z' de forma aleatoria. La función devuelve, además, una 
// lista con las palabras que se han usado para rellenar los huecos, junto con 
// su posición de origen y orientación en la sopa. Puede suceder que algunos 
// huecos (o todos) tengan posiciones en común. En estos casos la función 
// buscará en el diccionario dado las palabras que satisfacen dicha 
// combinación. Si no existe ninguna solución para rellenar los huecos, la 
// lista de las palabras halladas será vacia, la sopa de dejará intacta y se 
// lanzará un error informando del hecho sucedido.




#ifndef _BUILDER_HH
#define _BUILDER_HH




#include <list>

#include "match.hh"
#include "hueco.hh"
#include "sopa-letras.hh"
#include "diccionario.hh"
using std::list;




namespace builder {

    // Rellena una serie de huecos en una sopa de letras con las palabras
    // almacenadas en un diccionario, y el resto de celdas de dicha sopa con 
    // un carácter ASCII entre 'A' y 'Z' de forma aleatoria.
    // Pre: 'huecos' no contiene más de un hueco con misma posición de origen
    //      y orientación. 'l' es vacia y es un parámetro de salida. 'd' y
    //      'huecos' no pueden ser vacíos. 's.num_filas()' > 0 y 
    //      's.num_columnas()' > 0.
    // Post: en caso de éxito, 's' contiene los huecos indicados en 'huecos'
    //       rellenados con una de las palabras de 'd' por cada hueco, y el 
    //       resto de posiciones con alguna letra ASCII entre 'A' y 'Z' al 
    //       azar; 'l' contiene la lista de palabras que ocupan cada hueco y 
    //       está ordenada crecientemente (ver definición del operador '<' en 
    //       la clase 'match'). En caso contrario, 'l' y 's' quedan intactas y 
    //       se lanza un error informando de la no existencia de solución.
    // Errores: lanza un error en caso que no haya una combinación de palabras
    //          para rellenar los huecos, o alguno de los huecos no quepa en 
    //          's'.
    void build(const diccionario& d, const list<hueco>& huecos, 
               list<match>& l, sopa_letras& s) noexcept(false);

}



#endif