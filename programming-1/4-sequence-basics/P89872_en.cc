//SECOND MAXIMUM WORD

//Write a program that prints the second largest word, in alphabetical order,
//of a given a sequence of words, ignoring repetitions.

//Input consists of several words, all made up of only lowercase letters.
//There will always be at least two different words.
//Output: Print the second largest word in alphabetical order, ignoring
//repetitions.

#include <iostream>

using namespace std;

int main() {
    string max, secondmax;
    cin >> max >> secondmax;

    //After reading the first words, looks which is the biggest
    if (secondmax > max) {
        string newmax = max;
        max = secondmax;
        secondmax = newmax;
    }

    string elemseq;
    //Looks for the second maximum word of the sequence
    while (cin >> elemseq) {
        if (elemseq != max and elemseq != secondmax) {
            if (elemseq > secondmax and elemseq > max) {
                secondmax = max;
                max = elemseq;
            }
            else if (elemseq > secondmax) secondmax = elemseq;
            else if (max == secondmax) secondmax = elemseq;
        }
    }

    cout << secondmax << endl;
}
