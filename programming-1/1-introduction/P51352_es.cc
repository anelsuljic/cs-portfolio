//ELEMENTOS

//El agua (A) vence a la piedra (P) que a su vez vence al viento (V) que vence
//al agua. El programa dice quien gana el enfrentamiento, o si se produce un
//empate.

//Entrada: Dos letras (A, P o V) separados por un espacio.
//Salida: escribe una línea con el número 1 si vence el primero, el número 2
//si vence el segundo, o un guión (‘-’) si se produce un empate.

#include <iostream>

using namespace std;

const int GANA_PRIMERO = 1;
const int GANA_SEGUNDO = 2;
const char EMPATE = '-';

int main() {
    char primero, segundo; //caracteres
    cin >> primero >> segundo;

    //Gana el primero
    if ((primero == 'A' and segundo == 'P') or (primero == 'P' and segundo ==
        'V') or (primero == 'V' and segundo == 'A')) {
        cout << GANA_PRIMERO << endl;
    }

    //Gana el segundo
    else if ((primero == 'P' and segundo == 'A') or (primero == 'V' and
             segundo == 'P') or (primero == 'A' and segundo == 'V')) {
        cout << GANA_SEGUNDO << endl;
    }

    //Empate
    else cout << EMPATE << endl;
}
