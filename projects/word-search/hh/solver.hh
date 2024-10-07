// El módulo 'solver' define una única fúnción ('solve') cuya 
// finalidad es resolver una sopa de letras a partir de un 
// diccionario de palabras. Concretamente, encontrará todas las 
// palabras de cuatro o más letras que figuran en la sopa. Una vez 
// resuelta, devolverá una lista con todas las palabras halladas 
// junto con su posición de origen y orientación en la sopa de 
// letras. En caso de que aparezcan varias palabras en la sopa de 
// letras con la misma posición de origen y orientación, solamente 
// se listará la más larga. 



#ifndef _SOLVER_HH
#define _SOLVER_HH


#include <list>

#include "match.hh"
#include "sopa-letras.hh"
#include "diccionario.hh"
using std::list;



namespace solver {

    // Resuelve una sopa de letras a partir de un diccionario dado.
    // Pre: 'd' no es vacío; s.num_filas() > 0 y s.num_columnas > 0; 's' está 
    //      inicializada; 'l' es vacía y es un parámetro de salida.
    // Post: 'l' contiene todas las palabras de cuatro o más letras 
    //       halladas en 's'. En caso que haya más de una palabra 
    //       con la misma posición de origen y orientación en 's', 
    //       'l' solo contendrá la que sea más larga. 'l' está 
    //       ordenada crecientemente (ver definición del operador 
    //       '<' en la clase 'match').
    // Errores: lanza una excepción si no se cumple algún aspecto de la 
    //          precondición y puede propagar excepciones de algunas 
    //          operaciones usadas en la implementación, en caso que existan.
    void solve(const sopa_letras& s, const diccionario& d, list<match>& l)
         noexcept(false);

}


#endif