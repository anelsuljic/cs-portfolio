//CHESS BOARD (1)

//Consider a chess board with r rows and c columns, where every square
//contains between 0 and 9 coins. The program, given a chess board, computes
//the total number of coins on it.

//Input begins with the number of rows r and the number of columns c. Follow r
//lines, each one with c characters between ‘0’ and ‘9’.
//Output: Print the total number of coins on the board.

#include <iostream>

using namespace std;

int main() {
    int rows, columns; //natural numbers
    cin >> rows >> columns;

    int total = 0;

    //Reads every row
    for (int i = 0; i < rows; ++i) {
        //Reads every column and sums the coin
        for (int j = 0; j < columns; ++j) {
            char elem;
            cin >> elem;

            total += elem - '0';
        }
    }

    cout << total << endl;
}
