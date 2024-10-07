/** @file Procesador.cc
    @brief Código de la clase Procesador.
*/


#include "Procesador.hh"


bool Procesador::Hueco::operator<(const Hueco &H) const
{
    bool res = false;
    // Comprueba si los tamaños son iguales o no.
    if (tam == H.tam) res = pos_ini < H.pos_ini;
    else res = tam < H.tam;

    return res;
}

void Procesador::baja_proceso_memoria(map<int, Proceso>::iterator &it, int &pos_ini, int &tam)
{        
    // Eliminamos el proceso de la memoria y sus huecos adyacentes (estos dejan 
    // de estar disponibles, es decir, se elimina su información).
    if (it == Mem.begin()) {
        if (it != Mem.end()) it = Mem.erase(it);
        
        if (it != Mem.end() and it -> second.es_nulo()) {
            tam += it -> second.consultar_memoria();
            
            // Eliminamos el hueco de "Huecos".
            Huecos.erase({it -> second.consultar_memoria(), it -> first});
            // Eliminamos el hueco de "Mem".
            it = Mem.erase(it);
        }
    } else if (it == --Mem.end()) {
        if (it != Mem.begin()) --it;
        
        if (it -> second.es_nulo()) {
            pos_ini = it -> first;
            tam += it -> second.consultar_memoria();
            
            // Eliminamos el hueco de "Huecos".
            Huecos.erase({it -> second.consultar_memoria(), it -> first});
            // Eliminamos el hueco de "Mem".
            if (it != Mem.end()) it = Mem.erase(it);
        } else ++it;
        
        if (it != Mem.end()) it = Mem.erase(it);
    } else {
        if (it != Mem.begin()) --it;
        
        if (it -> second.es_nulo()) {
            pos_ini = it -> first;
            tam += it -> second.consultar_memoria();
            
            // Eliminamos el hueco de "Huecos".
            Huecos.erase({it -> second.consultar_memoria(), it -> first});
            // Eliminamos el hueco de "Mem".
            if (it != Mem.end()) it = Mem.erase(it);
        } else ++it;
        
        if (it != Mem.end()) it = Mem.erase(it);
        
        if (it != Mem.end() and it -> second.es_nulo()) {
            tam += it -> second.consultar_memoria();
            
            // Eliminamos el hueco de "Huecos".
            Huecos.erase({it -> second.consultar_memoria(), it -> first});
            // Eliminamos el hueco de "Mem".
            if (it != Mem.end()) it = Mem.erase(it);
        }
    }
}

Procesador::Procesador()
{
    id = "";
    tam = 1;
    ocup = 0;
    Mem.insert(pair<int, Proceso>(0, Proceso(tam)));
    Huecos.insert({tam, 0});
}

Procesador::Procesador(const string &id, int tam)
{
    this -> id = id;
    this -> tam = tam;
    ocup = 0;
    Mem.insert(pair<int, Proceso>(0, Proceso(this -> tam)));
    Huecos.insert({this -> tam, 0});
}

void Procesador::alta_proceso(const pair<int, int> &pos, const Proceso &Proc)
{
    // Añadimos la información de "Proc" a "Procesos" y actualizamos "ocup".
    Procesos.insert(pair<int, int>(Proc.consultar_id(), pos.second));
    ocup += Proc.consultar_memoria();

    // Eliminamos el hueco libre de la memoria y su información.
    Huecos.erase({pos.first, pos.second});
    map<int, Proceso>::const_iterator it1;
    // Miramos si el hueco libre está al principio o al final de la memoria 
    // (mayor eficiencia, ya que, si se cumple una de estas dos condiciones, no 
    // hace falta hacer una búsqueda al map, que tiene coste logarítmico). En 
    // cualquiera de los tres casos, "it1" apunta siempre a un elemento 
    // existente del map, ya que este tiene como mínimo un elemento.
    if (pos.second == 0) it1 = Mem.erase(Mem.begin());
    else if (tam - pos.first == pos.second) it1 = Mem.erase(--Mem.end());
    else {
        it1 = Mem.find(pos.second);
        it1 = Mem.erase(it1);
    }
    // Añadimos "Proc" a la memoria.
    it1 = Mem.insert(it1, pair<int, Proceso>(pos.second, Proc));

    // Añadimos un nuevo hueco si sobran posiciones libres del hueco ocupado 
    // por "Proc".
    int tam_proceso = Proc.consultar_memoria();
    if (tam_proceso < pos.first) {
        ++it1;
        // Es correcto incrementar "it1", ya que, previamente al incremento, 
        // este apunta al nuevo proceso añadido.
        int nuevo_hueco = pos.first - tam_proceso;
        int pos_ini = pos.second + tam_proceso;
        it1 = Mem.insert(it1, pair<int, Proceso>(pos_ini, Proceso(nuevo_hueco)));
        Huecos.insert({nuevo_hueco, pos_ini});
    }
}

