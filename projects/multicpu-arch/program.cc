/** @mainpage Simulación del rendimiento de procesadores interconectados

    El siguiente programa simula el funcionamiento de una arquitectura multiprocesador. Para dicha simulación, se hace uso de las clases Cluster, Procesador, Proceso y Pendientes.

    Un clúster contiene un número variable de procesadores, los cuales ejecutaran una serie de procesos. Todo proceso que no se pueda ejecutar en aquel instante se guardará en l'área de pendientes, para poder ser ejecutado posteriormente.
*/

/** @file program.cc
    @brief Programa principal para la <em>Simulación del rendimiento de procesadores interconectados</em>.
*/


#include "Cluster.hh"
#include "Pendientes.hh"
#include "Proceso.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;


/** @brief Programa principal para la <em>Simulación del rendimiento de procesadores interconectados</em>. 
*/
int main()
{
    Cluster Clust;
    Clust.leer();
    Pendientes Pend;
    Pend.leer();

    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "configurar_cluster" or comando == "cc") {
            if (comando == "configurar_cluster") {
                cout << "#configurar_cluster" << endl;
            } else cout << "#cc" << endl;

            Clust.leer();
        } else if (comando == "modificar_cluster" or comando == "mc") {
            if (comando == "modificar_cluster") {
                cout << "#modificar_cluster ";
            } else cout << "#mc ";

            string id_procesador;
            cin >> id_procesador;
            cout << id_procesador << endl;
            Cluster Subcluster;
            Subcluster.leer();

            Clust.modificar_cluster(id_procesador, Subcluster);
        } else if (comando == "alta_prioridad" or comando == "ap") {
            if (comando == "alta_prioridad") {
                cout << "#alta_prioridad ";
            } else cout << "#ap ";

            string id_prioridad;
            cin >> id_prioridad;
            cout << id_prioridad << endl;

            Pend.alta_prioridad(id_prioridad);
        } else if (comando == "baja_prioridad" or comando == "bp") {
            if (comando == "baja_prioridad") {
                cout << "#baja_prioridad ";
            } else cout << "#bp ";

            string id_prioridad;
            cin >> id_prioridad;
            cout << id_prioridad << endl;

            Pend.baja_prioridad(id_prioridad);
        } else if (comando == "alta_proceso_espera" or comando == "ape") {
            if (comando == "alta_proceso_espera") {
                cout << "#alta_proceso_espera ";
            } else cout << "#ape ";

            string id_prioridad;
            cin >> id_prioridad;
            Proceso Proc;
            Proc.leer();
            int id_proceso = Proc.consultar_id();
            cout << id_prioridad << ' ' << id_proceso << endl;

            Pend.alta_proceso(id_prioridad, Proc);
        } else if (comando == "alta_proceso_procesador" or comando == "app") {
            if (comando == "alta_proceso_procesador") {
                cout << "#alta_proceso_procesador ";
            } else cout << "#app ";

            string id_procesador;
            cin >> id_procesador;
            Proceso Proc;
            Proc.leer();
            cout << id_procesador << ' ' << Proc.consultar_id() << endl;

            Clust.alta_proceso_procesador(id_procesador, Proc);
        } else if (comando == "baja_proceso_procesador" or comando == "bpp") {
            if (comando == "baja_proceso_procesador") {
                cout << "#baja_proceso_procesador ";
            } else cout << "#bpp ";

            string id_procesador;
            int id_proceso;
            cin >> id_procesador >> id_proceso;
            cout << id_procesador << ' ' << id_proceso << endl;

            Clust.baja_proceso_procesador(id_procesador, id_proceso);
        } else if (comando == "enviar_procesos_cluster" or comando == "epc") {
            if (comando == "enviar_procesos_cluster") {
                cout << "#enviar_procesos_cluster ";
            } else cout << "#epc ";

            int num;        // num >= 0
            cin >> num;
            cout << num << endl;

            Pend.enviar_procesos_cluster(Clust, num);
        } else if (comando == "avanzar_tiempo" or comando == "at") {
            if (comando == "avanzar_tiempo") cout << "#avanzar_tiempo ";
            else cout << "#at ";

            int tiempo;     // tiempo > 0
            cin >> tiempo;
            cout << tiempo << endl;

            Clust.avanzar_tiempo(tiempo);
        } else if (comando == "imprimir_prioridad" or comando == "ipri") {
            if (comando == "imprimir_prioridad") {
                cout << "#imprimir_prioridad ";
            } else cout << "#ipri ";

            string id_prioridad;
            cin >> id_prioridad;
            cout << id_prioridad << endl;

            Pend.escribir_prioridad(id_prioridad);
        } else if (comando == "imprimir_area_espera" or comando == "iae") {
            if (comando == "imprimir_area_espera") {
                cout << "#imprimir_area_espera" << endl;
            } else cout << "#iae" << endl;

            Pend.escribir();
        } else if (comando == "imprimir_procesador" or comando == "ipro") {
            if (comando == "imprimir_procesador") {
                cout << "#imprimir_procesador ";
            } else cout << "#ipro ";

            string id_procesador;
            cin >> id_procesador;
            cout << id_procesador << endl;
            
            Clust.escribir_procesador(id_procesador);
        } else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {
            if (comando == "imprimir_procesadores_cluster") {
                cout << "#imprimir_procesadores_cluster" << endl;
            } else cout << "#ipc" << endl;

            Clust.escribir();
        } else if (comando == "imprimir_estructura_cluster" or comando == "iec") {
            if (comando == "imprimir_estructura_cluster") {
                cout << "#imprimir_estructura_cluster" << endl;
            } else cout << "#iec" << endl;

            Clust.escribir_estructura();
        } else if (comando == "compactar_memoria_procesador" or comando == "cmp") {
            if (comando == "compactar_memoria_procesador") {
                cout << "#compactar_memoria_procesador ";
            } else cout << "#cmp ";

            string id_procesador;
            cin >> id_procesador;
            cout << id_procesador << endl;

            Clust.compactar_memoria_procesador(id_procesador);
        } else if (comando == "compactar_memoria_cluster" or comando == "cmc") {
            if (comando == "compactar_memoria_cluster") {
                cout << "#compactar_memoria_cluster" << endl;
            } else cout << "#cmc" << endl;

            Clust.compactar_memoria();
        }

        cin >> comando;
    }
}