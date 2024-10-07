#include <iostream>
#include <vector>
#include "eda-error.hh"
#include "eda-mem.hh"

#include "sopa-letras.hh"
using std::vector;
using std::cerr;
using util::min;
using util::valor_aleatorio;



// Representación de la clase 'sopa_letras': una matriz que almacena los 
// carácteres de la sopa de letras y un booleano que indica si esta está 
// inicializada o no. Que una 'sopa_letras' esté inicializada significa que 
// todas sus celdas solo contienen carácteres ASCII del rango ['A', 'Z'] y 
// ningún asterísco (además que debe tener como mínimo cuatro filas y cuatro 
// columnas).
class sopa_letras::impl_ {
  public:

    // Inv. de representación:
    //
    // 1) 'sopa_' solo contiene strings con carácteres ASCII del rango 
    //    ['A', 'Z'] U {'*'}, y todos contienen la misma longitud.
    // 2) 'inicializada_' == true si, y solo si, 'sopa_' tiene como mínimo 
    //    cuatro strings de cuatro carácteres como mínimo y sus celdas solo 
    //    contienen carácteres ASCII del rango ['A', 'Z'] y ningún asterísco 
    //    '*'.
    vector<string> sopa_;
    bool inicializada_;      
    
    
    
    // Constantes de clase
    static const nat max_filas_ = 80;
    static const nat max_columnas_ = 80;



    // Constantes para la gestión de errores
    static const string nom_mod_;

    static const int numero_filas_incorrecto_ = 11;
    static const int longitud_fila_incorrecta_ = 12;
    static const int orientacion_incorrecta_ = 13;
    static const int sopa_incorrecta_ = 14;
    static const int pos_ini_incorrecta_ = 15;
    static const int string_no_existe_ = 16;
    static const int string_corto_ = 17;
    static const int string_no_cabe_ = 18;
    static const int fila_no_cabe_ = 19;
    static const int caracteres_invalidos_ = 20;
    

    static const string msg_num_filas_incorr_;
    static const string msg_long_fila_incorr_;
    static const string msg_orientacion_incorrecta_;
    static const string msg_sopa_incorrecta_;
    static const string msg_pos_ini_incorrecta_;
    static const string msg_string_no_existe_;
    static const string msg_string_corto_;
    static const string msg_string_no_cabe_;
    static const string msg_fila_no_cabe_;
    static const string msg_caracteres_invalidos_;
     
    


    // Operaciones privadas de 'sopa_letras'



    // Constuye un objeto 'impl_' a partir de un número de filas y columnas.
    // Pre: 4 <= num_fil <= max_filas_; 4 <= num_col <= max_columnas_. Si no 
    //      se especifica ninguno de los dos parámetros, estos toman el valor 
    //      de cero. Nota: o se especifican ambos o ninguno.
    // Post: es construido un objeto 'impl_' con 'num_fil' filas y 'num_fil' 
    //       columnas, cuyas celdas contienen asteríscos '*'. Si 'num_fil' == 
    //       'num_col' == 0, entonces el objeto queda vacia.
    impl_(nat num_fil = 0, nat num_col = 0) noexcept;



    // Construye un objeto 'impl_' a partir de otro ya existente.
    // Pre: ----
    // Post: es construido un objeto 'impl_' que corresponde a una copia de 
    //       'i'.
    impl_(const impl_& i) noexcept; 



    // Comprueba si una longitud dada es valida para obtener y/o insertar un 
    // string en una sopa de letras a partir de una posición inicial y 
    // orientación dadas.
    // Pre:  0 <= fil < rep.sopa_.size(); 0 <= col < rep.sopa_[0].size();
    //      'o' = {H, HR, V, VR, D, DR, B, BR}. 'rep' contiene la 
    //      representación de una 'sopa_letras'.
    // Post: devuelve cierto si es posible colocar 's' a partir de (fil, col) 
    //       con orientación 'o'. En caso contrario, devuelve falso.
    static bool longitud_correcta(nat lon, nat fil, nat col, 
                            const orientacion& o, const impl_& rep) noexcept;



