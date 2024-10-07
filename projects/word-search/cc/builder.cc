#include <string>
#include "eda-error.hh"
#include "eda-util.hh"
#include "eda-mem.hh"

#include "builder.hh"
#include "list-sort.hh"
using std::string;



namespace builder {

    // Definiciones de tipos para hacer más legible la declaración de
    // iteradores.
    typedef list<hueco>::const_iterator huecos_const_it;
    typedef list<match>::const_iterator l_const_it;



    // Constantes para la gestión de errores.
    const string nom_mod = "builder";
    const int huecos_no_colocables = 21;
    const string msg_huecos_no_colocables = "No se pueden colocar huecos";



    // Operaciones



    // Rellena un hueco de una sopa de letras con una palabra.
    // Pre: h.longitud() == pal.length(); 'pal' está compuesto únicamente
    //      por carácteres ASCII entre 'A' y 'Z'; 'h' es un hueco válido de 
    //      's'.
    // Post: 's' contiene el hueco representado por 'h' rellenado con el string
    //       'pal' y 'l' contiene un nuevo objeto 'match', que almacena la 
    //       información del nuevo hueco rellenado.
    void rellenar_hueco(const hueco& h, const string& pal, list<match>& l,
                        sopa_letras& s) noexcept;


    // Restablece el estado anterior de un hueco de una sopa de letras.
    // Pre: h.longitud() == patron.lenght(); 'patron' está compuesto únicamente
    //      por carácteres ASCII del rango ['A', 'Z'] U {'*'}; 'h' es un 
    //      hueco válido de 's'; se debe haber llamado previamente a la 
    //      operación 'rellenar_hueco(h, pal, l, s)', donde 'pal' es la 
    //      palabra con la qual se ha rellenado el hueco 'h' en 's'; el último 
    //      elemento de 'l' corresponde a la información del relleno de 'h' en 
    //      's'; 'patron' corresponde al string anterior al relleno de 'h' en 
    //      's'.
    // Post: el string que rellena 'h' en 's' ha sido substituido por 'patron';
    //       la información del relleno de 'h' en 's' ha sido eliminada de 'l'.
    void deshacer_cambios(const hueco& h, const string& patron, list<match>& l,
                          sopa_letras& s) noexcept;


    // Rellena una serie de huecos en una sopa de letras con las palabras 
    // almacenadas en un diccionario.
    // Pre: todos los huecos de 'huecos[huecos.begin(), it_hueco)' tienen 
    //      asignada una palabra de 'd', dichos resultados se almacenan 
    //      en 'l' y 's' contiene los huecos mencionados rellenados con su 
    //      respectiva palabra asignada; 'hay_solucion' == false; 'd' no es 
    //      vacío, 's.num_filas()' > 0 y 's.num_columnas()' > 0; huecos.begin
    //      () <= it_hueco <= huecos.end(); 'caben_huecos' == true.
    // Post: si 'hay_solucion' == true, entonces todos los huecos de 
    //       'huecos' tienen asignada una palabra de 'd', dichos resultados 
    //       se almacenan en 'l' y 's' contiene los huecos mencionados 
    //       rellenados con su respectiva palabra asignada. En caso 
    //       contrario, 'l' y 's' mantienen su estado inicial.
    // Errores: lanza un error si alguno de los huecos no puede colocarse 
    //          en 's' debido a su tamaño. En ese caso, caben_huecos == false.
    void rellenar_huecos(

        const diccionario& d, const list<hueco>& huecos, 
        list<match>& l, sopa_letras& s, 
        huecos_const_it it_hueco, bool& hay_solucion, bool& caben_huecos
        
    ) noexcept(false);

}



void builder::rellenar_hueco(const hueco& h, const string& pal, list<match>& l,
                             sopa_letras& s) noexcept {

    l.push_back(match(pal, h.fila(), h.columna(), h.orient()));
    s.inserta_cadena(pal, h.fila(), h.columna(), h.orient());
}



void builder::deshacer_cambios(const hueco& h, const string& patron,
                               list<match>& l, sopa_letras& s) noexcept {
    
    s.inserta_cadena(patron, h.fila(), h.columna(), h.orient());
    l.pop_back();
}



void builder::rellenar_huecos(

    const diccionario& d, const list<hueco>& huecos,
    list<match>& l, sopa_letras& s, 
    huecos_const_it it_hueco, bool& hay_solucion, bool& caben_huecos

) noexcept(false) {

    if (it_hueco == huecos.end() and not huecos.empty()) hay_solucion = true;
    else {
        try {
            string patron = s.cadena(it_hueco -> fila(), 
                                     it_hueco -> columna(), 
                                     it_hueco -> longitud(), 
                                     it_hueco -> orient());
            // si el hueco no cabe, 's.cadena(...)' ya lanzará la respectiva 
            // excepción.


            list<string> candidatas;
            d.satisfacen_patron(patron, candidatas);


            list<string>::const_iterator it_cand = candidatas.begin();
            while (caben_huecos and not hay_solucion 
                   and it_cand != candidatas.end()) {

                // Inv: candidatas.begin() <= it <= candidatas.end(); no se ha 
                //      podido encontrar una solución con las palabras de 
                //      'candidatas[candidatas.begin(), it_cand)'.

                rellenar_hueco(*it_hueco, *it_cand, l, s); 
                rellenar_huecos(d, huecos, l, s, ++it_hueco, 
                                hay_solucion, caben_huecos);
                --it_hueco;

                if (not hay_solucion or not caben_huecos) {
                    deshacer_cambios(*it_hueco, patron, l, s);
                    ++it_cand;
                }
            }
        }
        catch (const error& e) {
            caben_huecos = false;
        }
    }
}



void builder::build(const diccionario& d, const list<hueco>& huecos, 
                    list<match>& l, sopa_letras& s) noexcept(false) {
             
    huecos_const_it it_hueco = huecos.begin();
    bool hay_solucion = false;
    bool caben_huecos = true;
    rellenar_huecos(d, huecos, l, s, it_hueco, hay_solucion, caben_huecos);


    if (not hay_solucion or not caben_huecos) {
        throw error(nom_mod, huecos_no_colocables, msg_huecos_no_colocables);
    }
    
    s.reemplazar_asteriscos();
    list_sort::sort<match>(l);
}