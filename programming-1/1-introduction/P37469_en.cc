//TIME DECOMPOSITION

//Write a program that, given a number of seconds n, prints the number of 
//hours, minutes and seconds represented by n.
//Input consists of a natural number n.
//Output: print three natural numbers h, m, s such that 3600h + 60m + s = n, 
//with m < 60 and s < 60.

#include <iostream>

using namespace std;

int main() {
    int timesec; //natural number
    cin >> timesec;
    
    //converts timesec into hours, minutes, seconds.
    int hours = timesec / 3600;
    int min = (timesec % 3600) / 60;
    int sec = (timesec % 3600) % 60;
    
    //put the time such as hours < 24, minutes < 60, seconds < 60.
    int hourbase = hours;
    int minbase = min % 60;
    int secbase = sec % 60;
   
    cout << hourbase << ' ' << minbase << ' ' << secbase << endl;
}