    // Comprueba si un string es corto para añadirlo a una sopa de letras. Un 
    // string se considera corto si la sopa de letras no tiene ninguna fila y 
    // la longitud del string es menor a 4, o bien si la sopa de letras tiene 
    // filas y la longitud del string es menor al número de columnas.
    // Pre: 'rep' contiene la representación de una 'sopa_letras'.
    // Post: devuelve cierto si 's' es un string corto para añadirlo a la sopa 
    //       de letras representada por 'rep'. En caso contrario, devuelve 
    //       falso.
    static bool es_corto(const string& s, const impl_& rep) noexcept;



    // Comprueba si un string cabe en una sopa de letras como una fila nueva.
    // Un string cabe en una sopa de letras si esta no tiene ninguna fila y la 
    // longitud del string es menor al número máximo de columnas, o bien si la 
    // sopa de letras tiene filas, pero no se ha llegado a su número máximo de 
    // filas, y la longitud del string es igual al número de columnas de la 
    // sopa. 
    // Pre: 'rep' contiene la representación de una 'sopa_letras'.
    // Post: devuelve cierto si 's' cabe en 'sopa' como una nueva fila. En 
    //       caso contrario, devuelve falso.
    static bool cabe_fila(const string& s, const impl_& rep) noexcept; 



    // Comprueba si los carácteres de un string forman parte del rango 
    // ['A', 'Z'] U {'*'}.
    // Pre: s.length() >= 4.
    // Post: devuelve cierto si, y solo si, 's' contiene solamente caracteres 
    //       ASCII del rango ['A', 'Z'] U {'*'}.
    static bool caracteres_validos(const string& s) noexcept;


    
    // Devuelve los incrementadores para recorrer la sopa de letras con una 
    // orientacion especifica.
    // Pre: 'o' = {H, HR, V, VR, D, DR, B, BR}; 'inc_fil' y 'inc_col' son 
    //      variables de salida.
    // Post: inc_fil = {-1, 0, 1} y inc_col = {-1, 0, 1} segun el valor de 'o'.
    static void obtener_incrementadores(const orientacion& o, int& inc_fil, 
                                        int& inc_col) noexcept;
};

const string sopa_letras::impl_::nom_mod_ = 
    "sopa_letras";
const string sopa_letras::impl_::msg_num_filas_incorr_ = 
    "Numero de filas incorrecto";
const string sopa_letras::impl_::msg_long_fila_incorr_ = 
    "Longitud de la fila incorrecta";
const string sopa_letras::impl_::msg_orientacion_incorrecta_ =
    "Orientacion incorrecta";
const string sopa_letras::impl_::msg_sopa_incorrecta_ = 
    "La sopa de letras tiene menos de 4 filas o menos de 4 columnas";
const string sopa_letras::impl_::msg_pos_ini_incorrecta_ =
    "Posicion inicial incorrecta";
const string sopa_letras::impl_::msg_string_no_existe_ = 
    "No existe el string";
const string sopa_letras::impl_::msg_string_corto_ = 
    "El string tiene menos caracteres de los requeridos";
const string sopa_letras::impl_::msg_string_no_cabe_ = 
    "El string no cabe";
const string sopa_letras::impl_::msg_fila_no_cabe_ = 
    "La fila no cabe";
const string sopa_letras::impl_::msg_caracteres_invalidos_ = 
    "El string contiene algun caracter distinto de [\'A\',\'Z\'] U {\'*\'}";




// Implementación operaciones de 'impl_' (operaciones privadas de 
// 'sopa_letras')




sopa_letras::impl_::impl_(nat num_fil, nat num_col) 
        noexcept : sopa_(num_fil, string(num_col, '*')), inicializada_(false) {

}



