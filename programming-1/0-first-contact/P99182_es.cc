//PROMEDIO

//El programa scribe el promedio de dos números enteros.
//Entrada: Una línea con dos números enteros entre -1000 y 1000, separados por 
//un espacio.
//Salida: Escribe una línea con el promedio de ambos números.

#include <iostream>

using namespace std;

int main() {
    int primernum, segundonum; //numeros enteros
    cin >> primernum >> segundonum;
    
    //Calcula el promedio
    double promedio = (double(primernum) + double(segundonum)) / 2;
    
    cout << promedio << endl;
}
