#include "eda-util.hh"
using util::nat;


namespace list_sort {

    // Operaciones para manipular iteradores




    // Calcula la distancia entre dos elementos de una misma estructura de 
    // datos, apuntados por iteradores. 
    // Pre: 'izq' y '--der' apuntan al primer y último elemento de [izq, der), 
    //      y todos los elementos de este rango forman parte de la misma 
    //      estructura de datos.
    // Post: devuelve el numero de saltos que hay entre 'izq' y 'der'. El 
    //       valor es 0 si izq == der.
    template <typename iter_bidireccional>
    nat distancia(iter_bidireccional izq, iter_bidireccional der) noexcept;


    // Devuelve un iterador que apunta al elemento que está situado ciertas 
    // posiciones más adelante que otro elemento indicado de la misma 
    // estructura de datos.
    // Pre: ----
    // Post: devuelve el elemento apuntado por (it + n);
    template <typename iter_bidireccional>
    iter_bidireccional avanzar(iter_bidireccional it, nat n = 1) noexcept;


    // Devuelve un iterador que apunta al elemento anterior.
    // Pre: siendo 'x' una estructura de datos dotada de iteradores, 
    //      it != x.begin().
    // Post: devuelve '--it'.
    template <typename iter_bidireccional>
    iter_bidireccional anterior(iter_bidireccional it) noexcept;


    // Intercambia dos elementos de una misma estructura de datos.
    // Pre: 'it1' e 'it2' apuntan a elementos de la misma estructura de datos.
    // Post: *it1 e *it2 han sido intercambiados.
    template <typename iter_bidireccional>
    void intercambia(iter_bidireccional it1, iter_bidireccional it2) noexcept;




    // Algoritmos de ordenacion




    // Toda estructura de datos que tenga un número de elementos menor o igual 
    // a 10 será ordenada con la ordenación por inserción. En caso contrario, 
    // será ordenada con la ordenación rápida.
    const nat M = 10;




    // Devuelve un iterador apuntando al elemento de una estructura de datos 
    // el cual corresponde a la mediana entre el primer, el último y el 
    // elemento central de la misma estructura de datos.
    // Pre: 'izq' y '--der' apuntan al primer y último elemento de [izq, der),
    //      y todos los elementos de este rango forman parte de la misma 
    //      estructura de datos.
    // Post: devuelve un iterador apuntando a la mediana entre los siguientes 
    //       elementos de [izq, der): *izq, *(--der), elemento central de 
    //       [izq, der).
    template <typename iter_bidireccional>
    iter_bidireccional escoger_pivote(iter_bidireccional izq, 
                                      iter_bidireccional der) noexcept;



    // Encuentra el pivote de un rango de elementos de una estructura de 
    // datos, y coloca todos aquellos elementos del rango menores o igual que 
    // el pivote a la izquierda de este, y todos aquellos elementos del rango 
    // mayores que el pivote a la derecha de este. El pivote es la mediana 
    // entre el primer, el último y el elemento central del rango.
    // Pre: los elementos de [izq, der) deben disponer de constructora por 
    //      defecto, constructora por copia, operador de asignación. operador 
    //      '<' y operador '<='.
    // Post: es devuelto un iterador bidireccional al pivote 'x', donde 'x' 
    //       pertence a [izq, der); todos los elementos de [izq, der) más 
    //       pequeños o iguales que 'x' están situados a la izquerda de este, 
    //       y los elementos de [izq, der) más grandes que 'x' a la derecha de 
    //       este.
    template <typename iter_bidireccional>
    iter_bidireccional particion(iter_bidireccional izq, 
                                 iter_bidireccional der) noexcept;



    // Ordena crecientemente una estructura de datos usando el algoritmo de
    // ordenación rápida.
    // Pre: los elementos de [izq, der) deben disponer de constructora por 
    //      defecto, constructora por copia, operador de asignación, operador 
    //      '<' y operador '<='.
    // Post: los elementos de [izq, der) estan ordenados crecientemente.
    template <typename iter_bidireccional>
    void quick_sort(iter_bidireccional izq, iter_bidireccional der) noexcept;



    // Ordena crecientemente una estructura de datos usando el algoritmo de
    // ordenación por inserción.
    // Pre: los elementos de [izq, der) deben disponer de constructora por 
    //      defecto, constructora por copia, operador de asignación y operador 
    //      '<'.
    // Post: los elementos de [izq, der) estan ordenados crecientemente.
    template <typename iter_bidireccional>
    void insertion_sort(iter_bidireccional izq, iter_bidireccional der) 
         noexcept;

}