sopa_letras::impl_::impl_(const impl_& i) noexcept 
: sopa_(i.sopa_.size()), inicializada_(i.inicializada_) {

    nat num_filas = sopa_.size();
    for (nat j = 0; j < num_filas; ++j) {
        // Inv: sopa_[0..j-1] contiene los mismos strings que i.sopa_[0..j-1].

        sopa_[j] = i.sopa_[j];
    }
}



bool sopa_letras::impl_::longitud_correcta(nat lon, nat fil, nat col, 
                            const orientacion& o, const impl_& rep) noexcept {

    bool cabe = false;
    nat num_filas = rep.sopa_.size();
    nat num_cols = rep.sopa_[0].length();
    switch (o) {
        case orientacion::H:
            cabe = lon <= (num_cols - col);
            break;
        case orientacion::HR:
            cabe = lon <= (col + 1);
            break;
        case orientacion::V:
            cabe = lon <= (num_filas - fil);
            break;
        case orientacion::VR:
            cabe = lon <= (fil + 1);
            break;
        case orientacion::D:
            cabe = lon <= min<nat>(num_filas - fil, num_cols - col);
            break;
        case orientacion::DR:
            cabe = lon <= min<nat>(fil + 1, col + 1);
            break;
        case orientacion::B:
            cabe = lon <= min<nat>(fil + 1, num_cols - col);
            break;
        case orientacion::BR:
            cabe = lon <= min<nat>(num_filas - fil, col + 1);
    }

    return cabe;
}



bool sopa_letras::impl_::es_corto(const string& s, const impl_& rep) noexcept {
    return (rep.sopa_.size() == 0 and s.length() < 4) or
           (rep.sopa_.size() > 0 and s.length() < rep.sopa_[0].length());
}



bool sopa_letras::impl_::caracteres_validos(const string& s) noexcept {
    bool correcto = true;
    nat i = 0;
    while (correcto and i < s.length()) {
        // Inv: todos los caracteres de s[0..i-1] son carácteres ASCII del 
        //      rango ['A', 'Z'] U {'*'}.

        if ((s[i] < 'A' or s[i] > 'Z') and s[i] != '*') correcto = false;
        else ++i;
    }

    return correcto;
}



void sopa_letras::impl_::obtener_incrementadores(
                const orientacion& o, int& inc_fil, int& inc_col) noexcept {

    switch (o) {
        case orientacion::H:
            inc_fil = 0;
            inc_col = 1;
            break;
        case orientacion::HR:
            inc_fil = 0;
            inc_col = -1;
            break;
        case orientacion::V:
            inc_fil = 1;
            inc_col = 0;
            break;
        case orientacion::VR:
            inc_fil = -1;
            inc_col = 0;
            break;
        case orientacion::D:
            inc_fil = 1;
            inc_col = 1;
            break;
        case orientacion::DR:
            inc_fil = -1;
            inc_col = -1;
            break;
        case orientacion::B:
            inc_fil = -1;
            inc_col = 1;
            break;
        case orientacion::BR:
            inc_fil = 1;
            inc_col = -1;
    }
}




// Implementación operaciones de 'sopa_letras'




sopa_letras::sopa_letras() noexcept(false) {
    try {
        rep_ = new impl_;
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": sopa_letras::sopa_letras()";
        throw;
    }
}



sopa_letras::sopa_letras(nat num_fil, nat num_col) noexcept(false) {
    try {
        if ((num_col > 0 and num_fil == 0) or num_fil > impl_::max_filas_) {
            throw error(impl_::nom_mod_, impl_::numero_filas_incorrecto_, 
                        impl_::msg_num_filas_incorr_);
        }
        else if ((num_fil > 0 and num_col == 0) or 
                  num_col > impl_::max_columnas_) {

            throw error(impl_::nom_mod_, impl_::longitud_fila_incorrecta_,
                        impl_::msg_long_fila_incorr_);
        }

        rep_ = new impl_(num_fil, num_col);
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": sopa_letras::sopa_letras" + 
                     "(nat num_fil, nat num_col)";
        throw;
    }
}



