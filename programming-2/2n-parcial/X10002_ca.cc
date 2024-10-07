// Esborrat de totes les aparicions d'un element a una llista

public:
    void esborrar_tots(const T& x)
    /* Pre: parametre implicit = P */
    /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
       resta d'elements queda en el mateix ordre que a P); si el punt d'interes 
       de P referenciava a una aparicio d'x, passa a referenciar al primer 
       element diferent d'x posterior a aquesta (si no hi ha cap element 
       diferent d'x, passa a la dreta el tot); en cas contrari, el punt 
       d'interes no canvia */
    {
        node_llista* it = primer_node;

        while (it != nullptr) {
            if (it -> info == x) {
                if (it == primer_node and it == ultim_node) {
                    primer_node = nullptr;
                    ultim_node = nullptr;
                } else if (it == primer_node) {
                    (it -> seg) -> ant = nullptr;
                    primer_node = it -> seg;
                } else if (it == ultim_node) {
                    (it -> ant) -> seg = nullptr;
                    ultim_node = it -> ant;
                } else {
                    (it -> seg) -> ant = it -> ant;
                    (it -> ant) -> seg = it -> seg;
                }
                if (it == act) act = it -> seg;
                node_llista* aux = it -> seg;
                delete it;
                it = aux;
                --longitud;
            } else it = it -> seg;
        }
    }