// Implementación operaciones iteradores


template <typename iter_bidireccional>
nat list_sort::distancia(iter_bidireccional izq, iter_bidireccional der) 
               noexcept {

    nat dist = 0;
    while (izq != der) {
        // Inv: 'izq' ha avanzado 'dist' posiciones.
        
        ++dist;
        ++izq;
    }

    return dist;
}


template <typename iter_bidireccional>
iter_bidireccional list_sort::avanzar(iter_bidireccional it, nat n) 
noexcept {

    while (n > 0) {
        // Inv: 'it' ha avanzado 'n-1' posiciones.

        ++it;
        --n;
    }

    return it;
}


template <typename iter_bidireccional>
iter_bidireccional list_sort::anterior(iter_bidireccional it) noexcept {
    return --it;
}


template <typename iter_bidireccional>
void list_sort::intercambia(iter_bidireccional it1, iter_bidireccional it2) 
                noexcept {
    
    if (it1 != it2) {
        auto aux = *it1;
        *it1 = *it2;
        *it2 = aux;
    }
}










// Implementación algoritmos ordenación


template <typename iter_bidireccional>
iter_bidireccional list_sort::escoger_pivote(iter_bidireccional izq, 
                                             iter_bidireccional der) noexcept {

    iter_bidireccional mediana = avanzar(izq, distancia(izq, der) / 2);
    // El rango es [izq, der). Por tanto, el último elemento de este rango es 
    // --der.
    --der;
    
    bool izq_es_mediana = (*mediana <= *izq and *izq <= *der) or
                          (*der <= *izq and *izq <= *mediana);
    bool der_es_mediana = (*mediana <= *der and *der <= *izq) or
                          (*izq <= *der and *der <= *mediana);

    if (der_es_mediana) mediana = der;
    else if (izq_es_mediana) mediana = izq;

    return mediana;
}


template <typename iter_bidireccional>
iter_bidireccional list_sort::particion(iter_bidireccional izq, 
                                        iter_bidireccional der) noexcept {
    
    iter_bidireccional pivote = escoger_pivote(izq, der);
    intercambia(pivote, anterior(der));
    // Ahora anterior(der) es el pivote.

    iter_bidireccional it1 = izq;
    iter_bidireccional it2 = izq;
    while (it2 != anterior(der)) {
        // Inv: todos los elementos de [izq, it1) son más pequeños que el 
        //      pivote; izq <= it2 <= der.

        if (*it2 < *anterior(der)) {
            intercambia(it1, it2);
            ++it1;
        }
        ++it2;
    }

    // Colocamos el pivote a su posición correcta.
    intercambia(it1, it2);

    return it1;
}


template <typename iter_bidireccional>
void list_sort::quick_sort(iter_bidireccional izq, iter_bidireccional der) 
                noexcept {

    nat num_elems = distancia(izq, der);
    if (0 < num_elems and num_elems <= M) {
        insertion_sort<iter_bidireccional>(izq, der);
    }
    else if (0 < num_elems) {
        iter_bidireccional pivote = particion(izq, der);
        quick_sort(izq, pivote);
        quick_sort(avanzar(pivote), der);
    }
}


template <typename iter_bidireccional>
void list_sort::insertion_sort(iter_bidireccional izq, iter_bidireccional der) 
                noexcept {

    // Si el rango solo contiene un elemento, no hace falta ordenar nada.
    // Hacemos esta comparacion, ya que sinó, al ejectutar avanzar(izq) podemos
    // obtener errores fatales.
    if (izq != der) {
        for (iter_bidireccional it = avanzar(izq); it != der; ++it) {
            // Inv 1: los elementos de [izq, it) están ordenados 
            //        crecientemente.

            auto elem = *it;
            iter_bidireccional it_aux = it;
            while (it_aux != izq and elem < *anterior(it_aux)) {
                // Inv 2: [izq, it_aux) y [++it_aux, ++it) están 
                //        ordenados crecientemente.

                *it_aux = *anterior(it_aux);
                --it_aux;
            }
            *it_aux = elem;
        }
    }
}


template <typename elem>
void list_sort::sort(list<elem>& l) noexcept {
    quick_sort(l.begin(), l.end());
}
