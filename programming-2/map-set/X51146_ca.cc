// Activitats esportives ordenades (sets)


#include <iostream>
#include <string>
#include <set>

using namespace std;

// Pre: Hi ha preparats al canal estàndard d'entrada una seqüència d'strings 
// (només lletres i/o dígits) ordenats creixentment, acabada en ".".
// Post: els elements del canal estándar d'entrada són llegits y desats a "S".
// Cost: linial respecte el nombre d'elements del canal estàndard d'entrada.
void llegir(set<string> &S)
{
    string elem;
    cin >> elem;

    while (elem != ".") {
        set<string>::const_iterator it = S.insert(S.end(), elem);
        cin >> elem;
    }
}

// Pre: cert.
// Post: són escrits al canal estàndard de sortida tots els elements d'S, 
// mantenint el matiex ordre.
// Cost: linial respecte al nombre d'elements de "S".
void escriure(const set<string> &S)
{
    for (set<string>::const_iterator it = S.begin(); it != S.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}

// Calcula quins jugadors han participat a totes y a cap de les activitats 
// esportives d'unes jornades esportives.
int main()
// Entrada: Una llista amb el cognom (tots diferents i ordenats alfabèticament) 
// de tots els jugadors acabada en punt. Un enter indicant el nombre 
// d’activitats programades i tantes llistes com activitats programades, totes 
// acabades en punt, ordenades i sense cognoms repetits.
// Sortida: El text ”Totes les activitats: ” seguida de la llista de cognoms 
// que les han fetes i el text ”Cap activitat: ” seguida de la llista de 
// cognoms que no n’han fet cap.
{
    set<string> Totes;
    set<string> Cap;
    llegir(Cap);
    int num;        // num > 0.
    cin >> num;

    string elem;
    set<string>::const_iterator it1 = Totes.end();
    // Processem la primera seqüència.
    while (cin >> elem and elem != ".") {
        it1 = Totes.insert(Totes.end(), elem);
        ++it1;
        Cap.erase(elem);    
    }
    // Processem la resta d'activitats.
    for (int i = 1; i < num; ++i) {
        it1 = Totes.begin();
        while (cin >> elem and elem != ".") {
            while (it1 != Totes.end() and *it1 < elem) it1 = Totes.erase(it1);
            if (it1 != Totes.end() and *it1 == elem) ++it1;
            set<string>::const_iterator it2 = Cap.find(elem);
            if (it2 != Cap.end()) it2 = Cap.erase(it2);
        }
    }
    // Eliminem tots els elements més grans que queden després de processar 
    // l'última activitat
    while (it1 != Totes.end()) it1 = Totes.erase(it1);

    cout << "Totes les activitats:";
    escriure(Totes);
    cout << "Cap activitat:";
    escriure(Cap);
}