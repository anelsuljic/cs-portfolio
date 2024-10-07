// Un objeto de la clase 'hueco' es una cuádrupla <fila, columna, orientacion, 
// longitud>, que sirve para identificar un hueco que forma parte de una 
// sopa de letras. La clase porporciona operaciones elementales para consultar 
// cada campo de la cuádrupla y sobrecarga el operador '<' para realizar 
// dichas comparaciones.


#ifndef _HUECO_HH
#define _HUECO_HH


#include <iostream>
#include "eda-util.hh"

#include "orientacion.hh"
using std::istream;
using util::nat;


class hueco {
  private:
    class impl_;
    impl_* rep_;

  public:

    // Constructoras


    // Construye un objeto 'hueco' a partir de la información que dicha 
    // cuádrupla necesita.
    // Pre: 'o' != 'NO_OR'.
    // Post: es construido un objeto 'hueco' con los valores 
    //       <fil, col, o, lon>. En caso que alguno de los campos no sea 
    //       proporcionado por el usuario, entonces dicho campo tomará su 
    //       valor por defecto, tal como está definido en la cabecera.
    hueco(nat fil = 0, nat col = 0, const orientacion& o = orientacion::H,
          nat lon = 0) noexcept(false);


    
    // Constructora por copia, asignación y destructora.

    
    // Construye un objeto 'hueco' que corresponde a una copia de uno ya 
    // existente.
    // Pre: ----
    // Post: es construido un objeto 'hueco' que corresponde a una copia de 
    //       'h'.    
    hueco(const hueco& h) noexcept(false);


    // Copia los contenidos de un objeto 'hueco' al parámetro implícito.
    // Pre: ----
    // Post: devuelve una referencia al parámetro implícito que corresponde a 
    //       una copia de 'h'.
    hueco& operator=(const hueco& h) noexcept(false);


    // Destruye el parámetro implícito.
    // Pre: ----
    // Post: el parámetro implícito es destruido.
    ~hueco() noexcept;



    // Consultoras


    // Devuelve la fila de la primera posición del hueco que representa el 
    // parámetro implícito.
    // Pre: ----
    // Post: devuelve la fila de la primera posición del hueco que 
    //       representa el parámetro implícito.
    nat fila() const noexcept;


    // Devuelve la columna de la primera posición del hueco que representa 
    // el parámetro implícito.
    // Pre: ----
    // Post: devuelve la columna de la primera posición del hueco que 
    //       representa el parámetro implícito.
    nat columna() const noexcept;


    // Devuelve la orientación del hueco que almacena el parámetro implícito.
    // Pre: ----
    // Post: devuelve la orientación del hueco que almacena el parámetro 
    //       implícito.
    orientacion orient() const noexcept;


    // Devuelve la longitud del hueco que que almacena el parámetro implícito.
    // Pre: ----
    // Post: devuelve la longitud del hueco que que almacena el parámetro 
    //       implícito.
    nat longitud() const noexcept;



    // Operadores de comparación

    
    // Comprueba si el parámetro implícito es más pequeño que otro objeto 
    // 'hueco' dado.
    // Pre: ----
    // Post: devuelve cierto si el parámetro implícito es más pequeño que 'h'. 
    //       La comparación se basa en primer lugar en la posición, el par 
    //       [fil, col]: dadas dos posiciones [i,j] e [i',j'], 
    //       ( [i,j] < [i',j'] ) si (i < i') o (i == i' y j < j'). En caso de 
    //       empate, el orden lo dictan las orientaciones (ver especificación 
    //       de la clase 'orientacion') y, en caso de empate de orientaciones, 
    //       el orden lo dicta la longitud. En caso que 'h' se más pequeño que 
    //       el parámetro implícito, devuelve falso.
    bool operator<(const hueco& h) const noexcept;



    // Entrada/salida

    
    // Lee el contenido de un 'hueco' a través de un canal de entrada.
    // Pre/entrada: 'is' contiene una cuádrupla <fila, columna, orientacion, 
    //              longitud> que corresponden a los elementos de un 'hueco'.
    //              'fila' y 'columna' son dos naturales más grandes o igual a 
    //              cero; 'longitud' es un natrual más grande que cero; 
    //              'orientacion' = {"H", "HR", "V", "VR", "D", "DR", "B", 
    //              "BR"}, es decir, un string cuyos valores pueden ser los 
    //              del conjunto anterior.
    // Post: devuelve una referencia a 'is', cuyo contenido ha sido 
    //       transferido y almacenado a 'h'.
    friend istream& operator>>(istream& is, hueco& h) noexcept(false);

};


#endif