// Un objeto de la clase 'match' es una cuádrupla <palabra, fila, columna, 
// orientacion>, que sirve para identificar una palabra que forma parte de una 
// sopa de letras. La clase porporciona operaciones elementales para consultar 
// cada campo de la cuádrupla y sobrecarga el operador '<' para realizar 
// dichas comparaciones.


#ifndef _MATCH_HH
#define _MATCH_HH


#include <iostream>
#include <string>
#include "eda-util.hh"

#include "orientacion.hh"
using std::string;
using std::istream;
using std::ostream;
using util::nat;


class match {
  private:
    class impl_;
    impl_* rep_;

  public:

    // Constructora


    // Construye un objeto 'match' a partir de la información que dicha 
    // cuádrupla necesita.
    // Pre: 'o' != 'NO_OR' y 'pal' debe contener carácteres ASCII entre 'A' y 
    //      'Z'.
    // Post: es construido un objeto 'match' con los valores 
    //       <pal, fil, col, o>. En caso que alguno de los campos no sea 
    //       proporcionado por el usuario, entonces dicho campo tomará su 
    //       valor por defecto, tal como está definido en la cabecera.
    match(const string& pal = "", nat fil = 0, nat col = 0,
          const orientacion& o = orientacion::H) noexcept(false);


    
    // Constructora por copia, asignación y destructora.

    
    // Construye un objeto 'match' que corresponde a una copia de uno ya 
    // existente.
    // Pre: ----
    // Post: es construido un objeto 'match' que corresponde a una copia de 
    //       'm'.
    match(const match& m) noexcept(false);


    // Copia los contenidos de un objeto 'match' al parámetro implícito.
    // Pre: ----
    // Post: devuelve una referencia al parámetro implícito que corresponde a 
    //       una copia de 'm'.
    match& operator=(const match& m) noexcept(false);


    // Destruye el parámetro implícito.
    // Pre: ----
    // Post: el parámetro implícito es destruido.
    ~match() noexcept;



    // Consultoras

    
    // Devuelve la palabra del parámetro implícito.
    // Pre: ---
    // Post: devuelve la palabra del parámetro implícito.
    string palabra() const noexcept;


    // Devuelve la fila de la primera posición de la palabra que almacena el 
    // parámetro implícito.
    // Pre: ----
    // Post: devuelve la fila de la primera posición de la palabra que 
    //       almacena el parámetro implícito.
    nat fila() const noexcept;


    // Devuelve la columna de la primera posición de la palabra que almacena 
    // el parámetro implícito.
    // Pre: ----
    // Post: devuelve la columna de la primera posición de la palabra que 
    //       almacena el parámetro implícito.
    nat columna() const noexcept;


    // Devuelve la orientación de la palabra que almacena el parámetro 
    // implícito.
    // Pre: ----
    // Post: devuelve la orientación de la palabra que almacena el parámetro 
    //       implícito.
    orientacion orient() const noexcept;
    


    // Operadores de comparación


    // Comprueba si el parámetro implícito és más pequeño que otro objeto
    // 'match'.
    // Pre: ----
    // Post: devuelve cierto si el parámetro implícito es más pequeño que 'm'. 
    //       Dicha comparación funciona de la siguiente manera: la comparación 
    //       se basa en primer lugar en el orden creciente alfabético de las 
    //       palabras; en caso de empate, el orden lo dicta la posición de 
    //       origen. Dadas dos posiciones [i,j] e [i',j'], ([i,j] < [i',j']) 
    //       si (i < i') o (i == i' y j < j'). En caso de empate de 
    //       posiciones, se tendrá en cuenta la comparación de orientaciones 
    //       (ver especificacion de la clase 'orientacion'). En caso que 'm' 
    //       sea más pequeño que el parámetro implícito, se devuelve falso.
    bool operator<(const match& m) const noexcept;

    
    // Comprueba si el parámetro implícito es más grande que otro objeto
    // 'match'.
    // Pre: ----
    // Post: devuelve cierto si el parámetro implícito es más grande que 'm'. 
    //       Dicha comparación funciona de la siguiente manera: la comparación 
    //       se basa en primer lugar en el orden creciente alfabético de las 
    //       palabras; en caso de empate, el orden lo dicta la posición de 
    //       origen. Dadas dos posiciones [i,j] e [i',j'], ([i,j] > [i',j']) 
    //       si (i > i') o (i == i' y j > j'). En caso de empate de 
    //       posiciones, se tendrá en cuenta la comparación de orientaciones 
    //       (ver especificacion de la clase 'orientacion'). En caso que 'm' 
    //       sea más grande que el parámetro implícito, se devuelve falso.
    bool operator>(const match& h) const noexcept;


    // Comprueba si el parámetro implícito es más pequeño o igual que otro 
    // objeto 'match'.
    // Pre: ----
    // Post: devuelve cierto si el parámetro implícito es más pequeño o igual 
    //       que 'm'. Dicha comparación funciona de la siguiente manera: la 
    //       comparación se basa en primer lugar en el orden creciente 
    //       alfabético de las palabras; en caso de empate, el orden lo dicta 
    //       la posición de origen. Dadas dos posiciones [i,j] e [i',j'], 
    //       ([i,j] <= [i',j']) si (i <= i') o (i == i' y j <= j'). En caso de 
    //       empate de posiciones, se tendrá en cuenta la comparación de 
    //       orientaciones (ver especificacion de la clase 'orientacion'). En 
    //       caso que 'm' sea más pequeño o igual que el parámetro implícito, 
    //       se devuelve falso.
    bool operator<=(const match& h) const noexcept;

    

    // Entrada/salida


    // Lee el contenido de un objeto 'match' de un canal de entrada concreto.
    // Pre/input: el canal de entrada 'is' contiene los siguientes elementos, 
    //            separados por un espacio: un string de carácteres ASCII 
    //            entre 'A' y 'Z', un natural representando el número de fila, 
    //            un natural representando el número de columna, y una 
    //            orientacion especificada como un string, cuyo valor debe ser 
    //            del conjunto {"H", "HR", "V", "VR", "D", "DR", "B", "BR"}.
    // Post: devuelve una referencia a 'is', cuyo contenido se ha leido y 
    //       almacenado a 'm'.
    friend istream& operator>>(istream& is, match& m) noexcept;


    // Imprime el contenido de un objeto 'match' a un canal de salida concreto.
    // Pre: ----
    // Post: devuelve una referencia a 'os', que contiene impreso el contenido 
    //       de 'm', es decir, la cuadrupla <palabra, fila, columna, 
    //       orientacion>, donde cada elemento es separado por un espacio.
    friend ostream& operator<<(ostream& os, const match& m) noexcept;
};


#endif