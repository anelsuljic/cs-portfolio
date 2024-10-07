//MAXIMUM OF EACH SEQUENCE

//The program reads sequences of integer numbers and prints the maximum value
//of each sequence.

//Input contains several sequences. Each sequence begins with its number of
//elements n > 0, followed by n integer numbers.
//Output: Print the maximum of every sequence, one per line.

#include <iostream>

using namespace std;

int main() {
    int elemseq;

    //Reads every sequence
    while (cin >> elemseq) {
        //The first elem is always the reference maximum
        int max;
        cin >> max;

        //Reads the rest of the sequence and treats it
        for (int i = 1; i < elemseq; ++i) {
            int act;
            cin >> act;

            if (act > max) max = act;
        }

        cout << max << endl;
    }
}
