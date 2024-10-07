#include "eda-error.hh"
#include "eda-mem.hh"
#include "eda-util.hh"

#include "diccionario.hh"
using util::nat;




// Para representar un 'diccionario' usaremos el Ternary Search Tree (TST), el 
// cual nos permite insertar y obtener palabras del diccionario con coste 
// logarítmico de promedio (en el peor caso, el coste seria lineal). Para 
// representar el TST usaremos una subclase 'nodo_tst' que representa un nodo 
// del mismo y un apuntador al primer nodo. Un 'nodo_tst' almacena un único 
// carácter de un string. Contiene, además, un booleano que indica si ese 
// carácter representa el final de un string, así como tres apuntadores 'izq', 
// 'mid' y 'der' que representan, respectivamente, los subárboles TST 
// izquierdo, central y derecho. Todos los strings que empiezan con un 
// carácter que es más pequeño que el del nodo actual se almacenan en el 
// subárbol izquierdo. Análogamente, los strings que empiezan con un carácter 
// que es más grande que el del nodo actual se almacenan en el subárbol 
// derecho. El subárbol central contiene todos los substrings que son la 
// continuación del string principal, el cual contiene el carácter del nodo 
// actual.
class diccionario::impl_ {
  public:
    
    // Representación de la clase 'diccionario'.


    // Inv. de representación:
    //
    // 1) 'nodo_tst_.letra_' = ['A', 'B'].
    // 2) 'nodo_tst_.final_palabra_' es cierto si, y solo si, el nodo 
    //    representa el final de una palabra del diccionario.
    // 3) raiz_ == nullptr representa un diccionario con la palabra vacia.

    class nodo_tst_ {
      public:
        char letra_;
        bool final_palabra_;
        nodo_tst_* izq_;
        nodo_tst_* mid_;
        nodo_tst_* der_;


        // Construye un nodo_tst_ a partir de un carácter indicado.
        // Pre: 'A' <= c <= 'Z'; 'final' == true si 'c' es el caracter final 
        //      de una palabra.
        // Post: es construido un 'nodo_tst_' con letra_ == c, 
        //       final_palabra_ == 'final', izq_ == mid_ == der_ == nullptr.
        nodo_tst_(char c, bool final) noexcept;
    };

    nodo_tst_* raiz_;



    // Constantes para la gestión de errores.
    static const string nom_mod_;

    static const int string_invalido_ = 20;

    static const string msg_string_invalido_;



    // Operaciones privadas de 'diccionario'
    

    // Destruye el contenido de un TST.
    // Pre: ----
    // Post: el contenido de un TST, cuyo primer nodo es apuntado por 'nodo', 
    //       es destruido.
    static void destruye_tst(nodo_tst_* nodo) noexcept;


    // Devuelve un puntero al primer nodo de un TST, el cual corresponde a la 
    // copia de otro ya existente.
    // Pre: 'nodo' es un puntero al primer nodo de un TST.
    // Post: devuelve un puntero al primer nodo de un TST, que es la copia de 
    //       otro TST apuntado por 'nodo'.
    static nodo_tst_* copia_tst(nodo_tst_* nodo) noexcept(false);
    
    
    // Construye un objeto 'impl_', que corresponde a la representación de un
    // objeto 'diccionario'.
    // Pre: ----
    // Post: es construido un objeto 'impl_', que representa un diccionario 
    //       con la palabra vacia.
    impl_() noexcept;


    // Construye un objeto 'impl_', que corresponde a la representación de un
    // objeto 'diccionario', a partir de otro ya existente.
    // Pre: ----
    // Post: es construido un objeto 'impl_' a partir de la copia de 'rep'.
    impl_(const impl_& rep) noexcept(false);


    // Destruye un objeto 'impl_', que corresponde a la representación de un 
    // objeto 'diccionario'.
    // Pre: ----
    // Post: el parámetro implícito es destruido.
    ~impl_() noexcept;


