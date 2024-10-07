// Reorganitzar una llista (versió IN)

void  reorganitzar_in(const T& x)
/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels 
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */
{
    if (primer_node != nullptr) {
        node_llista* new_primer_node = nullptr;
        node_llista* new_act = nullptr;
        node_llista* new_ultim_node = nullptr;
        // Auxiliar per no modificar el primer node original del p.i.
        node_llista* aux = primer_node;
        node_llista* petits = nullptr; 
        node_llista* grans = nullptr; 
            
        while (aux != nullptr) {
            if (aux -> info <= x) {
                if (new_primer_node == nullptr) {
                    petits = new node_llista;
                    petits -> ant = new_primer_node;
                    new_primer_node = petits;
                } else {
                    petits -> seg = new node_llista;
                    (petits -> seg) -> ant = petits;
                    petits = petits -> seg;
                }
                petits -> info = aux -> info;
                petits -> seg = nullptr;
            } else {
                if (new_act == nullptr) {
                    grans = new node_llista;
                    grans -> ant = new_act;
                    new_act = grans;
                } else {
                    grans -> seg = new node_llista;
                    (grans -> seg) -> ant = grans;
                    grans = grans -> seg;
                }
                grans -> info = aux -> info;
                grans -> seg = nullptr;
            }

            aux = aux -> seg;
        }

        // Comprova si existeixen o no elements petits/grans
        if (new_primer_node != nullptr and new_act != nullptr) {
            petits -> seg = new_act;
            new_ultim_node = grans;
        } else if (new_primer_node != nullptr) {
            new_ultim_node = petits;
        } else {
            new_primer_node = new_act;
            new_ultim_node = grans;
        }

        primer_node = new_primer_node;
        act = new_act;
        ultim_node = new_ultim_node;
    }
}