// El módulo 'list_sort' define una función genérica 'sort' que ordena 
// crecientemente un lista cuyos elementos son de tipo 'elem'. Para que la 
// ejecución de 'sort' resulte exitosa, 'elem' debe disponer de: constructora 
// por defecto, constructora por copia, operador de asignación y operador '<'.


#ifndef _LIST_SORT_HH
#define _LIST_SORT_HH


#include <list>
using std::list;


namespace list_sort {

    // Ordena crecientemente una lista cuyos elementos son de tipo 'elem'.
    // Pre: 'elem' debe disponer de: constructora por defecto, constructora por
    //      copia, operador de asignación y operador '<'.
    // Post: 'l' está ordenada crecientemente.
    template <typename elem>
    void sort(list<elem>& l) noexcept;
}

#include "list-sort.t"


#endif