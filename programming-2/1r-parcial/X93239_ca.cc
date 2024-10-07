#include <iostream>
#include <vector>

using namespace std;

int suma_vec(const vector<int> &v)
/* Pre: cert */
/* Post: el resultat es la suma dels elements de v, excepte el primer */
{
    int size = v.size();
    int sum = 0;
    for (int i = 1; i < size; ++i) {
        sum += v[i];
    }

    return sum;
}

int comptatge_frontisses(const vector<int> &v)
/* Pre: cert */
/* Post: el resultat es el nombre d'elements frontissa de v */
{
    int i = 0;
    int size = v.size();
    int ant = 0;
    int suc = suma_vec(v);
    int res = 0;
    // Inv: 0 <= i <= size; res = "nombre d'elements frontissa de v[0..i - 1]; 
    // ant = v[0] + ... + v[i - 1] i suc = v[i + 1] + ... + v[size - 1]"
    while (i < size - 1) {
        if (v[i] == suc - ant) ++res;
        ant += v[i];
        suc -= v[i + 1];
        ++i;
    }
    if (v[i] == suc - ant) ++res;

    return res;
}

/* Calcula el nombre d'elements frontissa d'un vector d'enters. Un element es frontissa si, i només si, es igual a la diferència entre la suma dels seus successors i la suma dels seus antecessors */
//int main()
/* Entrada: un vector d'enters */
/* Sortida: el nombre d'elements frontissa del vector de l'entrada */
/*{
    int size;
    cin >> size;

    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    }

    cout << comptatge_frontisses(v) << endl;
}*/