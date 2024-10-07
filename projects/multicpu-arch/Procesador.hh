/** @file Procesador.hh
    @brief Especificación de la clase Procesador.
*/


#ifndef CLASS_PROCESADOR_HH
#define CLASS_PROCESADOR_HH

#include "Proceso.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <set>
#endif

using namespace std;


/** @class Procesador
    @brief Representa un procesador.

    Contiene un identificador en formato string (solo letras y dígitos) y una memoria de tamaño más grande que cero, indexada desde 0. Conoce en todo momento que procesos está ejecutando y que posiciones de memoria ocupan. En cualquier instante, puede tener procesos en ejecución. Todos los procesos se colocan en el hueco más ajustado de la memoria que esté más cerca de la primera posición de memoria. No puede haber procesos iguales.
*/

class Procesador {
  private:
    /** @brief Identificador del procesador. */
    string id;
    /** @brief Tamaño de la memoria del procesador. */
    int tam;
    /** @brief Número de posiciones ocupadas de la memoria del procesador. */
    int ocup;
    /** @brief Memoria del procesador.
    
        Ordenada crecientemente por las posiciones iniciales de memoria. El valor asociado corresponde al proceso en ejecución. Los huecos libres se representan con procesos nulos.
    */
    map<int, Proceso> Mem;
    /** @brief Información de procesos en ejecución del procesador.
    
        Map ordenado crecientemente por identificadores de proceso. El valor asociado corresponde a la posicion inicial de memoria que ocupa dicho proceso.
    */
    map<int, int> Procesos;
    /** @brief Representa un hueco libre en la memoria del procesador.
    
        Contiene la información de un hueco libre de la memoria del procesador. 
    */
    struct Hueco {
        /** @brief Tamaño del hueco. */
        int tam;
        /** @brief Posición inicial de memoria del hueco. */
        int pos_ini;

        /** @brief Operador de desigualdad entre dos huecos.
            \pre Cierto.
            \post El resultado es cierto si, y solo si, el tamaño del parámetro implícito es más pequeño que el de "H". En caso contrario, el resultado es falso. En caso de empate entre tamaños, el resultado es cierto si, y solo si, la posición inicial de memoria del parámetro implícito es más pequeña que la de "H".
            \coste Constante.
        */
        bool operator<(const Hueco &H) const;
    };
    /** @brief Huecos libres de la memoria del procesador.
    
        Conjunto ordenado crecientemente por tamaño de los huecos. En caso de empate entre tamaños, el orden es creciente según la posición inicial de memoria de los huecos.
    */
    set<Hueco> Huecos;


    // Invariante de representación:
    // - "id" solo contiene letras y/o dígitos.
    // - "tam" > 0.
    // - "ocup" >= 0.
    // - "Mem" y "Procesos" no contienen procesos iguales (mismo identificador).
    // - La clave del map "Mem" es un entero más grande o igual a cero.


    /** @brief Elimina un proceso y sus huecos adyacentes de la memoria del procesador.
        \pre "it" apunta al proceso a eliminar; "pos_ini" y "tam" contienen, respectivamente, la posición inicial de memoria y el tamaño del proceso a eliminar.
        \post Son eliminados de la memoria del parámetro implícito el proceso apuntado por "it" y sus huecos adyacentes, si existen; "it" apunta al siguiente proceso en ejecución o al final de la memoria; "pos_ini" y "tam" contienen, respectivamente, la posición inicial de memoria y el tamaño del nuevo hueco libre en la memoria (creado al eliminar el proceso y sus huecos adyacentes).
        \coste Logarítmico respecto al número de huecos disponibles en la memoria del parámetro implícito.
    */
    void baja_proceso_memoria(map<int, Proceso>::iterator &it, int &pos_ini, int &tam);


  public:
    // Constructoras


    /** @brief Constructora por defecto.
        \pre Cierto.
        \post El resultado es un procesador estándar: no tiene identificador y su memoria es de tamaño igual a 1. No tiene procesos en ejecución.
        \coste Constante.
    */
    Procesador();

    /** @brief Constructora con identificador y tamaño de memoria explícitos.
        \pre "id" es un identificador de un procesador y "tam" > 0.
        \post El resultado es un procesador con identificador "id" y una memoria con tamaño "tam". No tiene procesos en ejecución.
        \coste Constante.
    */
    Procesador(const string &id, int tam);


