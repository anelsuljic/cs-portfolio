//HORNER SCHEME

//Write a function int evaluate(const vector<int>& p, int x) that evaluates
//the polynomial at the point x. Use the Horner Scheme.

//Input consists of a natural number n > 0, followed by a sequence of integer
//numbers. Finally, there's an integer number x.
//Output: prints the sum of the Horner Scheme.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Reads a sequence of integer numbers and stores it into a vector.
//Pre: a vector with empty elements.
//Post: returns Seq.
void reads_vector(vector<int> &Seq) {
    int sizeVec = Seq.size();

    for (int i = 0; i < sizeVec; ++i) {
        cin >> Seq[i];
    }
}

//Makes the evaluation of a polynomial expression given with a vector at the
//point x.
//Pre: a vector of integers and an integer x.
//Post: returns sum
int evaluate(const vector<int>& p, int x) {
    int vectorSize = p.size();

    int sum = 0;
    int aux = 0;
    //Makes the operation
    for (int i = 0; i < vectorSize; ++i) {
	aux = pow(x, i);
        sum += p[i] * aux;
    }

    return sum;
}

int main() {
    int size; //natural number

    while (cin >> size) {
        //Stores the coefficients into a vector
        vector<int> Coefficients(size);
        reads_vector(Coefficients);

        //Reads the point x and evaluates the polynomial expression
        int point;
        cin >> point;

        cout << evaluate(Coefficients, point) << endl;
    }
}
