#include <iostream>
#include <map>

using namespace std;

int main()
{
    char codi;
    string paraula;

    map<string,int> M;
    while (cin >> codi >> paraula) {
        // Comprova l'existencia de "paraula"
        map<string,int>::iterator it = M.find(paraula);
        if (it == M.end()) it = M.insert(it, make_pair(paraula, 0));
        
        // Executa l'operacio corresponent
        if (codi == 'a') ++it->second;
        else if (codi == 'e' and it->second > 0) --it->second;
        else if (codi == 'f') cout << it->second << endl;
    }
}