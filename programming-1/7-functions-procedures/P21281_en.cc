//MOST FREQUENT FACTOR

//Write a procedure void factor(int n, int& f, int& q); to store in f the 
//most frequent factor of n, and store in q how many times it appears. If 
//there is a tie, choose the smallest factor. 

//Input is a sequence of natural numbers bigger than 2.
//Output: prints the most frequent factor and the number of times it appears.

#include <iostream>

using namespace std;

//Finds the most frequent factor of a natural number and returns how many 
//times that factor appears.
//Pre: n >= 2.
//Post: returns f and q.
void factor(int n, int &f, int &q) {
    //We force always q to zero.
    q = 0;
    
    int divisor = 2;
    //Finds the most frequent factor.
    while (divisor * divisor <= n) {
        int q_aux = 0;
        //Finds how many times the divisor is useful
        while (n % divisor == 0) {
            ++q_aux;
            n /= divisor;
        }
        
        //Sees if the actual divisor is more frequent than the previous.
        if (q_aux > q) {
            q = q_aux;
            f = divisor;
        }
        
        ++divisor;
    }
    //The number is prime
    if (q == 0) {
        f = n;
        q = 1;
    }
}

int main() {
    int num;
    
    while (cin >> num) {
        int fact = 0;
        int freq = 0;
        
        factor(num, fact, freq);
        
        cout << fact << ' ' << freq << endl;
    }
}
