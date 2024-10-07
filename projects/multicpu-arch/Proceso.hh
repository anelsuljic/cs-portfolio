/** @file Proceso.hh
    @brief Especificación de la clase Proceso.
*/


#ifndef CLASS_PROCESO_HH
#define CLASS_PROCESO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;


/** @class Proceso
    @brief Representa un proceso.

    Contiene un identificador en forma de entero no negativo. El resto de su información corresponde al tamaño que ocupa en memoria y a su tiempo de ejecución. Dispone, además, de dos estados: nulo o no nulo. Un proceso nulo es un proceso que solo ocupa espacio en memoria. No contiene ni identificador ni información sobre su tiempo de ejecución.

    Dos procesos son iguales si, y solo si, tienen el mismo identificador.
*/

class Proceso {
  private:
    /** @brief Identificador del proceso. */
    int id;
    /** @brief Tamaño del proceso. */
    int tam;
    /** @brief Tiempo de ejecución del proceso. */
    int teje;
    /** @brief Estado del procesador.
    
        Indica si es un proceso nulo o no.
    */
    bool nulo;


    // Invariante de representación:
    // "id" >= 0.
    // "tam" > 0.
    // "teje" > 0.
    // si "nulo", el proceso no tiene identificador ni tiempo de ejecución.


  public:
    // Constructoras
    
    
    /** @brief Constructora por defecto.
        \pre Cierto.
        \post El resultado es un proceso no nulo con identificador igual a 0, tamaño igual a 1 y tiempo de ejecución igual a 1.
        \coste Constante.
    */
    Proceso();

    /** @brief Constructora del proceso nulo.
        \pre "tam" > 0.
        \post El resultado es un proceso nulo con tamaño igual a "tam".
        \coste Constante.
    */
    Proceso(int tam);


    // Modificadoras


    /** @brief Avanza el tiempo del proceo.
        \pre El parámetro implícito no es un proceso nulo; "tiempo" es más pequeño que el tamaño del parámetro implícito.
        \post El parámetro implícito ha progresado "tiempo" unidades de tiempo.
        \coste Constante.
    */
    void avanzar_tiempo(int tiempo);


    // Consultoras


    /** @brief Consultora del estado del proceso.
        \pre Cierto.
        \post El resultado indica si el parámetro implícito es un proceso nulo o no.
        \coste Constante.
    */
    bool es_nulo() const;

    /** @brief Consultora del identificador del proceso.
        \pre El parámetro implícito no es un proceso nulo.
        \post El resultado es el identificador del parámetro implícito.
        \coste Constante.
    */
    int consultar_id() const;

    /** @brief Consultora del tamaño del proceso.
        \pre Cierto.
        \post El resultado es el tamaño del parámetro implícito.
        \coste Constante.
    */
    int consultar_memoria() const;

    /** @brief Consultora del tiempo de ejecución del proceso.
        \pre El parámetro implícito no es un proceso nulo.
        \post El resultado es el tiempo de ejecución del parámetro implícito.
        \coste Constante.
    */
    int consultar_tiempo() const;


    // Lectura y escritura


    /** @brief Operación de lectura del proceso.
        \pre El parámetro implícito no es un proceso nulo; hay preparados al canal estándar de entrada un entero no negativo, que representa el identificador de un proceso, y dos enteros positivos, que representan, respectivamente, el tamaño y el tiempo de ejecución de un proceso.
        \post Los atributos del canal estándar de entrada són leídos y asignados al parámetro implícito.
        \coste Constante. 
    */
    void leer();

    /** @brief Operación de escritura del proceso.
        \pre El parámetro implícito no es un proceso nulo.
        \post Son escritos al canal estándar de salida los atributos del parámetro implícito: su identificador, su tamaño y su tiempo se ejecución.
        \coste Constante.
    */
    void escribir() const;


};


#endif