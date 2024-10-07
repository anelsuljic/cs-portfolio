// Un objeto del tipo orientacion puede tomar cualquiera de los valores que
// aparecen listados en la definición del tipo mediante 'enum'. El valor 
// 'orientacion::NO_OR' sirve como valor ficticio. El operador de incremento 
// aplicado sobre un objeto del tipo hace que éste tome el valor siguiente
// en la lista, salvo que su valor fuese NO_OR, en cuyo caso no se modifica.
// Los operadores relacionales (==, <=, ...) pueden usarse entre los valores
// del tipo (H es el menor valor y NO_OR el mayor) gracias a la sobrecarga del 
// operador 'int()'. La constructora que recibe un string como argumento nos 
// permite crear una orientación a partir de su nombre. Como alternativa, está 
// la constructora que recibe directamente uno de los valores del 'enum'. 
// 'tostring()' nos devuelve la representación de un valor en un string, lo 
// que permite imprimirlo convenientemente. Por último, 'orientacion' tiene 
// definidas la constructora por copia, la destructora y el operador de 
// asignación.



#ifndef _ORIENTACION_HH
#define _ORIENTACION_HH


#include <string>
using std::string;



class orientacion {
  private:
    class impl_;
    impl_* rep_;    // Inv: rep_ != nullptr

  public:

    // Representa las distintas orientaciones que puede tomar un objeto de 
    // esta clase:
    //      - H = horizontal, de izquierda a derecha 
    //      - HR = horizontal, de derecha a izquierda 
    //      - V = vertical, de arriba a abajo 
    //      - VR = vertical, de abajo a arriba 
    //      - D = diagonal, de arriba-izquierda a abajo-derecha 
    //      - DR = diagonal, de abajo-derecha a arriba-izquierda 
    //      - B = diagonal, de abajo-izquierda a arriba-derecha 
    //      - BR = diagonal, de arriba-derecha a abajo-izquierda
    // 'H' contiene el menor valor (0) y 'NO_OR' el mayor (8).
    enum {H, HR, V, VR, D, DR, B, BR, NO_OR};



    // Constructoras



    // Construye un objeto 'orientacion' a partir de una orientacion 
    // indicada. Nota: también actua como constructora por defecto.
    // Pre: 'o' debe contener alguna de las orientaciones válidas para el
    //      objeto a construir: H, HR, V, VR, D, DR, B, BR, NO_OR. En los 
    //      casos donde no se pasa dicho parámetro al llamar a la 
    //      constructora, 'o' toma el valor de 'NO_OR'.
    // Post: es construido un objeto de tipo 'orientacion' con orientacion 
    //       'o'. En caso que 'o' no contenga una orientación válida, se 
    //       tomara el valor por defecto 'NO_OR'.
    // Errores: lanza un error en caso que no haya memoria dinámica disponible 
    //          para crear el objeto 'orientacion'.
    // Coste: theta(1).
    orientacion(int o = NO_OR) noexcept(false);


    // Construye un objeto 'orientacion' a partir de una orientacion 
    // indicada en formato 'string'.
    // Pre: 's' debe contener el nombre de alguna de las orientaciones 
    //      válidas. Concretamente: "H", "HR", "V", "VR", "D", "DR", "B", 
    //      "BR", "NO_OR".
    // Post: se construye un objeto de tipo 'orientacion' con la orientacion 
    //       indicada con 's'. En caso que la orientacion indicada no sea 
    //       válida, se asigna la orientación ficticia 'NO_OR'.
    // Coste: theta(1).
    orientacion(const string& s) noexcept(false); 



    // Constructora por copia, asignación y destructora



    // Construye un objeto 'orientacion' a partir de uno ya existente.
    // Pre: ----
    // Post: es construido un objeto de tipo 'orientacion' que representa la 
    //       copia del objeto 'orient'.
    // Coste; theta(1).
    orientacion(const orientacion& orient) noexcept(false);


    // Copia el contenido de un objeto 'orientacion' al parámetro implícito.
    // Pre: ----
    // Post: devuelve una referencia al parámetro implícito, el cual es una 
    //       copia de 'orient'.
    // Coste: theta(1).
    orientacion& operator=(const orientacion& orient) noexcept;


    // Destruye un objeto 'orientacion'.
    // Pre: ----
    // Post: el parámetro implícito es destruido.
    // Coste: theta(1).
    ~orientacion() noexcept;



    // Modificadoras



    // Hace que el parámetro implicito tome el siguiente valor de la lista 
    // de orientaciones. Ejemplo: si el p.i. tiene orientación 'HR' enonces 
    // tomará la orientación 'V'.
    // Pre: ----
    // Post: el parámetro implícito contiene el siguiente valor de la lista 
    //       de orientaciones. Si ya contenia la orientación 'NO_OR', 
    //       entonces no se modifica.
    // Coste: theta(1).
    orientacion& operator++() noexcept;



    // Consultoras



    // Devuelve el valor de un objeto 'orientacion' en formato entero.
    // Pre: ----
    // Post: devuelve la orientación del parámetro implícito en formato 
    //       de un entero: H = 0, ..., NO_OR = 8.
    // Coste: theta(1).
    operator int() const noexcept;


    // Devuelve el valor de un objeto 'orientacion' en formato 'string'.
    // Pre: ----
    // Post: devuelve la orientación del parámetro implícito en formato 
    //       de un 'string': H = "H", ..., NO_OR = "NO_OR".
    // Coste: theta(1).
    string tostring() const noexcept;


};


#endif