//PRODUCTS OF MATRICES

//Write a function that, given two matrices a and b, computes their product

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Rows;
typedef vector<Rows> Matrix;

//Computes the product of two matrices
//Pre: a = p x q; b = q x r
//Post: returns res; res = p x r
Matrix product(const Matrix& a, const Matrix& b) {
    int rows = a.size(); //p
    int cols = b[0].size(); //r
    Matrix res(rows, Rows(cols));

    //Computes a * b
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int aux = b.size(); //tambe serveix a[0].size()
            for (int k = 0; k < aux; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}
