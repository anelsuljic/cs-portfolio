//INCREASING PAIRS

//The program reads sequences of natural numbers, and for each one prints
//the number of pairs of consecutive numbers such that the second number of
//the pair is greater than the first one.

//Input consists of a natural number n, followed by n sequences of strictly
//positive natural numbers. Each sequence ends with a zero.
//Output: For every sequence, print in a line the number of pairs of
//consecutive numbers such that the second number of the pair is greater than
//the first one.

#include <iostream>

using namespace std;

int main() {
    int elemseq;
    cin >> elemseq;

    //Reads every sequence
    for (int i = 0; i < elemseq; ++i) {
        int prev;
        cin >> prev;

        int counter = 0;

        //If prev == 0, then there's nothing to do
        while (prev != 0) {
            int act;
            cin >> act;

            while (act != 0) {
                if (act > prev) ++counter;

                prev = act;
                cin >> act;
            }

            prev = act;
        }

        cout << counter << endl;
    }
}
