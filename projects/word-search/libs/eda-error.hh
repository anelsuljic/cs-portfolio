// Un objeto de la clase 'error' es una tupla con dos strings (el nombre del 
// módulo o clase y el mensaje de error), y un entero (el código de error). La 
// clase ofrece las operaciones 'modulo', 'mensaje', 'codigo' para consultar 
// cada uno de estos campos por separado, así como la sobrecarga del operador
// '<<' para facilitar la salida de datos.




#ifndef _EDA_ERROR
#define _EDA_ERROR




#include <iostream>
#include <string>
using std::string;
using std::ostream;




class error {
    private:
        // Representación de la clase 'error': un string para almacenar el 
        // módulo donde se produce el error, el código de error (que lo 
        // identifica), y el mensaje de error que representa una descripción 
        // del mismo. 
        
        string modulo_;       // Inv: modulo_ != "" and modulo_ != " "
        int codigo_;          // Inv: codigo_ >= 0.
        string mensaje_;      // Inv: mensaje_ != "" and mensaje_ != " "
        
    
    public:

        // Constructor



        // Construye un objeto 'error' inicializando todos sus atributos.
        // Pre: 'modulo' y 'mensaje' no son ninguno de estos dos strings: 
        //      "", " ".
        // Post: es construido un objeto 'error' con atributos 'modulo',
        //       'codigo' y 'mensaje', respectivamente.
        // Coste: theta(1).
        explicit error(const string& modulo, int codigo, 
                       const string& mensaje) noexcept;



        // Consultoras



        // Devuelve una referencia al nombre del módulo que ha generado el 
        // error y permite modificar dicho nombre. Nota: solo es recomendable 
        // modificar el nombre para los errores de memoria dinámica para saber 
        // que modulo estaba intentando reservar dicha memoria. 
        // Pre: ---
        // Post: devuelve una referencia al nombre del módulo que ha creado al 
        //       objeto error mediante el lanzamiento de una excepción y, en 
        //       caso que despues de la llamada se modifique dicho valor, el 
        //       parámetro implícto lo contiene.
        // Coste: theta(1).
        string& modulo() noexcept;


        // Devuelve una referencia al mensaje de error.
        // Pre: ---
        // Post: devuelve una referencia al mensaje de error, que indica el 
        //       error que se ha producido.
        // Coste: theta(1).
        const string& mensaje() const noexcept;


        // Devuelve el código de error.
        // Pre: ---
        // Post: devuelve el código de error que identifica al mismo.
        // Coste: theta(1).
        int codigo() const noexcept;



        // Entrada/salida



        // Imprime todos los atributos de un objeto de la clase 'error' por
        // el canal de salida indicado.
        // Pre: ---
        // Post: són impresos por el canal de salida 'os' los atributos 
        //       de 'e' con el siguiente formato: "Error en ['nombre_modulo']:
        //       'mensaje_error' (Código: 'codigo_error')"
        // Coste: theta(1).
        friend ostream& operator<<(ostream& os, const error& e) noexcept;
};




#endif