    // Inserta una palabra a un objeto 'impl_' el cual corresponde a 
    // la representación de un 'diccionario'.
    // Pre: 's' solo contiene carácteres ASCII del rango ['A', 'Z']; 
    //      'caracter_invalido' == false; 0 <= idx <= s.lenght().
    // Post: devuelve un apuntador a un 'nodo_tst_', el cual corresponde al 
    //       subarbol que contiene insertado el substring s[idx..s.length()].
    static nodo_tst_* inserta_palabra(const string& s, nodo_tst_* nodo, 
                            nat idx, bool& caracter_invalido) noexcept(false);

    
    // Calcula y devuelve la longitud de un prefijo más largo de un string.
    // Pre: s[idx] es un carácter ASCII del rango ['A', 'Z']; 
    //      0 <= idx <= s.length().
    // Post: devuelve la longitud del prefijo más largo de 's', el valor de la 
    //       cual forma parte del rengo [0, s.length()].
    static nat obtener_long_pref(const string& s, nodo_tst_* nodo, nat idx) 
               noexcept(false);


    // Devuelve una lista de palabras de un objeto 'impl_' que satisfacen un 
    // patron especifico.
    // Pre: s[idx] es un carácter ASCII del rango ['A', 'Z'] U {'*'}; 
    //      0 <= idx <= s.length(); 'aux' almacena la "subpalabra" que 
    //      satisface el subpatron s[0..idx-1]; 'l' contiene todas las 
    //      palabras que satisfacen el patron 's'.
    // Post: se han añadido a 'l' todas aquellas palabras que empiezan con los 
    //       carácteres de 'aux', terminan con una secuencia de caracteres 
    //       almacenada en el TST representado por 'nodo' y cumplen el patron 
    //       's'.
    static void satisfacen_patron(const string& s, nodo_tst_* nodo, nat idx,
                                 string& aux, list<string>& l) noexcept(false);

    
    // Escribe el contenido de un objeto 'impl_', el cual representa un objeto 
    // 'diccionario'.
    // Pre: 'aux' contiene los carácteres almacenados de todos los nodos padre 
    //      que tienen a 'nodo' dentro de sus subárboles centrales.
    // Post/salida: son escritos al canal de salida 'os' cada una de las 
    //              palabras que empiezan con los carácteres de 'aux' y tienen 
    //              su útlimo carácter dentro del TST representado por 'nodo'.
    static void escribe_contenido(nodo_tst_* nodo, ostream& os, string& aux) 
                noexcept;

};

const string diccionario::impl_::nom_mod_ = "diccionario";
const string diccionario::impl_::msg_string_invalido_ = "String invalido";










// Implementación operaciones de impl_::nodo_tst_




diccionario::impl_::nodo_tst_::nodo_tst_(char c, bool final) noexcept 
: letra_(c), final_palabra_(final), izq_(nullptr), mid_(nullptr), 
  der_(nullptr) {

}










// Implementación operaciones privadas 'diccionario'




void diccionario::impl_::destruye_tst(nodo_tst_* nodo) noexcept {
    if (nodo != nullptr) {
        destruye_tst(nodo -> izq_);
        destruye_tst(nodo -> mid_);
        destruye_tst(nodo -> der_);
        delete nodo;
    }
}


diccionario::impl_::nodo_tst_* diccionario::impl_::copia_tst(nodo_tst_* nodo) 
    noexcept(false) {
    
    nodo_tst_* aux = nullptr;
    if (nodo != nullptr) {
        aux = new nodo_tst_(nodo -> letra_, nodo -> final_palabra_);

        // Intenta copiar el subárbol izquierdo.
        try {
            aux -> izq_ = copia_tst(nodo -> izq_);
        }
        catch (const error& e) {
            delete aux;
            throw;
        }
        // Intenta copiar el subárbol central.
        try {
            aux -> mid_ = copia_tst(nodo -> mid_);
        }
        catch (const error& e) {
            destruye_tst(aux -> izq_);
            delete aux;
            throw;
        }
        // Intenta copiar el subárbol derecho.
        try {
            aux -> der_ = copia_tst(nodo -> der_);
        }
        catch (const error& e) {
            destruye_tst(aux -> izq_);
            destruye_tst(aux -> mid_);
            delete aux;
            throw;
        }
    }


    return aux;
}


