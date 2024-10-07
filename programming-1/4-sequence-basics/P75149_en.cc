//LOOKING FOR AN A

//The program reads a sequence of characters ended in a dot and tells if the 
//sequence has any lowercase ‘a’ or not.

//Input consists of a sequence of characters ended in ‘.’.
//Print “yes” or “no” depending on whether ‘a’ appears in the sequence or not.

#include <iostream>

using namespace std;

int main() {
    char characters;
    cin >> characters;
    
    bool found = false; //We didn't find an a yet.
    
    //Looks for an a.
    while (not found and characters != '.') {
        found = characters == 'a';
        
        cin >> characters;
    }
    
    if (found) cout << "yes" << endl;
    else cout << "no" << endl;
}
