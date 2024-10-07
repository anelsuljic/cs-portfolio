// Reorganitzar una llista (versió OUT)



Llista reorganitzar_out(const T& x) const
/* Pre: cert */
/* Post: el resultat és una llista que conté els mateixos 
elements que el p.i. tal que tots els més petits o iguals 
que x al p.i. precedeixen als més grans que x al p.i. però 
sempre respectant l'ordre que hi havia entre ells al p.i. 
L'element actual de la llista retornada és el primer dels 
més grans que x, si existeix, sinó es situa a la detra del 
tot. El p.i. no es modifica */
{
    Llista res;
    res.longitud = longitud;
    res.primer_node = nullptr; 
    res.act = nullptr;
    res.ultim_node = nullptr;

    if (primer_node != nullptr) {
        // Auxiliar per no modificar el primer node original del p.i.
        node_llista* aux = primer_node;
        node_llista* petits = nullptr; 
        node_llista* grans = nullptr; 
            
        while (aux != nullptr) {
            if (aux -> info <= x) {
                if (res.primer_node == nullptr) {
                    petits = new node_llista;
                    petits -> ant = res.primer_node;
                    res.primer_node = petits;
                } else {
                    petits -> seg = new node_llista;
                    (petits -> seg) -> ant = petits;
                    petits = petits -> seg;
                }
                petits -> info = aux -> info;
                petits -> seg = nullptr;
            } else {
                if (res.act == nullptr) {
                    grans = new node_llista;
                    grans -> ant = res.act;
                    res.act = grans;
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
        if (res.primer_node != nullptr and res.act != nullptr) {
            petits -> seg = res.act;
            res.ultim_node = grans;
        } else if (res.primer_node != nullptr) {
            res.ultim_node = petits;
        } else {
            res.primer_node = res.act;
            res.ultim_node = grans;
        }
    }
      
    return res;
}