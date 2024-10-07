//CHESS BOARD (2)

//The program, given a chess board, computes the total number of coins on its 
//white squares.

//Input begins with the number of rows r and the number of columns c. Follow r 
//lines, each one with c characters between ‘0’ and ‘9’.
//Output: Print the total number of coins on the white squares of the board.

#include <iostream>

using namespace std;

int main() {
    int rows, columns; //natural numbers
    cin >> rows >> columns;
    
    int sum = 0;
    
    //Reads every row
    for (int i = 0; i < rows; ++i) {
        //Reads every column
        for (int j = 0; j < columns; ++j) {
            char elem;
            cin >> elem;
            
            //Sees if elem is in a white square
            if ((i + j) % 2 == 0) sum += elem - '0';
        }        
    }
    
    cout << sum << endl;
}
