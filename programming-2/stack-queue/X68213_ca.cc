/* Simula els movivents dels mostradors d'una biblioteca. El mostrador consta
   de piles de llibres classificats en n categories. Mitjançant diferents tipus 
   d'ordres (-1, -2, -3, -4) es realitzaran diferents moviments respecte a 
   aquestes piles. L'especificacio de cada ordre la trobareu a la capçalera de
   cada operacio. */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void ord_1(vector<stack<string> > &devolucions)
// Pre: cert
// Post: "devolucions" conte un nou element afegit a la pila corresponent amb la 
// categoria seleccionada
{
    string titol;
    int categoria; //1 <= categoria <= devolucions.size()
    cin >> titol >> categoria;
    devolucions[categoria - 1].push(titol);
}

void ord_2(vector<stack<string> > &devolucions)
// Pre: cert
// Post: elimina la quantitat seleccionada de llibres d'una de les piles de 
// "devolucions"; si la quantitat es mes gran que la mida de la pila, s'esborrara
// fins que quedi buida
{
    int quantitat, categoria;   //1 <= categoria <= devolucions.size()
    cin >> quantitat >> categoria;

    int comptador = 0;
    while (not devolucions[categoria - 1].empty() and comptador < quantitat) {
        devolucions[categoria - 1].pop();
        ++comptador;
    }
}

void ord_3(const vector<stack<string> > &devolucions)
// Pre: cert
// Post: s'escriuen al canal de sortida tots els elements de la pila de la 
// categoria seleccionada: "Pila de la categoria n" seguit del elements
{
    int categoria;  //1 <= categoria <= devolucions.size()
    cin >> categoria;

    stack<string> escriptura(devolucions[categoria - 1]);

    cout << "Pila de la categoria " << categoria << endl;
    while (not escriptura.empty()) {
        cout << escriptura.top() << endl;
        escriptura.pop();
    }
}


int main()
// Entrada: un nombre n per indicar el nombre de categories, seguit d'una
// sequencia d'ordres, complementada amb les dades necessaries per ser executades
// Sortida: escriu la pila de la categoria seleccionada: "Pila de la categoria n"
// seguit d'una llista dels elements d'aquesta pila
{
    int categories; //categoria > 0
    cin >> categories;
    vector<stack<string> > devolucions(categories);

    int ordre;
    cin >> ordre;
    while (ordre != -4) {
        if (ordre == -1) ord_1(devolucions);
        else if (ordre == -2) ord_2(devolucions);
        else if (ordre == -3) {
            ord_3(devolucions);
            cout << endl;
        }

        cin >> ordre;
    }
}