diccionario::impl_::impl_() noexcept : raiz_(nullptr) {
    
}


diccionario::impl_::impl_(const impl_& rep) noexcept(false) {
    try {
        raiz_ = impl_::copia_tst(rep.raiz_);
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": diccionario::impl_::impl_" 
                     + "(const impl_& rep)";
        throw;
    }
}


diccionario::impl_::~impl_() noexcept {
    destruye_tst(raiz_);
}


diccionario::impl_::nodo_tst_* diccionario::impl_::inserta_palabra(
    const string& s, nodo_tst_* nodo, nat idx, bool& caracter_invalido
) noexcept(false) {

    try {
        if (s[idx] < 'A' or 'Z' < s[idx]) {
            throw error(nom_mod_, string_invalido_, msg_string_invalido_);
        }


        if (nodo == nullptr) {
            nodo_tst_* aux = new nodo_tst_(s[idx], false);
            if (idx == s.length() - 1) aux -> final_palabra_ = true;
            else {
                aux -> mid_ = inserta_palabra(s, aux -> mid_, idx + 1, 
                                              caracter_invalido);
            }

            if (caracter_invalido) delete aux;
            else nodo = aux;
        }
        else if (s[idx] < nodo -> letra_) {
            nodo -> izq_ = inserta_palabra(s, nodo -> izq_, idx, 
                                           caracter_invalido);
        }
        else if (s[idx] > nodo -> letra_) {
            nodo -> der_ = inserta_palabra(s, nodo -> der_, idx, 
                                           caracter_invalido);
        }
        else { // s[idx] == nodo -> letra_
            if (idx == s.length() - 1) nodo -> final_palabra_ = true;
            else {
                nodo -> mid_ = inserta_palabra(s, nodo -> mid_, idx + 1, 
                                               caracter_invalido);
            }
        }
    }
    catch (const error& e) {
        if (e.codigo() == string_invalido_) caracter_invalido = true;
    }

    return nodo;
}


nat diccionario::impl_::obtener_long_pref(const string& s, nodo_tst_* nodo, 
                                          nat idx) noexcept(false) {
    
    nat lon = 0;
    if (idx < s.length() and nodo != nullptr) {
        if (s[idx] < 'A' or 'Z' < s[idx]) {
            throw error(nom_mod_, string_invalido_, msg_string_invalido_);
        }

        if (s[idx] < nodo -> letra_) {
            lon = obtener_long_pref(s, nodo -> izq_, idx);
        }
        else if (s[idx] > nodo -> letra_) {
            lon = obtener_long_pref(s, nodo -> der_, idx);
        }
        else {
            lon = obtener_long_pref(s, nodo -> mid_, idx + 1);

            if (lon == 0 and nodo -> final_palabra_) lon = idx + 1;
        }
    }

    return lon;
}


