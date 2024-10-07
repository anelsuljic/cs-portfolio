/** @file Cluster.cc 
    @brief Código de la clase Cluster.
*/


#include "Cluster.hh"


void Cluster::i_modificar_cluster(
    BinTree<string> &Estructura, const BinTree<string> &Estructura_subcluster, 
    const string &id_procesador, bool &encontrado, bool &auxiliares
)
{
    if (not Estructura.empty()) { 
        if (Estructura.value() == id_procesador and Estructura.left().empty() 
            and Estructura.right().empty()) {
            Estructura = Estructura_subcluster;
            encontrado = true;
        } else if (Estructura.value() == id_procesador) {
            encontrado = auxiliares = true;
        } else {
            BinTree<string> left = Estructura.left();
            i_modificar_cluster(left, Estructura_subcluster, id_procesador, 
                                encontrado, auxiliares);
            // HI1: Si "left" contiene un procesador con identificador 
            // "id_procesador" y este procesador no contiene procesadores 
            // auxiliares, entonces es sustituído por "Estructura_subcluster" y 
            // encontrado = true. Si "left" contiene el procesador, pero este 
            // tiene auxiliares, entonces no es sustituído y encontrado = true 
            // y auxiliares = true.

            BinTree<string> right = Estructura.right();
            if (not encontrado) {
                i_modificar_cluster(right, Estructura_subcluster, 
                                    id_procesador, encontrado, auxiliares);
                // H1: "right" contiene un procesador con identificador 
                // "id_procesador". Si este procesador no contiene procesadores 
                // auxiliares, entonces es sustituído por 
                // "Estructura_subcluster" y encontrado = true. En caso 
                // contrario, el procesador no es sustituído y encontrado = 
                // true y auxiliares = true.
            }

            Estructura = BinTree<string>(Estructura.value(), left, right);
        }
    }
}

void Cluster::i_leer(
    BinTree<string> &Estructura, map<string, Procesador> &Procesadores, const 
    string &marca
)
{
    string id_procesador;
    cin >> id_procesador;
    if (id_procesador != marca) {
        int tam_memoria;
        cin >> tam_memoria;

        Procesadores.insert(pair<string, Procesador>(id_procesador, Procesador(id_procesador, tam_memoria)));
        
        BinTree<string> left;
        i_leer(left, Procesadores, marca);
        // HI1: "left" contiene el procesador auxiliar izquierdo como raíz, y 
        // esta raíz puede tener o no procesadores auxiliares. "Procesadores" 
        // contiene todos los procesadores leídos del subárbol izquierdo.
        
        BinTree<string> right;
        i_leer(right, Procesadores, marca);
        // HI1: "right" contiene el procesador auxiliar derecho como raíz, y 
        // esta raíz puede tener o no procesadores auxiliares. "Procesadores" 
        // contiene todos los procesadores leídos del subárbol derecho.

        Estructura = BinTree<string>(id_procesador, left, right);
    }
}

void Cluster::i_escribir_estructura(const BinTree<string> &Estructura)
{
    if (Estructura.empty()) cout << ' ';
    else {
        cout << '(' << Estructura.value();

        i_escribir_estructura(Estructura.left());
        // HI1: es escrita la estructura del subárbol izquierdo.

        i_escribir_estructura(Estructura.right());
        // HI2: es escrita la estructura del subárbol derecho.

        cout << ')';
    }
}

Cluster::Cluster()
{
    // El clúster solo contiene un procesador estándar sin procesos en 
    // ejecución.
    Estructura = BinTree<string>(Procesador().consultar_id());
    Procesadores.insert(pair<string, Procesador>(Procesador().consultar_id(), Procesador()));
}

void Cluster::modificar_cluster(const string &id_procesador, const Cluster &Subcluster)
{
    map<string, Procesador>::const_iterator it;
    it = Procesadores.find(id_procesador);

    // Comprueba si el procesador existe o no.
    if (it != Procesadores.end()) {
        // Comprueba si el procesador tiene procesos o no.
        if (not it -> second.tiene_procesos()) {
            bool encontrado = false;
            bool auxiliares = false;
            i_modificar_cluster(Estructura, Subcluster.Estructura, 
                                id_procesador, encontrado, auxiliares);
            
            // Comprueba si el procesador tiene procesadores auxiliares.
            if (not auxiliares) {
                // Actualiza el map de procesadores.
                it = Procesadores.erase(it);
                
                it = Subcluster.Procesadores.begin();
                for(; it != Subcluster.Procesadores.end(); ++it) {
                    Procesadores.insert(*it);
                }
            } else cout << "error: procesador con auxiliares" << endl;
        } else cout << "error: procesador con procesos" << endl;
    } else cout << "error: no existe procesador" << endl;
}

