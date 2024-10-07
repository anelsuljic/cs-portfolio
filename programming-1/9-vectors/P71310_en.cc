//SCALAR PRODUCT

//The scalar product of two vectors u=(u0,…,un−1) and v=(v0,…,vn−1) is ∑i=0n−1
//ui vi.Write a function that returns the scalar product of u and v.

#include <iostream>
#include <vector>

using namespace std;

//Calculates the scalar product of two vectors.
//Pre: two vectors of real numbers, u and v, with the same size.
//Post: returns result.
double scalar_product(const vector<double>& u, const vector<double>& v) {
    //We need the size of one vector. Is indifferent which we choose.
    int sizeVec = u.size();

    double result = 0;
    //Calculates the scalar product
    for (int i = 0; i < sizeVec; ++i) {
        result += u[i] * v[i];
    }

    return result;
}
