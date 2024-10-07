#include "eda-error.hh"
#include "eda-mem.hh"

#include "hueco.hh"




// Representación de la clase 'hueco': una cuádrupla 
// <fila, columna, orientacion, longitud> que identifica un hueco de una sopa 
// de letras.
class hueco::impl_ {
  public:

    // Inv. de representación:
    //
    // 1) or_ = {H, HR, V, VR, D, DR, B, BR}.

    nat fila_;
    nat columna_;
    orientacion or_;
    nat lon_;



    // Constantes para la gestión de errores.

    static const string nom_mod_;

    static const int orientacion_incorrecta_ = 21;

    static const string msg_orientacion_incorrecta_;


    // Operaciones privadas de 'hueco'


    // Construye un objeto 'impl_', que representa un objeto 'hueco'.
    // Pre: o != NO_OR.
    // Post: es construido un objeto 'impl_' a partir de la cuádrupla 
    //       <fil, col, o, lon.
    impl_(nat fil, nat col, const orientacion& o, nat lon) noexcept;
};

const string hueco::impl_::nom_mod_ = 
    "hueco";
const string hueco::impl_::msg_orientacion_incorrecta_ = 
    "orientacion incorrecta";










// Implementacion operaciones privadas 'hueco'


hueco::impl_::impl_(nat fil, nat col, const orientacion& o, nat lon) noexcept 
: fila_(fil), columna_(col), or_(o), lon_(lon) {

}










// Implementacion operaciones públicas 'hueco'


hueco::hueco(nat fil, nat col, const orientacion& o, nat lon) noexcept(false) {
    try {
        if (o == orientacion::NO_OR) {
            throw error(impl_::nom_mod_, impl_::orientacion_incorrecta_, 
                        impl_::msg_orientacion_incorrecta_);
        }
        rep_ = new impl_(fil, col, o, lon);
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        if (e.codigo() == 100) {
            e.modulo() = impl_::nom_mod_ + ": hueco::hueco(nat fil, nat col,"
                                         + " const orientacion& o, nat lon)";
        }
        throw;
    }
}


hueco::hueco(const hueco& h) noexcept(false) {
    try {
        rep_ = new impl_(h.fila(), h.columna(), h.orient(), h.longitud());
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": hueco::hueco(const hueco& h)";
        throw;
    }
}


hueco& hueco::operator=(const hueco& h) noexcept(false) {
    try {
        impl_* aux = new impl_(h.fila(), h.columna(), h.orient(), 
                               h.longitud());
        delete rep_;
        rep_ = aux;
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": hueco& hueco::operator="
                                     + "(const hueco& h)";
        throw;
    }

    return *this;
}


hueco::~hueco() noexcept {
    delete rep_;
}


nat hueco::fila() const noexcept {
    return rep_ -> fila_;
}


nat hueco::columna() const noexcept {
    return rep_ -> columna_;
}


orientacion hueco::orient() const noexcept {
    return rep_ -> or_;
}


nat hueco::longitud() const noexcept {
    return rep_ -> lon_;
}


bool hueco::operator<(const hueco& h) const noexcept {
    bool res;

    if (fila() == h.fila()) {
        if (columna() == h.columna()) {
            if (orient() == h.orient()) {
                res = longitud() < h.longitud();
            }
            else res = orient() < h.orient();
        }
        else res = columna() < h.columna();
    }
    else res = fila() < h.fila();

    return res;
}


istream& operator>>(istream& is, hueco& h) noexcept(false) {
    nat fil, col, lon;
    string orient;
    is >> fil >> col >> orient >> lon;

    // Declaramos un hueco auxiliar para asegurar que, en caso de suceder 
    // algun error, 'h' se mantiene intacto.
    hueco aux = hueco(fil, col, orientacion(orient), lon);
    h = aux;

    return is;
}