#include <string>
#include "eda-error.hh"
#include "eda-mem.hh"
#include "eda-util.hh"

#include "solver.hh"
#include "orientacion.hh"
#include "list-sort.hh"
using std::string;
using util::nat;
using util::min;



namespace solver {

    // Constantes para la gestión de errores.
    const string nom_mod = "solver";
    const int incumplimiento_pre = 22;
    const string msg_incumplimiento_pre = "solve: No se cumple precondición";

    
    
    // Operaciones



    // Comprueba si se cumple la precondición de la operación 'solve'.
    // Pre: ----
    // Post: devuelve cierto si 's', 'd', 'l' cumplen la precondición de 
    //       'solve'. En caso contrario, devuelve falso.
    bool se_cumple_pre_solve(const sopa_letras& s, const diccionario& d, 
                             list<match>& l) noexcept;

    
    // Obtiene la longitud del string más largo que se puede obtener de 
    // una sopa de letras a partir de una posición inicial y orientación 
    // específicas.
    // Pre: 's' es inicializada; 0 <= fil < s.num_filas(); 
    //      0 <= col < s.num_columnas(); 'o' = {H, HR, V, VR, D, DR, B, BR}.
    // Post: devuelve la longitud del string más largo de 's' que empieza en 
    //       (fil, col) y tiene una orientación 'o'.
    nat long_max(const sopa_letras& s, nat fil, nat col, const orientacion& o)
        noexcept;
}


bool solver::se_cumple_pre_solve(const sopa_letras& s, const diccionario& d, 
                                 list<match>& l) noexcept {

    return not d.es_vacio() and s.num_filas() > 0 and s.num_columnas() > 0 
           and s.es_inicializada() and l.empty();
}


nat solver::long_max(const sopa_letras& s, nat fil, nat col, 
                     const orientacion& o) noexcept {

    nat lon = 0;
    switch (o) {
        case orientacion::H:
            lon = s.num_columnas() - col;
            break;
        case orientacion::HR:
            lon = col + 1;
            break;
        case orientacion::V:
            lon = s.num_filas() - fil;
            break;
        case orientacion::VR:
            lon = fil + 1;
            break;
        case orientacion::D:
            lon = min<nat>(s.num_filas() - fil, s.num_columnas() - col);
            break;
        case orientacion::DR:
            lon = min<nat>(fil + 1, col + 1);
            break;
        case orientacion::B:
            lon = min<nat>(fil + 1, s.num_columnas() - col);
            break;
        case orientacion::BR:
            lon = min<nat>(s.num_filas() - fil, col + 1);
    }

    return lon;
}


void solver::solve(const sopa_letras& s, const diccionario& d, list<match>& l)
     noexcept(false) {
    if (not se_cumple_pre_solve(s, d, l)) {
        throw error(nom_mod, incumplimiento_pre, msg_incumplimiento_pre);
    }
    
    nat filas = s.num_filas();
    nat cols = s.num_columnas();

    for (nat i = 0; i < filas; ++i) {
        // Inv 1: 'l' contiene todas las palabras encontradas en 's' que 
        //        empiezan en una posición (a,b), donde 0 <= a < i y 
        //        0 <= b < cols, y tienen una orientación 'orient' = {H, HR, 
        //        V, VR, D, DR, B, BR}.

        for (nat j = 0; j < cols; ++j) {
            // Inv 2: 'l' contiene todas las palabras encontradas de Inv 1, 
            //        más todas aquellas que empiezan en una posición (i,b), 
            //        donde 0 <= b < j, y tienen una orientación 
            //        'orient' = {H, HR, V, VR, D, DR, B, BR}.

            for (orientacion o = orientacion::H; o < orientacion::NO_OR; ++o) {
                // Inv 3: 'l' contiene todas las palabras de 'Inv 2', más 
                //        todas aquellas que empiezan en (i,j) y tienen una 
                //        orientación 'orient' = [H, o).

                nat lon = long_max(s, i, j, o);
                string pal = d.prefijo(s.cadena(i, j, lon, o));
                if (pal.length() >= 4) l.insert(l.end(), match(pal, i, j, o));
            }
        }
    }

    list_sort::sort(l);
}