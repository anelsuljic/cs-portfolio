// Cerca de subarbres binaris

private:
    static void cerca_node_arbre(node_arbre* node, node_arbre* &res,
                                 const T& x, int alt, int& min)
    /* Pre: cert */
    /* Post: si node -> info == x, el res es una copia de la seqüència de 
       nodes que conté "node". Altrament, el resultat es nullptr. */
    {
        if (node != nullptr) {
            if (node -> info == x and (alt < min or min == -1)) {
                res = copia_node_arbre(node);
                min = alt;
            } else {
                cerca_node_arbre(node -> segE, res, x, alt + 1, min);
                cerca_node_arbre(node -> segD, res, x, alt + 1, min);
            }
        }
    }

public:
    void sub_arrel(Arbre& asub, const T& x)
    /* Pre: p.i. = A, asub es buit */
    /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
       si A no conte x, asub es buit */
    {
        asub.primer_node = nullptr;
        int min = -1;
        cerca_node_arbre(primer_node, asub.primer_node, x, 0, min);
    }