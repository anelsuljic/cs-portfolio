// Una 'sopa_letras' almacena una matriz de M x N caracteres, los cuales solo
// pueden ser asteriscos ('*') o carácteres ASCII entre 'A' y 'Z'. El número 
// de filas y columnas están acotados, respectivamente (las operaciones 
// max_filas() y max_cols() devuelven el valor de dichas cotas). Las filas se 
// indexan de 0 a M-1 y las columnas de 0 a N-1. Si la sopa de letras se 
// construye mediante la constructora por defecto, entonces el número de filas 
// y columnas viene determinado por la operación 'inserta_fila': el número de 
// columnas viene determinado por la longitud del primer 'string' insertado y 
// el número de filas por el número de 'strings' insertados hasta el momento; 
// si no se han insertado filas, entonces ambos números son cero.



#ifndef _SOPA_LETRAS_HH
#define _SOPA_LETRAS_HH



#include <iostream>
#include <string>
#include "eda-util.hh"

#include "orientacion.hh"
using std::string;
using std::istream;
using std::ostream;
using util::nat;



class sopa_letras {
  private:
    class impl_;
    impl_* rep_;
  
  public:

    // Constructoras


    // Construye una 'sopa_letras' vacía, sin filas ni columnas.
    // Pre: ----
    // Post: es construido un objeto 'sopa_letras' sin filas ni columnas.
    // Errores: se produce un error si no hay memoria dinámica suficiente para 
    //          construir el objeto.
    sopa_letras() noexcept(false);


    // Construye una 'sopa_letras' vacía, con un número de filas y columnas
    // indicado.
    // Pre: (num_fil, num_col) == (0, 0), o bien, 
    //      0 < 'num_fil' <= max_filas() y 0 < 'num_col' <= max_cols().
    // Post: es construido un objeto 'sopa_letras' con 'num_fil' filas y 
    //       'num_col' columnas, cuyas celdas contienen asteriscos '*'. Si 
    //       (num_fil, num_col) == (0, 0), se llama automáticamente a la 
    //       constructora por defecto: sopa_letras().
    // Errores: se produce un error si no se cumple algún aspecto de la 
    //          precondicion. Puede producirse, además, un error si no hay 
    //          memoria dinámica suficiente para construir el objeto.
    sopa_letras(nat num_fil, nat num_col) noexcept(false);



    // Constructora por copia, asignación y destructora.


    // Construye una 'sopa_letras' a partir de una ya existente.
    // Pre: ----
    // Post: es construido un objeto 'sopa_letras' que corresponde a una copia
    //       de 's'.
    // Errores: se produce un error si no hay memoria dinámica suficiente para 
    //          construir el objeto.
    sopa_letras(const sopa_letras& s) noexcept(false);


    // Copia el contenido de una 'sopa_letras' al parámetro implícito.
    // Pre: ----
    // Post: devuelve una referencia al parámetro implícito, el cual 
    //       corresponde a una copia de 's'.
    // Errores: se produce un error si no hay memoria dinámica suficiente para 
    //          realizar la copia.
    sopa_letras& operator=(const sopa_letras& s) noexcept(false);


    // Destruye un objeto 'sopa_letras'.
    // Pre: ----
    // Post: el parámetro implícito es destruido.
    ~sopa_letras() noexcept;



    // Modificadoras



    // Inserta una fila al parámetro implícito, cuyos carácteres se indicarán
    // mediante un string.
    // Pre: 's' no es vacío y solo puede contener carácteres ASCII entre 'A' y 
    //      'Z', y el asterísco '*'. Si el parámetro implícito no tiene filas, 
    //      4 <= s.lenght() <= max_cols(). Si el parámetro implícito ya tiene 
    //      filas, num_filas() < max_filas() y s.lenght() == num_columnas().
    // Post: el parámetro implícito contiene una fila más, que es una copia de 
    //       's'.
    // Errores: se produce un error si no se cumple la precondicion. Se da 
    //          información sobre que condición especifica de la pre no se 
    //          cumple.
    void inserta_fila(const string& s) noexcept(false);


