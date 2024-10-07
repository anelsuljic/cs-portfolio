private:
    static node_arbreNari* suma_nodes_arbNari(node_arbreNari* node)
    /* Pre: cert */
    /* Post: el resultat es el node que conté la suma de tots els nodes de 
    l'arbre N-ari (que li direm A) que té com a arrel l'element apuntat per 
    "node", i tots els seus fills també contenen la suma dels nodes dels 
    respectius subarbres d'A */
    {
        node_arbreNari* res = nullptr;

        if (node != nullptr) {
            res = new node_arbreNari;
            res -> info = node -> info;
            int tam = node -> seg.size();
            res -> seg = vector<node_arbreNari*>(tam);
            
            // Processa les sumes dels nodes dels subarbres.
            for (int i = 0; i < tam; ++i) {
                res -> seg[i] = suma_nodes_arbNari(node -> seg[i]);
                if (res -> seg[i] != nullptr) {
                    res -> info += res -> seg[i] -> info;
                }
            }
        }

        return res;
    }

public:
    void arbsuma(ArbreNari& asum) const
    /* Pre: cert */
    /* Post: asum és un arbre amb la mateixa estructura que el p.i.
       i cada node és la suma del node corresponent al p.i
       i tots els seus descendents al p.i. */
    {
        asum.N = N;
        asum.primer_node = suma_nodes_arbNari(primer_node);
    }