void diccionario::impl_::satisfacen_patron(const string& s, nodo_tst_* nodo, 
                       nat idx, string& aux, list<string>& l) noexcept(false) {

    if (idx < s.length() and nodo != nullptr) {
        if ((s[idx] < 'A' or 'Z' < s[idx]) and s[idx] != '*') {
            throw error(nom_mod_, string_invalido_, msg_string_invalido_);
        }

        if (s[idx] == '*') {
            satisfacen_patron(s, nodo -> izq_, idx, aux, l);

            aux.push_back(nodo -> letra_);
            satisfacen_patron(s, nodo -> mid_, idx + 1, aux, l);
            if (idx == (s.length() - 1) and nodo -> final_palabra_) {
                l.insert(l.end(), aux);
            }
            aux.pop_back();

            satisfacen_patron(s, nodo -> der_, idx, aux, l);
        }
        else if (s[idx] < nodo -> letra_) {
            satisfacen_patron(s, nodo -> izq_, idx, aux, l);
        }
        else if (s[idx] > nodo -> letra_) {
            satisfacen_patron(s, nodo -> der_, idx, aux, l);
        }
        else { // s[idx] == nodo -> letra_
            aux.push_back(nodo -> letra_);
            satisfacen_patron(s, nodo -> mid_, idx + 1, aux, l);
            if (idx == (s.length() - 1) and nodo -> final_palabra_) {
                l.insert(l.end(), aux);
            }
            aux.pop_back();
        }
    }
}


void diccionario::impl_::escribe_contenido(nodo_tst_* nodo, ostream& os, 
                                           string& aux) noexcept {
    
    if (nodo != nullptr) {
        escribe_contenido(nodo -> izq_, os, aux);


        aux.push_back(nodo -> letra_);
        if (nodo -> final_palabra_) os << aux << endl;

        escribe_contenido(nodo -> mid_, os, aux);
        aux.pop_back();


        escribe_contenido(nodo -> der_, os, aux);
    }
}










// Implementación operaciones públicas 'diccionario'




diccionario::diccionario() noexcept(false) {
    try {
        rep_ = new impl_;
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": diccionario::diccionario()";
        throw;
    }
}


diccionario::diccionario(const diccionario& d) noexcept(false) {
    try {
        rep_ = new impl_(*d.rep_);
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": diccionario::diccionario" 
                     + "(const diccionario& d)";
        throw;
    }
}


diccionario& diccionario::operator=(const diccionario& d) noexcept(false) {
    try {
        if (this != &d) {
            impl_* aux = new impl_(*d.rep_);
            delete rep_;
            rep_ = aux;
        }
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": diccionario& diccionario::operator="
                     + "(const diccionario& d)";
        throw;
    }

    return *this;
}


diccionario::~diccionario() noexcept {
    delete rep_;
}


void diccionario::inserta(const string& s) noexcept(false) {
    bool caracter_invalido = false;
    rep_ -> raiz_ = impl_::inserta_palabra(s, rep_ -> raiz_, 0, 
                                           caracter_invalido);
    
    if (caracter_invalido) {
        throw error(impl_::nom_mod_, impl_::string_invalido_, 
                    impl_::msg_string_invalido_);
    }
}


string diccionario::prefijo(const string& p) const noexcept(false) {
    nat lon = impl_::obtener_long_pref(p, rep_ -> raiz_, 0);
    return p.substr(0, lon);
}


void diccionario::satisfacen_patron(const string& s, list<string>& l) 
                  const noexcept(false) {
    
    string aux;
    impl_::satisfacen_patron(s, rep_ -> raiz_, 0, aux, l);
}


bool diccionario::es_vacio() const noexcept {
    return rep_ -> raiz_ == nullptr;
}


istream& operator>>(istream& is, diccionario& d) noexcept(false) {
    string pal;
    is >> pal;

    // El diccionario 'aux' sirve para hacer una lectura segura, ya que si 
    // alguna palabra del canal de entrada no cumple la precondición, debemos 
    // garantizar que 'd' sigue intacto.
    diccionario aux;
    while (pal != "end") {
        // Inv: 'aux' almacena todas las palabras leídas del canal de entrada 
        //      'is'.

        aux.inserta(pal);
        is >> pal;
    }
    d = aux;

    return is;
}


ostream& operator<<(ostream& os, const diccionario& d) noexcept {
    string aux;
    diccionario::impl_::escribe_contenido(d.rep_ -> raiz_, os, aux);

    return os;
}