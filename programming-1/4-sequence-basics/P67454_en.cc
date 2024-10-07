// COUNTING A'S (2)


#include <iostream>
using namespace std;


// Prints the number of times the character 'a' appears in a sequence of
// characters ended with '.'
// Pre/Input: the standard input channel contains a sequence of characters 
//            ended with '.'
// Post/Output: prints to the standard output channel the number of times the
//              character 'a' appears in the sequence from the input channel.
int main()
{
    char elem_seq;
    unsigned int num = 0;
    while (cin >> elem_seq and elem_seq != '.') {
        // Inv: "num" contains the number of times the character 'a' appeared
        //      in the part of the sequence treated until the now.
        
        if (elem_seq == 'a') ++num;
    }

    cout << num << endl;
}