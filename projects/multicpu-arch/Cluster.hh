/** @file Cluster.hh
    @brief Especificación de la clase Cluster.
*/


#ifndef CLASS_CLUSTER_HH
#define CLASS_CLUSTER_HH

#include "Procesador.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include "BinTree.hh"
#endif

using namespace std;


/** @class Cluster
    @brief Representa un clúster.

    Contiene un número de procesadores variable, distribuidos en forma de árbol binario, con identificadores únicos. Contiene, como mínimo, un procesador y cada uno de ellos puede tener cero, uno o dos procesadores auxiliares.
*/

class Cluster {
  private:
    /** @brief Estructura del clúster.
    
        Representada en forma de árbol binario. Sus nodos corresponden a los identificadores de los procesadores del clúster.
    */
    BinTree<string> Estructura;
    /** @brief Map de procesadores del clúster.
    
        Ordenado crecientemente por identificadores de procesador.
    */
    map<string, Procesador> Procesadores;


    // Invariante de representación:
    // - "Estructura" no contiene elementos iguales.
    // - Los elementos de "Estructura" y la clave del map "Procesadores", al 
    //   ser identificadores de procesador, solo pueden contener letras y/o 
    //   dígitos.


    /** @brief Immersión del método "modificar_cluster".
        \pre Si "Estructura" contiene un identificador de procesador igual a "id_procesador", entonces el procesador correspondiente a este identificador no tiene procesos en ejecución; "Estructura" no tiene ningún nodo igual a alguno de "Estructura_subcluster".
        \post Si "Estructura" contiene un procesador con identificador "id_procesador", encontrado = true y el procesador es sustituído por "Estructura_subcluster" si, y solo si, este procesador no tiene procesadores auxiliares. En caso contrario, auxiliares = true. 
        \coste Lineal respecto al número de elementos de "Estructura".
    */
    static void i_modificar_cluster(BinTree<string> &Estructura, const BinTree<string> &Estructura_subcluster, const string &id_procesador, bool &encontrado, bool &auxiliares);

    /** @brief Immersión del método "leer".
        \pre Hay preparados al canal estándar de entrada una secuencia de procesadores (<string, tamaño_memoria>) diferentes, distribuidos en forma de árbol binario recorrido en preorden, con "marca" como marca centinela.
        \post Son leídos todos los procesadores del canal estandar de entrada y guardados en "Estructura" y "Procesadores". En "Estructura" se guardan los identificadores de los procesadores, manteniendo el orden del canal estándar de entrada, y en "Procesadores" se guardan los procesadores completos, ordenados por su identificador.
        \coste Lineal respecto al número de procesadores del canal estándar de entrada.
    */
    static void i_leer(BinTree<string> &Estructura, map<string, Procesador> &Procesadores, const string &marca);

    /** @brief Immersión del método "escribir_estructura"
        \pre Cierto.
        \post Es escrita al canal estándar de salida la representación de "Estructura". Es decir, son escritos todos sus elementos de acuerdo a la organización del árbol binário.
        \coste Lineal respecto al número de elementos de "Estructura".
    */
    static void i_escribir_estructura(const BinTree<string> &Estructura);


  public:
    // Constructoras


    /** @brief Constructora por defecto.
        \pre Cierto.
        \post El resultado es un clúster con un procesador estándar, sin procesos en ejecución.
        \coste Constante.
    */
    Cluster();


    // Modificadoras


    /** @brief Modificadora del clúster.
        \pre "id_procesador" es un identificador de un procesador; el parámetro implícito no contiene ningún procesador igual a algún procesador de "Subcluster".
        \post El procesador con identificador "id_procesador" es sustituído por "Subcluster" si, y solo si, el parámetro implícito contiene dicho procesador, el procesador no tiene procesos en ejecución y no tiene procesadores auxiliares. En caso contrario, se imprime un mensaje de error indicando cual de las tres condiciones no se cumple.
        \coste Lineal respecto al número de procesadores del parámetro implícito.
    */
    void modificar_cluster(const string &id_procesador, const Cluster &Subcluster);

    /** @brief Añade un nuevo proceso a ejecutarse a un procesador específico del clúster.
        \pre "id_procesador" es un identificador de un procesador; "Proc" no es un proceso nulo.
        \post "Proc" es añadido al procesador con identificador "id_procesador" del parámetro implícito si, y solo si, el parámetro implícito contiene dicho procesador, este no contiene ya un proceso igual a "Proc" y existe espacio suficiente a la memoria del procesador. En caso contrario, se imprime un mensaje de error indicando cuál de las tres condiciones no se cumple. El proceso ocupa la memoria del procesador a partir de la posición inicial más pequeña que deje el hueco más ajustado.
        \coste Logarítmico respecto al número de procesadores del parámetro implícito. 
    */
    void alta_proceso_procesador(const string &id_procesador, const Proceso &Proc);

