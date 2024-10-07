#include "orientacion.hh"
#include "eda-error.hh"
#include "eda-mem.hh"
using std::cerr;
using std::endl;



// Representación de la clase 'orientacion': un entero que almacena
// uno de los valores posibles definidos en el 'enum' que representa
// las distintas orientaciones (definicion del 'enum' en la 
// especificación de la clase 'orientacion')
class orientacion::impl_ {
  public:
    // Inv:
    // - 'or_' = {H, HR, V, VR, D, DR, B, BR, NO_OR}
    // - 0 <= 'or_' <= 8. Nota: H = 0, ..., NO_OR = 8
    int or_;



    // Constructora


    // Construye un objeto 'impl' a partir de una orientacion 
    // indicada. Nota: también actua como constructora por defecto.
    // Pre: 'o' debe contener alguna de las orientaciones válidas para el
    //      objeto a construir: H, HR, V, VR, D, DR, B, BR, NO_OR. En los 
    //      casos donde no se pasa dicho parámetro al llamar a la 
    //      constructora, 'o' toma el valor de 'NO_OR'.
    // Post: es construido un objeto de tipo 'impl' con orientacion 
    //       'o'.
    // Coste: theta(1).
    impl_(int o = NO_OR) noexcept;
};


orientacion::impl_::impl_(int o) noexcept : or_(o) {

}


orientacion::orientacion(int o) noexcept(false) {
    try {
        // 'new impl' ya asigna la orientacion 'NO_OR' automáticamente.
        rep_ = new impl_;
        if (H <= o and o <= NO_OR) rep_ -> or_ = o;
    }
    catch (const error& e) {
        cerr << "Error en \'orientacion::orientacion(int o = NO_OR)\'. " 
             << e.mensaje() << " (Codigo error: " << e.codigo() << ')' 
             << endl;  
    }
}


orientacion::orientacion(const string& s) noexcept(false) {
    try {
        // 'new impl' ya asigna la orientacion 'NO_OR' automáticamente.
        // Dicha orientacion podrá cambiar según la evaluación de las 
        // sentencias 'if'-
        rep_ = new impl_;
        
        if (s == "H") rep_ -> or_ = H;
        else if (s == "HR") rep_ -> or_ = HR;
        else if (s == "V") rep_ -> or_ = V;
        else if (s == "VR") rep_ -> or_ = VR;
        else if (s == "D") rep_ -> or_ = D;
        else if (s == "DR") rep_ -> or_ = DR;
        else if (s == "B") rep_ -> or_ = B;
        else if (s == "BR") rep_ -> or_ = BR;
    }
    catch (const error& e) {
        cerr << "Error en \'orientacion::orientacion(const string& s)\'. " 
             << e.mensaje() << " (Codigo error: " << e.codigo() << ')' 
             << endl;  
    }
}


orientacion::orientacion(const orientacion& orient) noexcept(false) {
    try {
        rep_ = new impl_(orient.rep_ -> or_);
    }
    catch (const error& e) {
        cerr << "Error en \'orientacion::orientacion"
             << "(const orientacion& orient)\'. " << e.mensaje() 
             << " (Codigo error: " << e.codigo() << ')' 
             << endl;  
    }
}


orientacion& orientacion::operator=(const orientacion& orient) noexcept {
    try {
        if (this != &orient) {
            impl_* aux = new impl_(orient.rep_ -> or_);
            delete rep_;
            rep_ = aux;
        }
    }
    catch (const error& e) {
        cerr << "Error en \'orientacion::operator="
             << "(const orientacion& orient)\'. " << e.mensaje() 
             << " (Codigo error: " << e.codigo() << ')' 
             << endl;  
    }    

    return *this;
}


orientacion::~orientacion() noexcept {
    delete rep_;
}


orientacion& orientacion::operator++() noexcept {
    rep_ -> or_ = (rep_ -> or_ == NO_OR)  ?  NO_OR : rep_ -> or_ + 1;

    return *this;
}


orientacion::operator int() const noexcept {
    return rep_ -> or_;
}


string orientacion::tostring() const noexcept {
    string res;
    switch (rep_ -> or_) {
        case H : 
            res = "H";
            break;
        case HR : 
            res = "HR";
            break;
        case V:
            res = "V";
            break;
        case VR:
            res = "VR";
            break;
        case D:
            res = "D";
            break;
        case DR:
            res = "DR";
            break;
        case B:
            res = "B";
            break;
        case BR:
            res = "BR";
            break;
        default:
            res = "NO_OR";
    }

    return res;
}