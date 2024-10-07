//CLASSIFICATION OF CHARACTERS (1)

//The program reads a letter and tells if it's an uppercase or lowercase
//letter, and also if it's consonant or vowel.

//Input consist of a letter.
//Tell if the letter is uppercase or lowercase, and also tell if it is a vowel
//or a consonant.

#include <iostream>

using namespace std;

int main() {
    char letter; //letter is a character
    cin >> letter;

    //Lowercase
    if (letter >= 'a' and letter <= 'z') {
        cout << "lowercase" << endl;
    }

    //Uppercase
    else if (letter >= 'A' and letter <= 'Z') {
        cout << "uppercase" << endl;

        //Converts the letter to lowercase, so that the next if can work.
        letter = letter - 'A' + 'a';
    }

    //See if it's vowel or consonant
    if (letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or
        letter == 'u') {

        cout << "vowel" << endl;
    }

    else cout << "consonant" << endl;
}