void Cluster::alta_proceso_procesador(
    const string &id_procesador, const Proceso &Proc
)
{
    map<string, Procesador>::iterator it = Procesadores.find(id_procesador);
    
    // Comprueba si el procesador existe o no.
    if (it != Procesadores.end()) {
        // Comprueba si el procesador ya contiene "Proc" o no.
        if (not it -> second.contiene_proceso(Proc.consultar_id())) {
            // Comprueba si existe espacio suficiente en la memoria del 
            // procesador o no.
            pair<int, int> pos = {-1, -1};
            // Si el tamaño de "Proc" es más grande que la memoria libre 
            // disponible, no buscamos el hueco.
            if (Proc.consultar_memoria() <= it -> second.consultar_memoria_libre()) {
                pos = it -> second.existe_espacio(Proc.consultar_memoria());
            }

            if (pos.first != -1 and pos.second != -1) {
                it -> second.alta_proceso(pos, Proc);
            } else cout << "error: no cabe proceso" << endl;
        } else cout << "error: ya existe proceso" << endl;
    } else cout << "error: no existe procesador" << endl;
}

void Cluster::alta_proceso(const Proceso &Proc, bool &rechazado)
{
    queue<BinTree<string> > C;
    C.push(Estructura);
    pair<int, int> pos(-1, -1);
    map<string, Procesador>::iterator it;
    
    // Recorre la estructura del clúster por niveles.
    while (not C.empty()) {
        map<string, Procesador>::iterator it2;
        it2 = Procesadores.find(C.front().value());
        if (it2 != Procesadores.end() and 
            not it2 -> second.contiene_proceso(Proc.consultar_id()) and 
            Proc.consultar_memoria() <= it2 -> second.consultar_memoria_libre()) {
            pair<int, int> act;
            act = it2 -> second.existe_espacio(Proc.consultar_memoria());
            if (act.first != -1 and act.second != -1) {
                if ((pos.first == -1 and pos.second == -1) or 
                    (act.first < pos.first) or (act.first == pos.first and 
                    it2 -> second.consultar_memoria_libre() > it -> second.consultar_memoria_libre())) {
                    pos.first = act.first;
                    pos.second = act.second;
                    it = it2;
                }
            }
        }

        if (not C.front().left().empty()) C.push(C.front().left());
        if (not C.front().right().empty()) C.push(C.front().right());
        C.pop();
    }

    // Inserta "Proc" al procesador elegido.
    if (pos.first != -1 and pos.second != -1) {
        rechazado = false;
        it -> second.alta_proceso(pos, Proc);
    } else rechazado = true;
}

void Cluster::baja_proceso_procesador(
    const string &id_procesador, int id_proceso
)
{
    map<string, Procesador>::iterator it = Procesadores.find(id_procesador);
    
    // Comprueba si el procesador existe o no.
    if (it != Procesadores.end()) {
        // Si el procesador contiene el proceso, entonces este es eliminado. Si 
        // no, "existe" es falso.
        bool existe;
        it -> second.baja_proceso(id_proceso, existe);
        if (not existe) cout << "error: no existe proceso" << endl;
    } else cout << "error: no existe procesador" << endl;
}

void Cluster::avanzar_tiempo(int tiempo)
{
    map<string, Procesador>::iterator it = Procesadores.begin();
    for (; it != Procesadores.end(); ++it) {
        // Avanza el tiempo de todos los procesos en ejecución, si existen.
        if (it -> second.tiene_procesos()) it -> second.avanzar_tiempo(tiempo);
    }
}

void Cluster::compactar_memoria_procesador(const string &id_procesador)
{
    map<string, Procesador>::iterator it = Procesadores.find(id_procesador);
    
    // Comprueba si el procesador existe o no.
    if (it != Procesadores.end()) {
        // Compacta la memoria del procesador, si existen procesos.
        if (it -> second.tiene_procesos()) it -> second.compactar_memoria();
    }
    else cout << "error: no existe procesador" << endl;
}

void Cluster::compactar_memoria()
{
    map<string, Procesador>::iterator it = Procesadores.begin();
    for(; it != Procesadores.end(); ++it) {
        // Compacta la memoria del procesador actual, si existen procesos.
        if (it -> second.tiene_procesos()) it -> second.compactar_memoria();
    }
}

void Cluster::leer()
{
    // Elimina los procesadores antiguos.
    Procesadores.clear();
    // Lee los nuevos datos.
    i_leer(Estructura, Procesadores, "*");
}

void Cluster::escribir_procesador(const string &id_procesador) const
{
    map<string, Procesador>::const_iterator it;
    it = Procesadores.find(id_procesador);

    // Comprueba si el procesador existe o no.
    if (it != Procesadores.end()) it -> second.escribir();
    else cout << "error: no existe procesador" << endl;
}

void Cluster::escribir() const
{
    map<string, Procesador>::const_iterator it = Procesadores.begin();
    for (; it != Procesadores.end(); ++it) {
        // Escribe los datos del procesador: su identificador seguido de su 
        // contenido.
        cout << it -> first << endl;
        it -> second.escribir();
    }
}

void Cluster::escribir_estructura() const
{
    i_escribir_estructura(Estructura);
    cout << endl;
}