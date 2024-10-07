#include <iostream>
#include <stack>

using namespace std;

int main()
// Comprova si una sequencia de nombres es palindroma o no
{
    int mida;
    cin >> mida;
    stack<int> P;
    //Desa a P la primera meitat de la sequencia
    int posseq = 0;
    while (posseq < mida / 2) {
        int elem;
        cin >> elem;
        P.push(elem);
        ++posseq;
    }
    //Si el nombre d'elements es imparell, el central es salta
    if (mida % 2 != 0) {
        int elem;
        cin >> elem;
        ++posseq;
    }
    bool correcte = true;
    //Comprova que la sequencia sigui palindroma
    while (correcte and posseq < mida) {
        int elem;
        cin >> elem;
        if (P.top() != elem) correcte = false;
        else {
            P.pop();
            ++posseq;
        }
    }

    if (correcte) cout << "SI" << endl;
    else cout << "NO" << endl;
}