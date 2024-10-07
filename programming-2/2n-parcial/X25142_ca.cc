// Suma màxima dels camins d'un arbre general

private:
    static T max_suma_nodes(node_arbreGen* m)
    /* Pre: m != nullptr */
    /* Post: el resultat es la suma del camí de suma máxima de la seqüència de 
       nodes que conté m. */
    {
        if (m != nullptr) {
            T suma = m -> info;
            int ari = m -> seg.size();

            for (int i = 0; i < ari; ++i) {
                if (m -> seg[i] != nullptr) {
                    T aux = max_suma_nodes(m -> seg[i]);
                    aux += m -> info;
                    if (aux > suma) suma = aux;
                }
            }

            return suma;
        } else throw PRO2Excepcio("m no pot ser igual a nullptr");
    }

public:
    T max_suma_cami() const
    /* Pre: el parametre implicit no es buit */
    /* Post: el resultat es la suma del cami de suma maxima del parametre 
       implicit */
    {
        if (primer_node != nullptr) {
            return max_suma_nodes(primer_node);
        } else throw PRO2Excepcio("El parametre implicit no pot ser buit");
    }