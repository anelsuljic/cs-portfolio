/** @file Pendientes.hh
    @brief Especificación de la clase Pendientes.
*/


#ifndef CLASS_PENDIENTES_HH
#define CLASS_PENDIENTES_HH

#include "Cluster.hh"
#include "Proceso.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <utility>
#include <map>
#include <list>
#endif

using namespace std;


/** @class Pendientes
    @brief Representa una área de procesos pendientes.

    Contiene una serie de prioridades diferentes, designadas con un identificador en formato string (solo letras y dígitos) y ordenadas crecientemente lexicográficamente. Cada prioridad puede contener una serie de procesos no nulos diferentes, ordenados decrecientemente por antigüedad. Todos los procesos de una área de espera permanecerán en esta hasta que sean enviados a ejecutarse a un procesador.
*/

class Pendientes {
  private:
    /** @brief Representa una prioridad.
    
        Contiene una lista de procesos pendientes, ordenada decrecientemente por antigüedad. Además contiene dos variables que representan, respectivamente, el número de procesos pendientes enviados con éxito a un clúster y el número de procesos rechazados (un mismo proceso cuenta tantas veces como rechazos haya sufrido).
    */
    struct Prioridad {
        /** @brief Lista de procesos pendientes.
        
            Ordenada decrecientemente por antigüedad.
        */
        list<Proceso> Procesos;
        /** @brief Número de procesos enviados con éxito a un clúster. */
        int enviados;
        /** @brief Número de procesos rechazados. */
        int rechazados;
    };
    /** @brief Área de procesos pendientes. 
    
        Ordenada crecientemente por identificadores de prioridad.
    */
    map<string, Prioridad> Area;


    // Invariante de representación:
    // - "enviados" >= 0.
    // - "rechazados" >= 0.
    // - "Procesos" no contiene procesos iguales (mismo identificador).
    // - "Area" no contiene prioridades con identificador igual.
    // - La clave del map "Area" corresponde al identificador de prioridad: 
    //   solo contiene letras y/o dígitos.


    /** @brief Consultora de la existencia de un proceso en una lista de procesos.
        \pre "id_proceso" es un identificador de un proceso.
        \post El resultado es cierto si, y solo si, "L" contiene un proceso con identificador igual a "id_proceso".
        \coste Lineal respecto al número de elementos de "L".
    */
    static bool existe_proceso(const list<Proceso> &L, int id_proceso);


  public:
    // Constructoras


    /** @brief Constructora por defecto.
        \pre Cierto.
        \post El resultado es una área de procesos pendientes vacía.
        \coste Constante.
    */
    Pendientes();


    // Modificadoras


    /** @brief Añade una nueva prioridad a l'área de procesos pendientes.
        \pre "id_prioridad" es un identificador de prioridad.
        \post Es añadida la prioridad con identificador "id_prioridad" al parámetro implícito si, y solo si, este no contiene ya dicha prioridad. En caso contrario, se imprime un mensaje de error. La prioridad añadida no tiene procesos pendientes.
        \coste Logarítmico respecto al número de prioridades del parámetro implícito, incluída la añadida.
    */
    void alta_prioridad(const string &id_prioridad);

    /** @brief Elimina una prioridad de l'área de procesos pendientes.
        \pre "id_prioridad" es un identificador de prioridad.
        \post Es eliminada la prioridad con identificador "id_prioridad" del parámetro implícito si, y solo si, este contiene dicha prioridad y esta no tiene procesos pendientes. En caso contrario, se imprime un mensaje de error indicando cual de las dos condiciones no se cumple.
        \coste Logarítmico respecto al número de prioridades del parámetro implícito.
    */
    void baja_prioridad(const string &id_prioridad);

    /** @brief Añade un nuevo proceso a una prioridad específica de l'área de procesos pendientes.
        \pre "id_prioridad" es un identificador de prioridad; "Proc" no es un proceso nulo.
        \post "Proc" es añadido a la prioridad con identificador "id_prioridad" del parámetro implícito si, y solo si, el parámetro implícito contiene dicha prioridad y esta no contiene un proceso igual a "Proc". En caso contrario, se imprime un mensaje de error indicando cual de las dos condiciones no se cumple.
        \coste Logarítmico respecto al número de prioridades del parámetro implícito. En el caso de que haya más procesos pendientes en la prioridad con identifcador "id_prioridad" que prioridades en el parámetro implícito, el coste es logarítmico respecto al número de procesos pendientes de dicha prioridad.
    */
    void alta_proceso(const string &id_prioridad, const Proceso &Proc);

    /** @brief Envia a un clúster una cantidad específica de procesos de l'área de procesos pendientes. 
        \pre "num" >= 0.
        \post Se intentan enviar "num" procesos del parámetro implícito a "Clust", por orden creciente de prioridad y, dentro de cada prioridad, por orden decreciente de antigüedad. Los intentos continuan hasta haber colocado los "num" procesos a "Clust" o hasta que no queden procesos pendientes al parámetro implícito o hasta que todos los que queden pendientes se hayan intentado colocar sin éxito. Todos los procesos que no se han podido colocar sin éxito cuentan como procesos rechazados y son devueltos a la misma prioridad como procesos nuevos. Los procesos que se han podido colocar con éxito cuentan como procesos enviados con éxito.
        \coste Lineal respecto al número total de procesos pendientes del parámetro implícito.
    */
    void enviar_procesos_cluster(Cluster &Clust, int num);


    // Lectura y escritura


    /** @brief Operación de lectura de l'área de procesos pendientes.
        \pre Hay preparados al canal estándar de entrada un número entero N más grande que cero, seguido de N identificadores (strings) de prioridades.
        \post Son leídos todos los identificadores de prioridades y guardados al parámetro implícito. Ninguna prioridad contiene procesos pendientes.
        \coste Lineal respecto al número de identficadores de prioridades del canal estándar de entrada.
    */
    void leer();

    /** @brief Operación de escritura de una prioridad específica de l'área de procesos pendientes.
        \pre "id_prioridad" es un identificador de prioridad.
        \post Són escritos al canal estándar de salida todos los datos de la prioridad con identificador "id_prioridad" si, y solo si, el parámetro implícito contiene dicha prioridad. En caso contrario, se imprime un mensaje de error. Los datos de la prioridad se escriben en el siguiente formato: primero son escritos todos los procesos por orden decreciente de antigüedad y, seguidamente, se escribe el número de procesos enviados con éxito a un clúster y el número de procesos rechazados.
        \coste Lineal respecto al número de procesos pendientes de la prioridad con identificador "id_prioridad" del parámetro implícito.
    */
    void escribir_prioridad(const string &id_prioridad) const;

    /** @brief Operación de escritura de l'área de procesos pendientes.
        \pre Cierto.
        \post Són escritas al canal estándar de salida todas las prioridades del parámetro implícito, por orden creciente de prioridad. Para cada prioridad, se escriben todos sus procesos por orden decreciente de antigüedad y, seguidamente, se escribe el número de procesos enviados con éxito a un clúster y el número de procesos rechazados.
        \coste Lineal respecto al número total de procesos pendientes del parámetro implícito.
    */
    void escribir() const;


};


#endif