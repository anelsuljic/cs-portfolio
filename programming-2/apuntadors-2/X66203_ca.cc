// Màxim d'un arbre n-ari

private:
    static T node_maxim_arbreNari(node_arbreNari* node, int tam)
    /* Pre: node != nullptr */
    /* Post: el resultat es el valor máxim de l'arbre N-ari que té com a arrel 
       l'element apuntat per "node" */
    {
        T max = node -> info;

        // Comprova si els nodes seguents tenen un valor més gran que l'arrel.
        for (int i = 0; i < tam; ++i) {
            if (node -> seg[i] != nullptr) {
                T aux = node_maxim_arbreNari(node -> seg[i], tam);
                if (aux > max) max = aux;
            }
        }

        return max;
    }

public:
    T maxim() const
    /* Pre: el p.i. no és buit */
    /* Post: el resultat indica el valor més gran que conté el p.i. */
    {
        if (primer_node != nullptr) return node_maxim_arbreNari(primer_node, N);
        else throw PRO2Excepcio("El p.i. no pot ser buit");
    }