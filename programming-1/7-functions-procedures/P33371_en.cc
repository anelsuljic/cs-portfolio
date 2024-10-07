//CAESAR CIPHER

//Given a constant k, each letter of the original message is replaced by the
//letter that is alphabetically k positions to its right (circularly, if
//needed).

//Input consists of several cases. Each case begins with a natural number k >
//0, followed by a text made up of only lowercase letters and separator
//characters, but with no spaces, and ended with a dot.
//Output: rint in a line the encrypted text, using uppercase letters. Replace
//each ‘_’ with a space, and leave unchanged the rest of separator characters.

#include <iostream>

using namespace std;

const int ALPHABET_LETTERS = 26;

//Encodes every character
//Pre: a character between 'a' and 'z'
//Post: the character encrypted
char encoded(char c, int k) {
    char character;

    if (c >= 'a' and c <= 'z') {
        character = 'A' + (c - 'a' + k) % ALPHABET_LETTERS;
    }
    else if (c == '_') character = ' ';
    else character = c;

    return character;
}

int main() {
    int num;

    //Reads every case
    while (cin >> num) {
        char character;
        cin >> character;

        //Encodes the text
        while (character != '.') {
            cout << encoded(character, num);

            cin >> character;
        }

        cout << endl;
    }
}
