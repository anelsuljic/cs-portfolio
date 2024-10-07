//HELLO-BYE

//The program reads a sequence of letters that ends with a dot and tells if it
//contains the succession of consecutive letters ‘h’, ‘e’, ‘l’, ‘l’, ‘o’ or
//not.

//Input consists of a sequence of lowercase letters ended in ‘.’.
//Output: Print “hello” if the input consecutively contains the letters ‘h’,
//‘e’, ‘l’, ‘l’, ‘o’. Otherwise, print “bye”.

#include <iostream>

using namespace std;

int main() {
    char letter;
    cin >> letter;

    bool found = false;

    //Looks for the word "hello"
    while (not found and letter != '.') {
        if (letter == 'h') {
            cin >> letter;
            if (letter == 'e') {
                cin >> letter;
                if (letter == 'l') {
                    cin >> letter;
                    if (letter == 'l') {
                        cin >> letter;
                        if (letter == 'o') found = true;
                    }
                }
            }
        }

        else cin >> letter;
    }

    if (found) cout << "hello" << endl;
    else cout << "bye" << endl;
}
