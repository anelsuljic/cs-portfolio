//NÚMERO DE CIFRAS

//Dado un número, el programa dice cuantas cifras són necesarias para 
//representarlo en todas las bases desde la 2 hasta la 16.

//Entrada: una entrada con un único número k, del 1 al 10 elevado 8.
//Salida: escribe 15 líneas de la forma “Base x: y cifras.”, donde x son los 
//números del 2 al 16, y y es el número de cifras necesarias en base x para 
//representar el número k.

#include <iostream>

using namespace std;

int main() {
    int num; //número natural entre 1 i 10 elevado a 8
    cin >> num;
    
    int aux = num;
    
    //Trata cada base
    for (int i = 2; i <= 16; ++i) {
        num = aux;
        
        cout << "Base" << ' ' << i << ':' << ' ';
        
        //Cuenta las cifras
        int cifras = 0;
        while (num > 0) {
            ++cifras;
            num /= i;
        }
        cout << cifras << ' ' << "cifras." << endl;
    }
}
