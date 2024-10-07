//COUNTING A'S (1)

//The program reads a sequence of characters ended with a period and prints
//the number of letters ‘a’ in the sequence.

//Input consists of a sequence of characters ended in a period.
//Output: Print the number of times that ‘a’ appears in the sequence.

#include <iostream>

using namespace std;

int main() {
    char letters;
    cin >> letters;

    //Counts every a's
    int counter = 0;
    while (letters != '.') {
        if (letters == 'a') ++counter;

        cin >> letters;
    }

    cout << counter << endl;
}
