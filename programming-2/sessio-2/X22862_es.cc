#include "Cjt_estudiants.hh"

void ord_1(Cjt_estudiants &A)
// Pre: hay preparados al canal de entrada un estudiante: {entero >= 0, double}
// Post: lee un nuevo estudiante y lo pone en el conjunto A, en el caso de que 
// no exista y A no este lleno. En caso contrario, se escribira un mensaje para 
// dar constancia de que el estudiante leido ya exite en A
{
    Estudiant est;
    est.llegir();

    int dni = est.consultar_DNI();
    if (not A.existeix_estudiant(dni)) {
        A.afegir_estudiant(est);
    } else cout << "el estudiante " << dni << " ya estaba" << endl << endl;
}

void ord_2(const Cjt_estudiants &A)
// Pre: hay preparados al canal de entrada un entero >= 0: dni
// Post: lee un dni y consulta la nota del estudiante con DNI = dni, en el caso 
// de que exista en A y tenga nota
{
    int dni;
    cin >> dni;

    if (A.existeix_estudiant(dni)) {
        Estudiant est = A.consultar_estudiant(dni);

        if (est.te_nota()) {
            cout << "el estudiante " << dni << " tiene nota " 
                 << est.consultar_nota() << endl;
        } else cout << "el estudiante " << dni << " no tiene nota" << endl;
    } else cout << "el estudiante " << dni << " no esta" << endl;
    cout << endl;
}

void ord_3(Cjt_estudiants &A)
// Pre: hay preparados en el canal de entrada un entero >= 0 (dni) y un double 
// (nota)
// Post: modifica la nota del estudiante con DNI = dni, si este existe y tiene 
// nota
{
    int dni;
    double nota;
    cin >> dni >> nota;

    if (A.existeix_estudiant(dni)) {
        Estudiant est = A.consultar_estudiant(dni);
        if (nota <= Estudiant::nota_maxima() and nota >= 0 and est.te_nota()) {
            est.modificar_nota(nota);
        } else if (nota <= Estudiant::nota_maxima() and nota >= 0) {
            est.afegir_nota(nota);
        } 
        A.modificar_estudiant(est);
    } else cout << "el estudiante " << dni << " no esta" << endl << endl;
}

double red_nota(double nota)
// Pre: 0 <= nota <= Estudiant::nota_maxima()
// Post: el resultado es la nota redondeada a la decima mas proxima
{
    return int(10.0 * (nota + 0.05)) / 10.0;
}

void ord_4(Cjt_estudiants &A)
// Pre: cierto 
// Post: A pasa a tener todas las notas de sus estudiantes redondeadas a la 
// primera decima
{
    int size = A.mida();
    for (int pos = 1; pos <= size; ++pos) {
        Estudiant est = A.consultar_iessim(pos);
        if (est.te_nota()) {
            est.modificar_nota(red_nota(est.consultar_nota()));
            A.modificar_iessim(pos, est);
        }
    }
}

int main()
// Realiza una gestion de un conjunto de estudiantes mediante distintas 
// ordenes: -1 (poner un nuevo estudiante al conjunto), -2 (consultar la nota 
// de un estudiante a partir de su DNI), -3 (modificar la nota de un 
// estudiante), -4 (redondear la nota de todos los estudiantes del conjunto), 
// -5 (escribir el conjunto de estudiantes), -6 (fin del programa)
{
    Cjt_estudiants A;
    A.llegir();
    
    int orden;  //-6 <= orden <= -1
    cin >> orden;
    while (orden != -6) {
        if (orden == -1) ord_1(A);
        else if (orden == -2) ord_2(A);
        else if (orden == -3) ord_3(A);
        else if (orden == -4) ord_4(A);
        else {
            A.escriure();
            cout << endl;
        }
        
        cin >> orden;
    }
}