sopa_letras::sopa_letras(const sopa_letras& s) noexcept(false) {
    try {
        rep_ = new impl_(*s.rep_);
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": sopa_letras::sopa_letras" + 
                     "(const sopa_letras& s)";
        throw;
    }
}



sopa_letras& sopa_letras::operator=(const sopa_letras& s) noexcept(false) {
    try {
        impl_* aux = new impl_(*s.rep_);
        delete rep_;
        rep_ = aux;
    }
    catch (error& e) {
        // Al ser 'e' un error de memoria dinámica, modificamos el nombre del 
        // módulo para saber donde se produce dicho fallo, ya que la operacion 
        // 'new' desconoce quien la invoca.
        e.modulo() = impl_::nom_mod_ + ": sopa_letras& sopa_letras::operator="
                     + "(const sopa_letras& s)";
        throw;
    }

    return *this;
}



sopa_letras::~sopa_letras() noexcept {
    delete rep_;
}



bool sopa_letras::impl_::cabe_fila(const string& s, 
                                   const impl_& rep) noexcept {
    return (rep.sopa_.size() == 0 and s.length() <= impl_::max_columnas_) or
           (rep.sopa_.size() > 0 and rep.sopa_.size() < impl_::max_filas_ and 
            s.length() == rep.sopa_[0].size());
}



void sopa_letras::inserta_fila(const string& s) noexcept(false) {
    
    if (impl_::es_corto(s, *rep_)) {
        throw error(impl_::nom_mod_, impl_::string_corto_, 
                    impl_::msg_string_corto_);
    }
    else if (not impl_::cabe_fila(s, *rep_)) {
        throw error(impl_::nom_mod_, impl_::fila_no_cabe_, 
                    impl_::msg_fila_no_cabe_);
    }
    else if (not impl_::caracteres_validos(s)) {
        throw error(impl_::nom_mod_, impl_::caracteres_invalidos_, 
                    impl_::msg_caracteres_invalidos_); 
    }
   
    rep_ -> sopa_.push_back(s);
}



void sopa_letras::inserta_cadena(const string& s, nat fil, nat col, 
                                 const orientacion& o) noexcept(false) {

    
    if (o < orientacion::H or orientacion::BR < o) {
        throw error(impl_::nom_mod_, impl_::orientacion_incorrecta_, 
                    impl_::msg_orientacion_incorrecta_);
    }
    else if (num_filas() < 4 and num_columnas() < 4) {
        throw error(impl_::nom_mod_, impl_::sopa_incorrecta_, 
                    impl_::msg_sopa_incorrecta_);
    }
    else if (fil >= num_filas() or col >= num_columnas()) {
        throw error(impl_::nom_mod_, impl_::pos_ini_incorrecta_,
                    impl_::msg_pos_ini_incorrecta_);
    }
    else if (not impl_::longitud_correcta(s.length(), fil, col, o, *rep_)) {
        throw error(impl_::nom_mod_, impl_::string_no_cabe_, 
                    impl_::msg_string_no_cabe_);
    }
    else if (not impl_::caracteres_validos(s)) {
        throw error(impl_::nom_mod_, impl_::caracteres_invalidos_,
                    impl_::msg_caracteres_invalidos_);
    }


    nat i = fil;
    nat j = col;
    int inc_fil, inc_col;
    impl_::obtener_incrementadores(o, inc_fil, inc_col);
    
    nat k = 0;
    while (k < s.length()) {
        // Inv: los carácteres de s[0..k-1] se han insertado al parámetro 
        //      implícito a partir de la posicion (fil, col) y siguiendo la 
        //      orientación 'o'; fil <= i <= fil + s.length(); 
        //      col <= j <= col + s.length(); 0 <= k <= s.length().

        rep_ -> sopa_[i][j] = s[k];
        i += inc_fil;
        j += inc_col;
        ++k;
    }
}



