//GIRANT UNA LLISTA DE PARAULES (4)

//Write a program that reads a number n and a sequence of n or more words, and
//prints the n last words in reverse order.

//Input begins with a natural number n, followed by, at least, n words.
//Output: Print the last n words of the original sequence, in reverse order,
//and one per line.

#include <iostream>

using namespace std;

//Reads a list of words and prints the last num words in reversed order.
//Pre: a natural number: num.
//Post: returns num - 1.
void reversing_words(int &num) {
    string word;

    if (cin >> word) {
        reversing_words(num);

        if (num > 0) {
            cout << word << endl;

            --num;
        }
    }
}

int main() {
    int num;
    cin >> num;

    reversing_words(num);
}
