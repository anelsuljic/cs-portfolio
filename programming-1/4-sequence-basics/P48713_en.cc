// PRIMALITY


#include <iostream>
using namespace std;


// Tells if each element of a sequence of natural numbers is prime or not.
// Pre/Input: the standard input channel contains a natural number, n, followed
//            by "n" natural numbers.
// Post/Output: for each number of the sequence from the input channel, prints
//              wheter the number is prime or not.
int main()
{
    unsigned int num_elems;
    cin >> num_elems;

    for (int i = 0; i < num_elems; ++i) {
        // Inv: it has been printed to the standard output channel the 
        //      primality of all treated numbers of the sequence.

        unsigned int elem_seq;
        cin >> elem_seq;

        bool no_prime = elem_seq <= 1;
        for (int j = 2; not no_prime and j * j <= elem_seq; ++j) {
            // Inv: all the natural numbers from [2..j-1] don't divide 
            //      "elem_seq".

            if (elem_seq % j == 0) no_prime = true;
        }

        if (not no_prime) cout << elem_seq << " is prime" << endl;
        else cout << elem_seq << " is not prime" << endl;
    }
}