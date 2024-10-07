private:
    static int freq_nodes_arbregen(node_arbreGen* node, const T& x)
    /* Pre: cert */
    /* Post: el resultat indica quantes vegades apareix "x" a la seqüència de 
    nodes que conté "node" */
    {
        int f = 0;

        if (node != nullptr) {
            if (x == node -> info) ++f;
            
            int tam = node -> seg.size();
            for (int i = 0; i < tam; ++i) {
                f += freq_nodes_arbregen(node -> seg[i], x);
            }
        }

        return f;
    }

public:
    int freq(const T& x) const
    /* Pre: cert */
    /* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
    {
        return freq_nodes_arbregen(primer_node, x);
    }