//TRANSPOSED MATRIX

//Write a procedure that transposes a square matrix m.

//Input consist of two natural numbers, rows and cols, followed by a sequence
//of integer numbers. Observation: rows == cols.
//Output: prints the transposed matrix.

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Rows;
typedef vector<Rows> Matrix;

//Transposes a matrix of integer numbers.
//Pre: a matrix of integer numbers.
//Post: returns m.
void transpose(Matrix& m) {
    int sizem = m.size();

    //We store the transposed data into an auxiliar matrix
    Matrix Aux(sizem, Rows(sizem));

    //Transposes m
    for (int i = 0; i < sizem; ++i) {
        for (int j = 0; j < sizem; ++j) {
            Aux[i][j] = m[j][i];
        }
    }

    m = Aux;
}
