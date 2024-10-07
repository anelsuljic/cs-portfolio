//UPPERCASE AND LOWERCASE LETTERS

//The program reads a letter and prints it in lowercase if it was uppercase,
//or prints it in uppercase if it was lowercase.

//Input consists of a letter.
//Output: Print a line with the given letter in lowercase if it was uppercase,
//or in uppercase if it was lowercase.

#include <iostream>

using namespace std;

int main() {
    char letter; //character
    cin >> letter;

    //Conversion to uppercase
    if (letter >= 'a' and letter <= 'z') letter = letter - 'a' + 'A';

    //Conversion to lowercase
    else letter = letter - 'A' + 'a';

    cout << letter << endl;
}