void Procesador::baja_proceso(int id_proceso, bool &existe)
{
    map<int, int>::const_iterator it1 = Procesos.find(id_proceso);
    if (it1 != Procesos.end()) {
        existe = true;

        // Elimina el proceso y sus huecos adyacentes.
        map<int, Proceso>::iterator it2;
        if (it1 -> second == 0) it2 = Mem.begin();
        else it2 = Mem.find(it1 -> second);
        int pos_ini = it2 -> first;
        int tam = it2 -> second.consultar_memoria();
        baja_proceso_memoria(it2, pos_ini, tam);
        // "tam" y "pos_ini" contienen, respectivamente, el tamaño y la 
        // posición inicial de memoria del hueco libre que queda tras eliminar 
        // el proceso.

        // Insertamos el hueco libre a la memoria y a guardamos la información 
        // del nuevo hueco.
        Huecos.insert({tam, pos_ini});
        it2 = Mem.insert(it2, pair<int, Proceso>(pos_ini, Proceso(tam)));
        
        // Eliminamos el resto de información del proceso.
        ocup -= tam;
        it1 = Procesos.erase(it1);       
    } else existe = false;
}

void Procesador::avanzar_tiempo(int tiempo)
{
    map<int, Proceso>::iterator it1 = Mem.begin();
    for(; it1 != Mem.end(); ++it1) {
        // Los huecos los saltamos.
        if (not it1 -> second.es_nulo()) {
            // Eliminamos el proceso si ya ha terminado.
            if (it1 -> second.consultar_tiempo() <= tiempo) {
                ocup -= it1 -> second.consultar_memoria();
                Procesos.erase(it1 -> second.consultar_id());
                int pos_ini = it1 -> first;
                int tam = it1 -> second.consultar_memoria();
                baja_proceso_memoria(it1, pos_ini, tam);
                
                // Insertamos el hueco libre a la memoria y a "Huecos".
                it1 = Mem.insert(it1, pair<int, Proceso>(pos_ini, Proceso(tam)));
                Huecos.insert({tam, pos_ini});
            } else it1 -> second.avanzar_tiempo(tiempo);
        }
    }
}

void Procesador::compactar_memoria()
{
    int pos_ini = 0;
    map<int, Proceso>::const_iterator it1 = Mem.begin();
    
    // Compactamos la memoria.
    while (it1 != Mem.end()) {
        // Eliminamos los huecos nulos. No movemos los procesos que ya tienen 
        // la posición inicial igual a "pos_ini".
        if (it1 -> second.es_nulo()) {
            Huecos.erase({it1 -> second.consultar_memoria(), it1 -> first});
            it1 = Mem.erase(it1);
        } else {
            Procesos[it1 -> second.consultar_id()] = pos_ini;
            Proceso Aux = it1 -> second;
            it1 = Mem.erase(it1);
            it1 = Mem.insert(it1, pair<int, Proceso>(pos_ini, Aux));
            pos_ini += Aux.consultar_memoria();
            ++it1;
        }
    }
    
    // Añadimos un hueco libre al final de la memoria, si esta no está ocupada 
    // del todo.
    if (ocup != tam) {
        Huecos.insert({tam - ocup, pos_ini});
        it1 = Mem.insert(it1, pair<int, Proceso>(pos_ini, Proceso(tam - ocup)));
    }
}

string Procesador::consultar_id() const
{
    return id;
}

bool Procesador::tiene_procesos() const
{
    return not Procesos.empty();
}

bool Procesador::contiene_proceso(int id_proceso) const
{
    return Procesos.find(id_proceso) != Procesos.end();
}

pair<int, int> Procesador::existe_espacio(int tam) const
{
    int hueco = -1;
    int pos_ini = -1;
    
    // Comprueba si existe un hueco mayor o igual a "tam".
    set<Hueco>::const_iterator it = Huecos.lower_bound({tam, 0});
    if (it != Huecos.end()) {
        hueco = it -> tam;
        pos_ini = it -> pos_ini;
    }

    return pair<int, int>(hueco, pos_ini);
}

int Procesador::consultar_memoria_libre() const
{
    return tam - ocup;
}

void Procesador::escribir() const
{
    map<int, Proceso>::const_iterator it = Mem.begin();
    
    // Escribe todos los procesos en ejecución.
    for (; it != Mem.end(); ++it) {
        if (not it -> second.es_nulo()) {
            cout << it -> first << ' ';
            it -> second.escribir();
        }
    }
}