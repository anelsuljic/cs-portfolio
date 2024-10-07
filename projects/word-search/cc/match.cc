#include "eda-error.hh"
//#include "eda-mem.hh"

#include "match.hh"




// Representación de la clase 'match': una cuádrupla <palabra, fila, columna, 
// orientación>, que sirve para identificar una palabra en una sopa de letras.
class match::impl_ {
  public:

    // Representación de la clase 'match'


    // Inv. de representación:
    //
    // 1) o_ = {H, HR, V, VR, D, DR, B, BR}.
    // 2) palabra_ solo contiene carácteres ASCII del rango ['A', 'Z'].

    string palabra_;
    nat fila_;
    nat columna_;
    orientacion orient_;



    // Constantes para la gestión de errores


    static const string nom_mod_;



    // Operaciones privadas de la clase 'match'


    // Construye un objeto 'impl_', que representa a un objeto 'match'.
    // Pre: 'pal' solo contiene carácteres ASCII del rango ['A', 'Z']; 
    //      o = {H, HR, V, VR, D, DR, B, BR}.
    // Post: es construido un objeto 'impl_' a partir de la cuádrupla 
    //       <pal, fil, col, o>.
    impl_(const string& pal, nat fil, nat col, const orientacion& o) 
             noexcept;

};

const string  match::impl_::nom_mod_ = "match";










// Implementación operaciones privadas 'match'


match::impl_::impl_(const string& pal, nat fil, nat col, 
                    const orientacion& o) noexcept 
: palabra_(pal), fila_(fil), columna_(col), orient_(o) {
    
}










// Implementación operaciones públicas 'match'


match::match(const string& pal, nat fil, nat col, 
             const orientacion& o) noexcept(false) {

    try {
        rep_ = new impl_(pal, fil, col, o);
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": match::match(const string& pal,"
                     + "nat fil, nat col, const orientacion& o)";
        throw;
    }
}


match::match(const match& m) noexcept(false) {
    try {
        rep_ = new impl_(m.palabra(), m.fila(), m.columna(), m.orient());
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": match::match(const match& m)";
        throw;
    }
}


match& match::operator=(const match& m) noexcept(false) {
    try {
        impl_* aux = new impl_(m.palabra(), m.fila(), m.columna(), m.orient());
        delete rep_;
        rep_ = aux;
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": match& match::operator=" 
                                     + "(const match& m)";
        throw;
    }

    return *this;
}


match::~match() noexcept {
    delete rep_;
}


string match::palabra() const noexcept {
    return rep_ -> palabra_;
}


nat match::fila() const noexcept {
    return rep_ -> fila_;
}


nat match::columna() const noexcept {
    return rep_ -> columna_;
}


orientacion match::orient() const noexcept {
    return rep_ -> orient_;
}


bool match::operator<(const match& m) const noexcept {
    bool res;

    if (palabra() == m.palabra()) {
        if (fila() == m.fila()) {
            if (columna() == m.columna()) {
                res = orient() < m.orient();
            }
            else res = columna() < m.columna();
        }
        else res = fila() < m.fila();
    }
    else res = palabra() < m.palabra();

    return res;
}


bool match::operator>(const match& m) const noexcept {
    bool res;

    if (palabra() == m.palabra()) {
        if (fila() == m.fila()) {
            if (columna() == m.columna()) {
                res = orient() > m.orient();
            }
            else res = columna() > m.columna();
        }
        else res = fila() > m.fila();
    }
    else res = palabra() > m.palabra();

    return res;
}


bool match::operator<=(const match& m) const noexcept {
    bool res;

    if (palabra() == m.palabra()) {
        if (fila() == m.fila()) {
            if (columna() == m.columna()) {
                res = orient() <= m.orient();
            }
            else res = columna() <= m.columna();
        }
        else res = fila() <= m.fila();
    }
    else res = palabra() <= m.palabra();

    return res;
}


istream& operator>>(istream& is, match& m) noexcept {
    string pal, orient;
    nat fil, col;
    is >> pal >> fil >> col >> orient;
    m = match(pal, fil, col, orientacion(orient));

    return is;
}


ostream& operator<<(ostream& os, const match& m) noexcept {
    os << m.palabra() << ' ' << m.fila() << ' ' << m.columna() << ' ' 
       << m.orient().tostring();

    return os;
}