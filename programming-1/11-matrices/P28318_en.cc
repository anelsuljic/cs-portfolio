//ROWS AND COLUMNS

//Write a program that reads a matrix, and afterwards prints the rows, the
//columns and the elements that are asked for.

//Input consists of a matrix followed by a sequence of questions about the
//matrix.
//Output: For every question, print the row, the column, or the element asked
//for.

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Rows;
typedef vector<Rows> Matrix;

//Reads a sequence of integer numbers and stores it into a matrix.
//Pre: --------
//Post: returns Mat.
Matrix read_data() {
    int rows, cols; //natural numbers
    cin >> rows >> cols;

    Matrix Mat(rows, Rows(cols));

    //Reads the sequence and stores it into Mat.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> Mat[i][j];
        }
    }

    return Mat;
}

//Reads a row position, x, and prints the row x of Mat.
//Pre: a matrix of integer numbers.
//Post: --------
void print_row(const Matrix &Mat) {
    int pos; //row position
    cin >> pos;

    cout << "row" << ' ' << pos << ':';

    int rowSize = Mat[0].size();
    //Prints the row
    for (int i = 0; i < rowSize; ++i) {
        cout << ' ' << Mat[pos - 1][i];
    }

    cout << endl;
}

//Reads a column position, x, and prints the column x of Mat.
//Pre: a matrix of integer numbers.
//Post: --------
void print_col(const Matrix &Mat) {
    int pos; //column position
    cin >> pos;

    cout << "column" << ' ' << pos << ':';

    int colSize = Mat.size();
    //Prints the column
    for (int i = 0; i < colSize; ++i) {
        cout << ' ' << Mat[i][pos - 1];
    }

    cout << endl;
}

//Reads the position of one element of a matrix, and prints it.
//Pre: a matrix of integer numbers.
//Post: --------
void print_elem(const Matrix &Mat) {
    int row, col; //coordinates of elem
    cin >> row >> col;

    cout << "element" << ' ' << row << ' ' << col << ':'
         << ' ' << Mat[row - 1][col - 1] << endl;
}

int main() {
    //Reads the matrix
    Matrix Mat = read_data();

    string request;
    //Reads every request and does the necessary task
    while (cin >> request) {
        if (request == "row") print_row(Mat);
        else if (request == "column") print_col(Mat);
        else print_elem(Mat); //request == "element"
    }
}
