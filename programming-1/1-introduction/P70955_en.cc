//HOW MANY SECONDS ARE THEY?

//The program converts to seconds a given amount of years, days, hours, 
//minutes and seconds.
//The input consists of five natural numbers that represent the years, days, 
//hours, minutes and seconds, respectively.
//Write the total number of seconds represented by the input.

#include <iostream>

using namespace std;

int main() {
    int years, days, hours, minutes, seconds; 
    cin >> years >> days >> hours >> minutes >> seconds;
    
    //Converts into seconds all the variables, and sums all of them.
    int timesec = years * 31536000 + days * 86400 + hours * 3600 + minutes * 
        60 + seconds;
    
    cout << timesec << endl;
}