    // Modificadoras


    /** @brief Añade un nuevo proceso al procesador.
        \pre El parámetro implícito no contiene un proceso igual a "Proc" y existe espacio suficiente en la memoria (equivalente a la siguiente condición: "pos" != <-1, -1>).
        \post "Proc" pasa a ejecutarse al parámetro implícito, ocupando las posiciones de memoria necesarias del hueco de tamaño "pos.first" de la memoria, a partir de la posición inicial que indica "pos.second".
        \coste Logarítmico respecto al número de procesos en ejecución (incluyendo el añadido) del parámetro implícito.
    */
    void alta_proceso(const pair<int, int> &pos, const Proceso &Proc);

    /** @brief Elimina un proceso del procesador.
        \pre "id_proceso" es un identificador de un proceso; "existe" es una variable de salida.
        \post El proceso con identificador "id_proceso" es eliminado del parámetro implícito si, y solo si, este contiene dicho proceso (en este caso, "existe" es cierto). En caso contrario, no se elimina ningún proceso y "existe" es falso.
        \coste Logarítmico respecto al número de procesos en ejecución del parámetro implícito.
    */
    void baja_proceso(int id_proceso, bool &existe);

    /** @brief Avanza el tiempo del procesador.
        \pre "tiempo" > 0.
        \post Todos los procesos cuyo tiempo de ejecución es menor o igual a "tiempo", son eliminados del parámetro implícito. Los procesos restantes han progresado "tiempo" unidades de tiempo.
        \coste Lineal respecto al número de procesos en ejecución del parámetro implícito.
    */
    void avanzar_tiempo(int tiempo);

    /** @brief Compacta la memoria del procesador.
        \pre Cierto.
        \post Se mueven todos los procesos del parámetro implícito hacia el principio de su memoria, sin dejar huecos, sin solaparse y respetando el orden inicial.
        \coste Lineal respecto al número de procesos en ejecución del parámetro implícito.
    */
    void compactar_memoria();


    // Consultoras


    /** @brief Consultora del identificador del procesador.
        \pre Cierto.
        \post El resultado es el identificador del parámetro implícito.
        \coste Constante.
    */
    string consultar_id() const;

    /** @brief Consultora de la existencia de procesos en ejecución en el procesador.
        \pre Cierto.
        \post El resultado indica si el parámetro implícito tiene procesos en ejecución o no.
        \coste Constante.
    */
    bool tiene_procesos() const;

    /** @brief Consultora de la existencia de un proceso específico en el procesador.
        \pre "id_procesador" es un identificador de un proceso.
        \post El resultado indica si el parámetro implícito contiene un proceso con identificador "id_proceso" o no.
        \coste Logarítmico respecto al número de procesos del parámetro implícito.
    */
    bool contiene_proceso(int id_proceso) const;

    /** @brief Consultora de la existencia de espacio disponible en la memoria del procesador.
        \pre "tam" es el tamaño de un proceso.
        \post Si existe un hueco disponible más grande o igual a "tam" en la memoria del parámetro implícito, el resultado es el par <hueco, pos_ini>, donde "hueco" es el tamaño del hueco disponible y "pos_ini" la primera posición de memoria de este hueco. Si existen varios huecos disponibles, se selecciona el más ajustado a "tam" y, si existen empates, el que se sitúe más cerca de la primera posición de la memoria del parámetro implícito.
        \coste Logarítmico respecto al número de huecos disponibles.
    */
    pair<int, int> existe_espacio(int tam) const;

    /** @brief Consultora del espacio libre en la memoria del procesador.
        \pre Cierto.
        \post El resultado es el número de posiciones libres de la memoria del parámetro implícito.
        \coste Constante.
    */
    int consultar_memoria_libre() const;


    // Lectura y escritura


    /** @brief Operación de escritura del procesador.
        \pre Cierto.
        \post Son escritos al canal estándar de salida todos los procesos en ejecución del parámetro implícito por orden creciente de primera posición de memoria, incluyendo dicha posición y el resto de datos del proceso.
        \coste Lineal respecto al número de procesos en ejecución del parámetro implícito.
    */
    void escribir() const;


};


#endif