    // Añade los carácteres de un string al parámetro implícito, a partir de 
    // una posición inicial y una orientación dadas.
    // Pre: 'o' = {H, HR, V, VR, D, DR, B, BR}; num_filas() >= 4 o 
    //      num_columnas() >= 4. 0 <= fil < num_filas(); 
    //      0 <= col < num_columnas(); 's' solo contiene carácteres ASCII del 
    //      rango ['A', 'Z'] U {'*'}.
    // Post: los carácteres de 's' són insertados al parámetro implícito a 
    //       partir de la posición (fil, col) con orientación 'o'.
    // Errores: se produce un error si 's' no cabe al parámetro implícito 
    //          colocándolo a la posición inicial (fil, col) y 
    //          orientación 'o'; o bien si no se cumple algún aspecto de la 
    //          precondición.
    void inserta_cadena(const string& s, nat fil, nat col, 
                        const orientacion& o) noexcept(false);

    
    // Reemplaza cada asterísco de una 'sopa_letras' por un carácter ASCII 
    // entre 'A' y 'Z'.
    // Pre: ----
    // Post: todas las celdas del parámetro implícito que contienen un 
    //       asterísco han sido reemplazadas por un carácter ASCII entre 'A' y 
    //       'Z'.
    void reemplazar_asteriscos() noexcept;
    


    // Consultoras


    // Devuelve un string de una longitud concreta a partir de una posición 
    // inicial y orientación dadas.
    // Pre: 0 <= fil < num_filas(); 0 <= col < num_columnas();
    //      'o' = {H, HR, V, VR, D, DR, B, BR}; 'lon' ha de tener un valor que 
    //      permita obtener un string que comienza en (fil, col) y sigue la 
    //      orientacion 'o'.
    // Post: devuelve un string de longitud 'lon' que comienza en la posición 
    //       (fil, col) en la orientación 'o'.
    // Errores: se produce un error si no se cumple la precondición.
    string cadena(nat fil, nat col, nat lon, const orientacion& o) const 
           noexcept(false);

    
    // Devuelve el número de filas del parámetro implícito.
    // Pre: ----
    // Post: devuelve el número de filas del parámetro implícito.
    nat num_filas() const noexcept;


    // Devuelve el número de columnas del parámetro implícito.
    // Pre: ----
    // Post: devuelve el número de columnas del parámetro implícito.
    nat num_columnas() const noexcept;


    // Devuelve el número máximo de filas que una 'sopa_letras' puede tener.
    // Pre: ----
    // Post: devuelve el número máximo de filas que una 'sopa_letras' puede 
    //       tener.
    static nat max_filas() noexcept;


    // Devuelve el número máximo de columnas que una 'sopa_letras' puede tener.
    // Pre: ----
    // Post: devuelve el número máximo de columnas que una 'sopa_letras' puede 
    //       tener.
    static nat max_cols() noexcept;


    // Dice si una 'sopa_letras' es inicializada o no. Estar inicializada 
    // significa que todas las celdas corresponden a un carácter ASCII entre 
    // 'A' y 'Z'. Es decir, no puede haber ningún asterísco.
    // Pre: ----
    // Post: devuelve cierto si el parámetro implícito solo contiene 
    //       carácteres ASCII entre 'A' y 'Z', y ningún asterísco. En caso
    //       contrario, devuelve falso. Nota: una 'sopa_letras' sin filas ni 
    //       columnas no es inicializada.
    bool es_inicializada() const noexcept;



    // Entrada/salida


    // Lee el contenido de una 'sopa_letras'.
    // Pre/entrada: 's' es vacia, sin filas ni columnas; 'is' contiene un 
    //              natural 'num_s' más grande que cero, seguido de 'num_s' 
    //              strings, cuyos carácteres son ASCII del rango 
    //              ['A', 'Z'] U {'*'} y cuyo tamaño debe ser más grande o 
    //              igual a 4.
    // Post: 's' es igual a la sopa de letras representada en el canal de 
    //       entrada 'is' mediante strings.
    // Errores: se produce un error si alguno de los strings leídos no cumple 
    //          alguno de los requisitos de la precondición. En estos casos, 
    //          's' queda intacta.
    friend istream& operator>>(istream& is, sopa_letras& s) noexcept(false);


    // Imprime por un canal de salida una 'sopa_letras'
    // Pre: ----
    // Post: devuelve una referencia a 'os', que contiene impreso el contenido 
    //       de 's'.
    friend ostream& operator<<(ostream& os, const sopa_letras& s) noexcept;
    
};


#endif