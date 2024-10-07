// RECTANGLES DIAGONALS

#include <iostream>

using namespace std;

// Escriu un rectangle d'f files i c columnes, de manera que a la diagonal hi 
// hagi zeros i a la resta de posicions la distància respecte a aquesta mòdul 
// 10.
int main()
// Entrada: dos nombres naturals estrictament positius.
// Sortida: escriu el rectangle mencionat anteriorment.
{
    unsigned int f, c;
    cin >> f >> c;

    for (unsigned int i = 0; i < f; ++i) {
        unsigned int compt = 0;
        unsigned int j = i;
        // Ordre decreixent
        while (compt < c and j > 0) {
            cout << j % 10;
            ++compt;
            --j;
        }
        j = 0; 
        // Ordre creixent 
        while (compt < c) {
            cout << j % 10;
            ++compt;
            ++j;
        }
        cout << endl;
    }
}