// Trenat de cues

public:
    void trenat(Cua &c)
    /* Pre: p.i. = C1, c = C2 */
    /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser 
       buida */
    {
        node_cua* aux = primer_node;
        while (aux != nullptr and c.primer_node != nullptr) {
            node_cua* seg = aux -> seguent;
            node_cua* c_seg = c.primer_node -> seguent;
            aux -> seguent = c.primer_node;
            aux = seg;
            if (seg != nullptr) c.primer_node -> seguent = seg;
            c.primer_node = c_seg;
        }

        if (c.primer_node != nullptr) {
            if (primer_node == nullptr) primer_node = c.primer_node;
            ultim_node = c.ultim_node;
        }
        
        longitud += c.longitud;
        c.primer_node = nullptr;
        c.ultim_node = nullptr;
    }