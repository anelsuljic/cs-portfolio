//CONTROL C202E

//El programa llegeix un natural n i escriu figures n× n com es mostra als 
//exemples.

//L’entrada és un natural n ≥ 1.
//Cal escriure la figura corresponent.

#include <iostream>

using namespace std;

int main() {
    int num; //nombre natural
    cin >> num;
   
    //Escriu cada linia
    for (int i = 0; i < num; ++i) {
        //Escriu '+'
        for (int k = 1; k < num - i; ++k) {
            cout << '+';
        }
        
        cout << '/';
        
        //Escriu '*'
        for (int l = 0; l < i; ++l) {
            cout << '*';
        }
        
        cout << endl;
    }
}
