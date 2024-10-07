// Frequencia de paraules amb diccionaris

#include <iostream>
#include <map>

using namespace std;

int main()
{
    char codi;
    string paraula;

    map<string, int> M;
    while (cin >> codi >> paraula) {
        if (codi == 'a') {
            ++M[paraula];
        } else cout << M[paraula] << endl;
    }
}