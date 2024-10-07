// Cerca en un arbre general

private:
    static bool cerca_node_arbregen(node_arbreGen* node, const T& x)
    /* Pre: cert */
    /* Post: el resultat indica si x es troba a la seqüència de nodes que conte 
    "node" o no. */
    {
        bool res = false;

        if (node != nullptr) {
            if (x == node -> info) res = true;
            else {
                int tam = node -> seg.size();
                int cont = 0;
                while (not res and cont < tam) {
                    res = cerca_node_arbregen(node -> seg[cont], x);
                    ++cont;
                }
            }
        }

        return res;
    }

public:
    bool buscar(const T& x) const
    /* Pre: cert */
    /* Post: el resultat indica si x es troba al p.i. o no */
    {
        return cerca_node_arbregen(primer_node, x);
    }