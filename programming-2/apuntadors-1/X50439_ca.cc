// Còpia d'una cadena de nodes simplement encadenats

node_pila* copia_node_pila_it(node_pila* m) 
/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; en cas contrari, el
   resultat apunta al primer node d'una cadena de nodes que són
   còpia de de la cadena que té el node apuntat per m com a primer */
{
    node_pila* res = nullptr;

    if (m != nullptr) {
        node_pila* seguent = new node_pila;
        res = seguent;
        while (m != nullptr) {
            seguent -> info = m -> info;
            m = m -> seguent;
            if (m != nullptr) {
                seguent -> seguent = new node_pila;
                seguent = seguent -> seguent;
            }   
        }
        seguent -> seguent = nullptr;
    }

    return res;
}

Pila& operator=(const Pila& original) 
/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
   contingut anterior del p.i. ha estat esborrat (excepte si el
   p.i. i original ja eren el mateix objecte) */
{
    if (this != &original) {
        esborra_node_pila_it(primer_node);
        altura = original.altura;
        primer_node = copia_node_pila_it(original.primer_node);
    }

    return *this;
}