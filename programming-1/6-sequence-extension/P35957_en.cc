//MIDDLE DIGITS

//The program decides the winner of Anna and Bernard's game.

//Input consists of a natural number n≥ 1, followed by 2n natural numbers a1,
//b1, …, an, bn: a1 is the first number of Anna, b1 is the first number of
//Bernard, a2 is the second number of Anna, etcetera.
//Print ‘A’, ‘B’, or ‘=’, depending on whether Anna wins, Bernard wins, or it
//is a tie.

#include <iostream>

using namespace std;

int main() {
    int num; //natural number
    cin >> num;

    bool winner = false;
    int counter = 0;
    int md_prev = 0;

    //Looks for the winner of the game
    while (not winner and counter < 2 * num) {
        int elemseq;
        cin >> elemseq;

        int aux = elemseq;
        int n_digits = 1;

        //Calculates the number of digits
        while (aux > 9) {
            ++n_digits;
            aux /= 10;
        }

        //Sees if there are even digits or not
        if (n_digits % 2 == 0) winner = true;
        else {
            //Looks for the middle digit
            for (int i = 0; i < n_digits / 2; ++i) {
                elemseq /= 10;
            }
            int md_act = elemseq % 10;

            //Anna's first number
            if (counter == 0) {
                md_prev = md_act;
            }
            //Rest of numbers
            else {
                if (md_act != md_prev) winner = true;
                else md_prev = md_act;
            }
        }

        ++counter;
    }

    //Looks who finally wins
    if (winner and counter % 2 == 0) cout << 'A' << endl;
    else if (winner and counter % 2 != 0) cout << 'B' << endl;
    else cout << '=' << endl;
}
