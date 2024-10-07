#include <iostream>
#include <string>
#include <set>

using namespace std;

void llegeix(set<string> &S)
// Pre: hi ha preparats al canal estàndard d'entrada una llista d'strings, 
// acabada en "."
// Post: els atributs del canal estàndard d'entrada són llegits i desats a S
{
    string elem;
    cin >> elem;

    while (elem != ".") {
        S.insert(elem);
        cin >> elem;
    }
}

void escriure(const set<string> &S)
// Pre: cert
// Post: són escrits al canal estàndard de sortida els atributs de S, separats 
// per un espai.
{
    for (set<string>::const_iterator it = S.begin(); it != S.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}

// Calcula quins jugadors han participat totes les activitat i quins no
int main()
{
    set<string> Cognoms;
    llegeix(Cognoms);
    int num_act;
    cin >> num_act;

    set<string> Cap = Cognoms;
    //Seqüència de llistes
    for (int iter = 0; iter < num_act; ++iter) {
        string elem;
        cin >> elem;

        set<string> Totes;
        while (elem != ".") {
            if (Cognoms.find(elem) != Cognoms.end()) Totes.insert(elem);
            if (Cap.find(elem) != Cap.end()) Cap.erase(elem);
            cin >> elem;
        }
        Cognoms = Totes;
    }

    cout << "Totes les activitats:";
    escriure(Cognoms);
    cout << "Cap activitat:";
    escriure(Cap);
}