//PICA D'ESTATS

//Given a sequence of integer numbers strictly positive ended with 0,
//the program prints if contains any peak greater than 3143 (the height of
//Pica d’Estats). A peak is an integer of the sequence that has a predecessor
//and a successor and it is strictly greater than them.

//Input is a sequence of integer numbers strictly positive ended with 0. At
//least, always there are three integer numbers (not counting the 0).
//Output: The output must be “YES” if there is any peak greater than 3143, and
//“NO” otherwise.

#include <iostream>

using namespace std;

const int MAX_HEIGHT = 3143;

int main() {
    int prev; //integer number
    cin >> prev;

    bool found = false;

    //First reads the three first numbers
    while (not found and prev != 0) {
        int act; //integer number
        cin >> act;

        while (not found and act != 0) {
            int post; //integer number
            cin >> post;

            //Looks for the peak and reads the rest of the sequence
            while (not found and post != 0) {
                found = act > MAX_HEIGHT and act > prev and act > post;

                //Prepares for the next iteration
                prev = act;
                act = post;
                cin >> post;
            }
            //Forces the loop to stop
            act = post;
        }
        //Forces the loop to stop
        prev = act;
    }

    //Sees if a peak is found
    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;
}
