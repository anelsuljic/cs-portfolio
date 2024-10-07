/** @file Pendientes.cc
    @brief Código de la classe Pendientes.
*/


#include "Pendientes.hh"


bool Pendientes::existe_proceso(const list<Proceso> &L, int id_proceso)
{
    bool res = false;
    list<Proceso>::const_iterator it = L.begin();
    
    // Realiza la búsqueda.
    while (not res and it != L.end()) {
        res = id_proceso == it -> consultar_id();
        ++it;
    }

    return res;
}

Pendientes::Pendientes()
{
    // No inicializamos nada, ya que l'área tiene que ser vacía.
}

void Pendientes::alta_prioridad(const string &id_prioridad)
{
    map<string, Prioridad>::const_iterator it = Area.lower_bound(id_prioridad);
    
    // Comprueba si existe la prioridad o no.
    if (it == Area.end() or it -> first != id_prioridad) {
        it = Area.insert(it, pair<string, Prioridad>(id_prioridad, {{}, 0, 0}));
    } else cout << "error: ya existe prioridad" << endl;
}

void Pendientes::baja_prioridad(const string &id_prioridad)
{
    map<string, Prioridad>::const_iterator it = Area.find(id_prioridad);
    
    // Comprueba si existe la prioridad o no.
    if (it != Area.end()) {
        // Comprueba si tiene procesos pendientes o no.
        if (it -> second.Procesos.empty()) it = Area.erase(it);    
        else cout << "error: prioridad con procesos" << endl;
    } else cout << "error: no existe prioridad" << endl;
}

void Pendientes::alta_proceso(const string &id_prioridad, const Proceso &Proc)
{
    map<string, Prioridad>::iterator it1 = Area.find(id_prioridad);
    
    // Comprueba si existe la prioridad o no.
    if (it1 != Area.end()) {
        // Comprueba si ya existe un proceso igual o no.
        if (not existe_proceso(it1 -> second.Procesos, Proc.consultar_id())) {
            it1 -> second.Procesos.insert(it1 -> second.Procesos.end(), Proc);
        } else cout << "error: ya existe proceso" << endl;
    } else cout << "error: no existe prioridad" << endl;
}

void Pendientes::enviar_procesos_cluster(Cluster &Clust, int num)
{
    // Saltamos todas las prioridades vacías.
    map<string, Prioridad>::iterator it1 = Area.begin();
    while (it1 != Area.end() and it1 -> second.Procesos.empty()) ++it1;
    
    // Iniciamos los intentos de envío.
    int contador1 = 0;
    while (contador1 < num and it1 != Area.end()) {
        int contador2 = 0;
        int size = it1 -> second.Procesos.size();
        list<Proceso>::const_iterator it2 = it1 -> second.Procesos.begin();

        // Intentamos enviar los procesos de la prioridad actual. Los procesos 
        // devueltos no se vuelven a intentar enviar.
        while (contador1 < num and contador2 < size) {
            bool rechazado;
            Clust.alta_proceso(*it2, rechazado);
            
            if (not rechazado) {
                ++it1 -> second.enviados;
                ++contador1;
            } else {
                list<Proceso>::const_iterator it3 = it1 -> second.Procesos.end();
                it1 -> second.Procesos.insert(it3, *it2);
                ++it1 -> second.rechazados;
            }

            it2 = it1 -> second.Procesos.erase(it2);
            ++contador2;
        }

        ++it1;
    }
}

void Pendientes::leer()
{
    int num;        // "num" > 0.
    cin >> num;
    
    // Lee los identificadores de prioridad.
    map<string, Prioridad>::const_iterator it;
    for (int i = 0; i < num; ++i) {
        string id_prioridad;
        cin >> id_prioridad;
        // Si en el canal estándar de entrada los identificadores de prioridad 
        // estan ordenados crecientemente, entonces podemos optimizar las 
        // inserciones. En caso contrario, la inserción será logarítmica, ya 
        // que tendrá que ordenar las prioridades.
        it = Area.insert(Area.end(), pair<string, Prioridad>(id_prioridad, {{}, 0, 0}));
    }
}

void Pendientes::escribir_prioridad(const string &id_prioridad) const
{
    map<string, Prioridad>::const_iterator it1 = Area.find(id_prioridad);
    
    // Comprueba si existe la prioridad o no.
    if (it1 != Area.end()) {
        // Escribe la prioridad.
        list<Proceso>::const_iterator it2 = it1 -> second.Procesos.begin();
        for (; it2 != it1 -> second.Procesos.end(); ++it2) it2 -> escribir();
        
        cout << it1 -> second.enviados << ' ' << it1 -> second.rechazados 
             << endl;
    } else cout << "error: no existe prioridad" << endl;
}

void Pendientes::escribir() const
{
    map<string, Prioridad>::const_iterator it1 = Area.begin();
    
    // Escribe el contenido de cada prioridad.
    for (; it1 != Area.end(); ++it1) {
        cout << it1 -> first << endl;
        
        list<Proceso>::const_iterator it2 = it1 -> second.Procesos.begin();
        for (; it2 != it1 -> second.Procesos.end(); ++it2) it2 -> escribir();
        
        cout << it1 -> second.enviados << ' ' << it1 -> second.rechazados 
             << endl;
    }
}