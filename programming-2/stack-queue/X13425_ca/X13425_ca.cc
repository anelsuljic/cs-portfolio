#include "CuaIOParInt.hh"

void distr_cues(queue<ParInt> &inicial, queue<ParInt> &cua_2)
// Pre: inicial = INICIAL; cua_2 no te cap element
// Post: els elements de INICIAL son distribuits entre inicial i cua_2 seguint ç
// els criteris especificats a l'explicacio del programa
{
    int temps_cua_1 = 0;
    int temps_cua_2 = 0;

    int mida = inicial.size();
    for (int i = 0; i < mida; ++i) {
        ParInt front = inicial.front();
        if (temps_cua_1 <= temps_cua_2) {
            inicial.push(front);
            temps_cua_1 += front.segon();
        } else if (temps_cua_1 > temps_cua_2) {
            cua_2.push(front);
            temps_cua_2 += front.segon();
        }
        inicial.pop();
    }
}

// A partir d'una cua de parells d'enters, de la forma (identificador, temps 
// esperat), el programa reparteix els usuaris en dues cues diferents per tal 
// que cada usuari esperi el minim temps possible. Si un usuari pot anar a les 
// dues cues, s'escull la primera
int main()
// Entrada: una sequencia de parells d'enters, acabada en 0 0
// Sortida: el contingut de les dues cues 
{
    queue<ParInt> Inicial;
    llegirCuaParInt(Inicial);

    queue<ParInt> Cua_2;
    distr_cues(Inicial, Cua_2);

    escriureCuaParInt(Inicial);
    cout << endl;
    escriureCuaParInt(Cua_2);
}