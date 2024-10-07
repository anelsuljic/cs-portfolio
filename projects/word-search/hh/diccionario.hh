// La clase 'diccionario' corresponde a una estructura de datos que almacena 
// palabras cuyos caracteres estan codificados en ASCII y forman parte del 
// rango ['A', 'Z']. Por supuesto, la clase viene dotada de una operación de 
// inserción de palabras, así como dos operaciones especiales: 'prefijo' y 
// 'satisfacen_patron'. La operación 'prefijo' devuelve distintos resultados 
// según el string que se pase como parámetro actual: si dicho string 
// corresponde a una palabra del diccionario, entonces se devuelve la palabra 
// entera. En caso contrario, no se devuelve la palabra entera: o bien se 
// devuelve el prefijo más largo del string (si este prefijo forma parte del 
// diccionario) o se devuelve un string vacio (que es una palabra del 
// diccionario). La operación 'satisfacen_patron' recibe un patrón a través de 
// un string y devuelve una lista ordenada con las palabras del diccionario 
// que satisfacen dicho patrón. Un patrón consta de letras ASCII entre la 'A' 
// y la 'Z' y asteriscos. Una posición que contiene un asterisco significa que 
// en ella puede haber cualquier letra entre la 'A' y la 'Z'. En general, si 
// por ejemplo, se recibe el patron "A*T**", la operación deberá devolver 
// todas las palabras del diccionario que tienen una 'A' como primera letra y 
// una 'T' como tercera letra. Si el patrón es '*****', devolverá todas las 
// palabras de longitud 5, y, si el patron es "ASTRO", devolverá una lista con 
// esa palabra en caso que forme parte del diccionario. La lista será vacia si 
// no hay ninguna palabra que satisfaga el patrón dado.



#ifndef _DICCIONARIO_HH
#define _DICCIONARIO_HH




#include <iostream>
#include <string>
#include <list>
using std::string;
using std::list;
using std::istream;
using std::ostream;




class diccionario {
  private:
    class impl_;
    impl_* rep_;

  public:

    // Constructora


    // Contruye un diccionario que contiene una única palabra: la palabra 
    // vacía.
    // Pre: ----
    // Post: es construído un objeto 'diccionario' con una única palabra, la 
    //       palabra vacía.
    // Errores: lanza un error si no hay memoria dinámica suficiente para crear
    //          un diccionario.
    diccionario() noexcept(false);


    
    // Constructora por copia, asignación y destructora.


    // Construye un diccionario que corresponde a una copia de otro 
    // diccionario ya existente.
    // Pre: ----
    // Post: es construído un objeto 'diccionario' que corresponde a una copia 
    //       de 'd'.
    // Errores: lanza un error si no hay memoria dinámica suficiente para crear
    //          un diccionario a partir de la copia de 'd'.
    diccionario(const diccionario& d) noexcept(false);


    // Copia el contenido de un 'diccionario' ya existente al parámetro 
    // implícito.
    // Pre: ----
    // Post: devuelve una referencia al parámetro implícito, que corresponde a 
    //       una copia de 'd'.
    // Errores: lanza un error si no hay memoria dinámica suficiente para 
    //          copiar los contenidos de 'd' al parámetro implícito.
    diccionario& operator=(const diccionario& d) noexcept(false);


    // Destruye el parámetro implícito.
    // Pre: ----
    // Post: el parámetro implícito es destruido.
    ~diccionario() noexcept;



    // Modificadoras


    // Inserta una palabra al parámetro implícito.
    // Pre: 'p' solo puede contener carácteres ASCII entre 'A' y 'Z'.
    // Post: si 'p' ya figuraba en el parámetro implícito, entonces no surge 
    //       ningún efecto. En caso contrario, 'p' es insertada.
    // Errores: lanza un error en caso que 'p' contenga algún carácter 
    //          invalido o si no hay memoria dinámica suficiente para añadir 
    //          'p'.
    void inserta(const string& p) noexcept(false);



    // Consultoras


    // Devuelve la palabra más larga del parámetro implícito y que es prefijo 
    // de un string dado.
    // Pre: 'p' solo puede contener carácteres ASCII del rango ['A', 'Z'].
    // Post: si 'p' es una palabra que forma parte del parámetro implícito, 
    //       devuelve dicha palabra. En caso contrario, devuelve el prefijo 
    //       más largo de 'p' y, si este tampoco existe, entonces devuelve el 
    //       string vacio.
    // Errores: lanza un error en caso que 'p' contenga algún carácter 
    //          inválido.
    string prefijo(const string& p) const noexcept(false);


    // Devuelve una lista de palabras del parámetro implícito que satisfacen 
    // un patrón especificado con un string (ver descripcion detallada al 
    // inicio del módulo).
    // Pre: 's' solo puede contener carácteres ASCII del rango 
    //      ['A', 'Z'] U {'*'}; 'l' es una lista vacía y corresponde a un 
    //      parámetro de salida.
    // Post: 'l' contiene todas las palabras del parámetro implíctio que 
    //       satisfacen el patrón 's' y está ordenada crecientemente.
    // Errores: lanza un error si 's' contiene algún carácter inválido.
    void satisfacen_patron(const string& s, list<string>& l) 
         const noexcept(false);

    
    // Dice si un diccionario es vacio o no. Un diccionario se considera vacio 
    // si solo contiene la palabra vacia.
    // Pre: ----
    // Post: devuelve cierto si el parámetro implícito es vacio. En caso 
    //       contrario, devuelve falso.
    bool es_vacio() const noexcept;



    // Entrada/salida


    // Lee el contenido de un diccionario a través de un canal de entrada.
    // Pre/entrada: el canal de entrada 'is' contiene una secuencia de palabras
    //              (strings) en español, acabada con el string "end" y cuyos 
    //              caracteres estan codificados en ASCII y forman parte del 
    //              rango ['A', 'Z'].
    // Post: se devuelve una referencia a 'is', cuyo contenido ha sido 
    //       transferido y almacenado en 'd'.
    // Errores: lanza un error si alguna palabra del canal de entrada 'is' 
    //          contiene algun carácter distinto de ['A', 'Z']. En estos casos,
    //          'd' queda intacto.
    friend istream& operator>>(istream& is, diccionario& d) noexcept(false);


    // Escribe el contenido de un diccionario a un canal de salida.
    // Pre: ----
    // Post: devuelve una referencia a 'os', que contiene todas las palabras 
    //       de 'd', cada una en una linea independiente y ordenadas 
    //       lexicográficamente.
    friend ostream& operator<<(ostream&, const diccionario& d) noexcept;

};


#endif