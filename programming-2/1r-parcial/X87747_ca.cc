#include <iostream>
#include <vector>

using namespace std;

int solitaris(const vector<int> &v)
/* Pre: v.size() > 0 */
/* Post: el resultat es el nombre de solitaris a v */
{
    int res = 0;
    int i = 1;
    int size = v.size();
    if (size == 1 or (i < size and v[0] != v[i])) ++res;
    else ++i;
    // Inv: 1 <= i <= size; res = "nombre d'elements solitaris de v[0..i-1]"; 
    // v[0] es diferent del seu antecessor i v[size - 1] es diferent del seu 
    // successor
    while (i < size - 1) {
        if (v[i] != v[i - 1] and v[i] != v[i + 1]) ++res;
        // Si l'element actual es igual al següent, llavors v[i + 1] no es 
        // solitari i no fa falta tractar-lo.
        else if (v[i] == v[i + 1]) ++i;
        ++i; 
    }
    // Si 'i' apunta a l'últim element, vol dir que aquest es solitari ja que es diferent a l'anterior.
    if (i == size - 1 and v[i] != v[i - 1]) ++res; 

    return res;
}

/* Calcula el nombre d'elements solitaris d'un vector d'enters. Un element d'un 
vector es solitari si, i només si, es diferent del seu antecessor i successor. */
//int main()
/* Entrada: un vector d'enters */
/* Sortida: el nombre d'elements solitaris del vector de l'entrada */
/*{
    int size;
    cin >> size;

    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    }

    cout << solitaris(v) << endl;
}*/