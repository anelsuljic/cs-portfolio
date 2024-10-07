//LINES IN ORDER (1)

//Write a program that, given a sequence of lines with words, tells which is
//the first line that has the words in increasing (lexicographic) order.

//Input consists of a sequence of lines with words. Each line begins with a
//number n, followed by n words made up of only lowercase letters.
//Print the index of the first line with the words in (not necessary
//strictly) increasing order. If there is no such line, tell so. Follow the
//format of the examples.

#include <iostream>

using namespace std;

int main() {
    int numelemseq;
    bool increasing = false;
    int line = 0;

    //Reads the list of sequences
    while (not increasing and cin >> numelemseq) {
        string prev;
        cin >> prev;
        bool wrong = false;

        //Reads the elements of one sequence
        int find = 1;
        while (find < numelemseq) {
            string actual;
            cin >> actual;

            //Sees if the order is correct
            if (actual >= prev) prev = actual;
            else wrong = true;
            ++find;
        }
        if (not wrong) increasing = true;
        ++line;
    }

    if (increasing) {
        cout << "The first line in increasing order is ";
        cout << line << '.' << endl;
    }
    else cout << "There is no line in increasing order." << endl;

}
