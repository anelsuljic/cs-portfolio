//PRODUCT OF SQUARE MATRICES

//Write a function that, given two square matrices a and b, computes their
//product.

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Rows;
typedef vector<Rows> Matrix;

//Computes the product of two matrices.
//Pre: two matrices of integer numbers.
//Post: returns a and b.
Matrix product(const Matrix& a, const Matrix& b) {
    int size = a.size(); //the size is the same for both square matrices.

    Matrix c(size, Rows(size));

    //Makes the product of a * b.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}
