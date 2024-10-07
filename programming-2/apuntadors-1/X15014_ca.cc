private:
    static node_arbre* suma_nodes_arbre(node_arbre* m)
    /* Pre: cert. */
    /* Post: el resultat conté la suma de tots els nodes de l'arbre el qual te com a arrel l'element apuntat per "m". */
    {
        node_arbre* res = nullptr;
        
        if (m != nullptr) {
            node_arbre* aux = new node_arbre;
            aux -> info = m -> info;
            aux -> segE = suma_nodes_arbre(m -> segE);
            aux -> segD = suma_nodes_arbre(m -> segD);

            if (aux -> segE != nullptr) aux -> info += (aux -> segE) -> info;
            if (aux -> segD != nullptr) aux -> info += (aux -> segD) -> info;
            res = aux;
        }

        return res;
    }

public:
    void arb_sumes(Arbre<int> &asum) const
    /* Pre: cert */
    /* Post: l'arbre asum és l'arbre suma del p.i. */
    {
        asum.primer_node = suma_nodes_arbre(primer_node);
    }