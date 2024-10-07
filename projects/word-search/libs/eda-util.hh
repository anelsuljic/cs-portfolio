// El módulo 'util' define una serie de funciones genericas y redifiniciones 
// de tipos para simplificar su legibilidad.




#ifndef _EDA_UTIL
#define _EDA_UTIL




#include <list>
using std::list;




namespace util {

    // Redefinicion de tipos
    typedef unsigned int nat;



    // Funciones genéricas



    // Lee los contenidos de una lista cuyos elementos son de tipo <elem>.
    // Pre/entrada: el canal estándar de entrada contiene un número natural 
    //              'n' seguido una secuencia de 'n' elementos de tipo 'elem'; 
    //              'elem' debe tener el operador '>>' sobrecargado; 'l' es 
    //              vacia y es un parámetro de salida.
    // Post: 'l' contiene los elementos de tipo 'elem' leidos del canal de 
    //       entrada.
    // Coste: theta(n), donde 'n' es el número de elementos leídos.
    template <typename elem>
    void leer_lista(list<elem>& l) noexcept;


    // Imprime el contenido de una lista cuyos elementos son de tipo <elem>.
    // Pre: 'elem' debe tener sobrecargado el operador '<<'.
    // Post: son impresos por el canal estándar de salida el contenido de 'l', 
    //       donde cada elemento ocupa una linea independiente.
    // Coste: theta(n), donde 'n' = l.size().
    template <typename elem>
    void imprimir_lista(const list<elem>& l) noexcept;


    // Replica la operacion de resta de conjuntos, pero en listas.
    // Pre: a = A y b = B; 'A' y 'B' están ordenadas crecientemente.
    // Post: 'a' contiene todos los elementos de 'A' excepto aquellos 
    //       elementos que también forman parte de 'B'.
    // Coste: big-o(max{n,m}) y omega(min{n,m}), donde 'n' = A.size() y 
    //        'm' = B.size().
    template <typename elem>
    void restar_lista(list<elem>& a, const list<elem>& b) noexcept;


    // Calcula y devuelve el mínimo entre dos elementos de tipo 'elem'.
    // Pre: 'elem' debe tener los operadores '<' y '=' sobrecargados.
    // Post: devuelve 'a' o 'b' según el cual sea más pequeño.
    // Coste: theta(1).
    template <typename elem>
    elem min(const elem& a, const elem& b) noexcept;


    // Devuelve un elemento aleatorio dentro de un rango de elementos.
    // Pre: ----
    // Post: devuelve un elemento aleatorio entre [a, b].
    // Coste: theta(1).
    template <typename elem>
    elem valor_aleatorio(elem a, elem b) noexcept;
}

#include "eda-util.t"




#endif