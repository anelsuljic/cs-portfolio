// CHESS BOARD (3)

// The program reads a square chessboard of size n² ("n" is a natural
// number), where every square contains between 0 and 9 coins. After that, it
// computes the total number of coins on the chessboard's main diagonal and
// antidiagonal, and prints to the std output channel such result.ç

// Input: a natural number that indicates the size of the chessboard (call it
//        "size"), followed by "size" lines of "size" characters each line,
//        where each character is a value between '0' and '9'.
// Output: prints to the std output channel the total number of coins of
//         the main diagonal and antidiagonal of the chessboard read.

// Example of input and output:
// 
// Inp: 3
//      975
//      123
//      450
// Out: 20


#include <iostream>
using namespace std;


int main()
{
    int size;   // natural number bigger than zero.
    cin >> size;

    int res = 0;
    for (int i = 0; i < size; ++i) {
        // Inv 1: 0 <= i <= size; res contains the sum of elements that are
        //        part of the main diagonal or antidiagonal in rows between
        //        0 and i-1.

        for (int j = 0; j < size; ++j) {
            // Inv 2: 0 <= j <= size; res contains the sum of values specified 
            //        in Inv 1, plus the sum of all elements that are part of
            //        the main diagonal or antidiagonal in row "i" and columns
            //        between 0 and j-1.

            char num_coins;
            cin >> num_coins;

            if (i == j or i + j == size - 1) res += num_coins - '0';
        }
    }

    cout << res << endl;
}