void sopa_letras::reemplazar_asteriscos() noexcept {
    nat num_fil = num_filas();
    nat num_cols = num_columnas();

    for (nat i = 0; i < num_fil; ++i) {
        // Inv 1: todos los carácteres de rep_ -> sopa_[0..i-1][b], donde 
        //        0 <= b < num_cols, forman parte del rango ['A', 'Z'].

        for (nat j = 0; j < num_cols; ++j) {
            // Inv 2: todos los caráceres de 'Inv 1' más los de 
            //        rep_ -> sopa_[i][0..j-1] forman parte del rango 
            //        ['A', 'Z'].

            if (rep_ -> sopa_[i][j] == '*') {
                rep_ -> sopa_[i][j] = valor_aleatorio('A', 'Z');
            }
        }
    }

    rep_ -> inicializada_ = true;
}



string sopa_letras::cadena(nat fil, nat col, nat lon, 
                           const orientacion& o) const noexcept(false) {

    if (o < orientacion::H or orientacion::BR < o) {
        throw error(impl_::nom_mod_, impl_::orientacion_incorrecta_, 
                    impl_::msg_orientacion_incorrecta_);
    }
    else if (fil >= num_filas() or col >= num_columnas()) {
        throw error(impl_::nom_mod_, impl_::pos_ini_incorrecta_,
                    impl_::msg_pos_ini_incorrecta_);
    }
    else if (not impl_::longitud_correcta(lon, fil, col, o, *rep_)) {
        throw error(impl_::nom_mod_, impl_::string_no_existe_,
                    impl_::msg_string_no_existe_);
    }

    nat i = fil;
    nat j = col;
    int inc_fil, inc_col;
    impl_::obtener_incrementadores(o, inc_fil, inc_col);

    nat k = 0;
    string cadena;
    while (k < lon) {
        // Inv: 'cadena' contiene todos los carácteres de 
        //      rep_ -> sopa_[fil..i-1][col..j-1].

        cadena += rep_ -> sopa_[i][j];

        i += inc_fil;
        j += inc_col;
        ++k;
    }

    return cadena;
}



nat sopa_letras::num_filas() const noexcept {
    return rep_ -> sopa_.size();
}



nat sopa_letras::num_columnas() const noexcept {
    return (rep_ -> sopa_.size() > 0)  ?  rep_ -> sopa_[0].length() : 0;
}



nat sopa_letras::max_filas() noexcept {
    return impl_::max_filas_;
}



nat sopa_letras::max_cols() noexcept {
    return impl_::max_columnas_;
}



bool sopa_letras::es_inicializada() const noexcept {
    return rep_ -> inicializada_;
}



istream& operator>>(istream& is, sopa_letras& s) noexcept(false) {
    try {
        nat num_s;      // num_s >= 4
        is >> num_s;

        for (nat i = 0; i < num_s; ++i) {
            // Inv: 's' contiene 'i-1' filas leidas de 'is'.

            string fila;
            is >> fila;

            s.inserta_fila(fila);
        }
    }
    catch (const error& e) {
        s = sopa_letras();
        throw;
    }

    return is;
}



ostream& operator<<(ostream& os, const sopa_letras& s) noexcept {
    nat num_fil = s.num_filas();
    nat num_cols = s.num_columnas();
    
    for (nat i = 0; i < num_fil; ++i) {
        // Inv 1: el contenido de s.rep_ -> sopa_[0..i-1] ha sido impreso a 
        //        'os'.

        for (nat j = 0; j < num_cols; ++j) {
            // Inv 2: el contenido de Inv 1 más el contenido de 
            //        s.rep_ -> sopa_[i][0..j-1] ha sido impreso a 'os'.

            if (j != 0) os << ' ';
            os << s.rep_ -> sopa_[i][j];
        }
        if (i < num_fil - 1) os << '\n';
    }
    

    return os;
}