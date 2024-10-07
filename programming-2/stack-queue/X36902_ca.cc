#include <iostream>
#include <stack>

using namespace std;

int main()
// Avalua una sequencia de parèntesis utilitzant piles. Si la sequencia es
// correcta, escriu "correcte". En cas contrari, esciriu "incorrecte" i la
// posicio de la sequencia on es comet l'error
{
    

    char elem;
    cin >> elem;
    bool correcte = true;
    stack<char> oberts;
    int pos = 0;   
    while (correcte and elem != '.') {
        if (elem == '(' or elem == '[') {
            oberts.push(elem);
        } else if (elem == ')' and (oberts.empty() or oberts.top() != '(')) {
            correcte = false;
        } else if (elem == ']' and (oberts.empty() or oberts.top() != '[')) {
            correcte = false;
        } else {
            oberts.pop();
        }

        cin >> elem;
        ++pos;
    }

    if (correcte and oberts.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte " << pos << endl; 
}