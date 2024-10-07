//IS IT A PALINDROME?

//Write a function that tells if s is a palindrome or not. Remember that a
//word is a palindrome if it reads the same from left to right than from
//right to left.

//Input consist of a sequence of words.
//Output: prints true if the word is a palindrome. Otherwhise, prints false.

#include <iostream>
#include <string>

using namespace std;

//Looks if a word is a palindrome and returns true if it is.
//Pre: a string word.
//Post: returns result.
bool is_palindrome(const string& s) {
    bool result = true;

    //Two counters to treat every positin of s.
    int lastelem = s.size() - 1;
    int firstelem = 0;

    //Inv: stops whether result is false or firstelem == lastelem
    while (result and firstelem < lastelem) {
        if (s[firstelem] != s[lastelem]) result = false;
        else {
            ++firstelem;
            --lastelem;
        }
    }

    return result;
}

int main() {
    string word;

    while (cin >> word) {
        if (is_palindrome(word)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}
