// THE VALUE OF THE LETTERS

#include <iostream>

using namespace std;

// Gets the value of a letter.
int get_value(char letter)
// Pre: letter is a lowercase alphabetical letter.
// Post: returns the value of letter.
{
    int res = 0 ;
    if (letter == 'a' or letter == 'e') res = 1;
    else if (letter == 'o' or letter == 's') res = 2;
    else if (letter == 'd' or letter == 'i' or letter == 'n' or letter == 'r') {
        res = 3;
    }
    else if (letter == 'c' or letter == 'l' or letter == 't' or letter == 'u') {
        res = 4;
    }
    else if (letter == 'm' or letter == 'p') res = 5;
    else if (letter == 'b' or letter == 'f' or letter == 'g' or letter == 'h' 
             or letter == 'j' or letter == 'q' or letter == 'v' or 
             letter == 'x' or letter == 'y' or letter == 'z') {
        res = 6;
    }
    else if (letter == 'k' or letter == 'w') res = 7;

    return res;
}

// Computes the value of a given message. Every letter has a specific value 
// (info on the assignment).
int main()
// Input: a sequence of characters.
// Output: the value of the corresponding message.
{
    char letter;
    int value = 0;
    while (cin >> letter) {
        if (letter >= 'a' and letter <= 'z') value += get_value(letter);
    }

    cout << value << endl;
}