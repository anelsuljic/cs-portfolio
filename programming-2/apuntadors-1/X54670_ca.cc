// Concatenació de dues cues amb apuntadors.

void concat(Cua &c)
/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
{
    // Si "c" es buida, no s'ha de concatenar res.
    if (c.longitud != 0) {
        // Concatena les cues.
        if (primer_node == nullptr) primer_node = c.primer_node;
        else ultim_node -> seguent = c.primer_node;
        ultim_node = c.ultim_node;
        longitud += c.longitud;
        // Buida "c".
        c.ultim_node = nullptr;
        c.primer_node = nullptr;
        c.longitud = 0;
    }
}