    /** @brief Añade un nuevo proceso a ejecutarse al clúster.
        \pre "rechazado" es una variable de salida.
        \post "Proc" es añadido a uno de los procesadores del parámetro implícito si, y solo si, existe al menos un procesador que no contiene ya un proceso igual a "Proc" y, además, dispone de espacio suficiente en su memoria. Si "Proc" puede colocarse en más de un procesador, se designa el que disponga de un hueco más ajustado en su memoria. En caso de empate, se designa el que quede con más memoria libre. Si aún persiste el empate, se escoge el procesador que esté más cerca de la raíz del árbol binario y, si todavia es necesario desempatar, se escoge el que esté más a la izquierda.
        \coste Lineal respecto al número de procesadores del parámetro implícito.
    */
    void alta_proceso(const Proceso &Proc, bool &rechazado);

    /** @brief Elimina un proceso de un procesador específico del clúster.
        \pre "id_procesador" es un identificador de un procesador; "id_proceso" es un identificador de un proceso.
        \post El proceso con identificador "id_proceso" es eliminado del procesador con identificador "id_procesador" del parámetro implícito si, y solo si, el parámetro implícito contiene dicho procesador y este contiene dicho proceso. En caso contrario, se imprime un mensaje de error indicando cual de las dos condiciones no se cumple.
        \coste Logarítmico respecto al número de procesadores del parámetro implícito.
    */
    void baja_proceso_procesador(const string &id_procesador, int id_proceso);

    /** @brief Avanza el tiempo de todos los procesadores del clúster.
        \pre "tiempo" > 0.
        \post Todos los procesadores del parámetro implícito han avanzado "tiempo" unidades de tiempo. Los procesos cuyo tiempo de ejecución es más pequeño o igual a "tiempo" son eliminados. En caso contrario, los procesos restantes han progresado "tiempo" unidades de tiempo.
        \coste Lineal respecto al número total de procesos en ejecución del parámetro implícito.
    */
    void avanzar_tiempo(int tiempo);

    /** @brief Compacta la memoria de un procesador específico del clúster.
        \pre "id_procesador" es un identificador de un procesador.
        \post Se mueven todos los procesos del procesador con identificador "id_procesador" hacia el principio de su memoria (sin dejar huecos, sin solaparse y respetando el orden inicial) si, y solo si, el parámetro implícito contiene dicho procesador. En caso contrario, se imprime un mensaje de error.
        \coste Lineal respecto al número de procesos en ejecución del procesador con identificador "id_procesador" del parámetro implícito.
    */
    void compactar_memoria_procesador(const string &id_procesador);

    /** @brief Compacta la memoria de todos los procesadores del clúster.
        \pre Cierto.
        \post En cada procesador del parámetro implícito se mueven todos los procesos hacia el principio de la memoria, sin dejar huecos, sin solaparse y respetando el orden inicial.
        \coste Lineal respecto al número total de procesos en ejecución del parámetro implícito.
    */
    void compactar_memoria();
    

    // Lectura y escritura


    /** @brief Operación de lectura del clúster.
        \pre Hay preparados al canal estándar de entrada una secuencia de procesadores (<string, tamaño_memoria>) diferentes, distribuidos en forma de árbol binario recorrido en preorden, con "*" como marca centinela.
        \post Todos los procesadores del canal estándar de entrada son leídos y guardados al parámetro implícito, sin procesos en ejecución. Si el parámetro implícito ya contenía procesadores, estos dejan de existir, independientemente de si tenian procesos en ejecución o no.
        \coste Lineal respecto al número de procesadores del canal estándar de entrada.
    */
    void leer();

    /** @brief Operación de escritura de un procesador específico del clúster.
        \pre "id_procesador" es un identificador de un procesador.
        \post Son escritos al canal estándar de salida todos los datos del procesador con identificador "id_procesador" si, y solo si, el parámetro implícito contiene dicho procesador. En caso contrario, se imprime un mensaje de error. Los datos del procesador corresponden a todos los procesos en ejecución, que son escritos por orden creciente de primera posición de memoria, incluyendo dicha posición y el resto de datos del proceso.
        \coste Lineal respecto al número de procesos en ejecución del procesador con identificador "id_procesador" del parámetro implícito.
    */
    void escribir_procesador(const string &id_procesador) const;

    /** @brief Operación de escritura del clúster.
        \pre Cierto.
        \post Són escritos al canal estándar de salida todos los procesadores del parámetro implícito, ordenados crecientemente por identificador. Para cada procesador, se escribe su identificador y todos sus procesos en ejecución por orden creciente de primera posición de memoria, incluyendo dicha posición y el resto de datos del proceso.
        \coste Lineal respecto al número total de procesos en ejecución del parámetro implícito.
    */
    void escribir() const;

    /** @brief Operación de escritura de la estructura del clúster.
        \pre Cierto.
        \post Es escrita al canal estándar de salida la representación de la estructura del parámetro implícito. És decir, se escribe la organización del árbol binario de procesadores. Para cada procesador, solo se escribe su identificador.
        \coste Lineal respecto al número de procesadores del parámetro implícito.
    */
    void escribir_estructura() const;


};


#endif