#include "eda-error.hh"




error::error(const string& modulo, int codigo, const string& mensaje) 
noexcept : modulo_(modulo), codigo_(codigo), mensaje_(mensaje) {

}



string& error::modulo() noexcept {
    return modulo_;
}



const string& error::mensaje() const noexcept {
    return mensaje_;
}



int error::codigo() const noexcept {
    return codigo_;
}



ostream& operator<<(ostream& os, const error& e) noexcept {
    os << "Error en [" << e.modulo_ << "]: " << e.mensaje_ << " (Codigo: " 
       << e.codigo_ << ')';

    return os;
}