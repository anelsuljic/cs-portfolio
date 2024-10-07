//ADD ONE SECOND

//The program adds one second to a clock given in hours, minutes and seconds.
//Input consists of three natural numbers h, m and s that represent a clock 
//time, that is, such that h < 24, m < 60 and s < 60.
//Print the new clock time defined by h, m and s plus one second in the format 
//“HH:MM:SS”.

#include <iostream>

using namespace std;

int main() {
    int hours, minutes, seconds; //hours < 24, min < 60, sec < 60.
    cin >> hours >> minutes >> seconds;
    
    //conversion into seconds and addition of one second.
    int timesec = hours * 3600 + minutes * 60 + seconds;
    ++timesec;
    
    //conversion into hours, minutes and seconds. HH:MM:SS.
    int hour = (timesec / 3600) % 24;
    int min = ((timesec % 3600) / 60) % 60;
    int sec = ((timesec % 3600) % 60) % 60;
    
    cout << hour / 10 << hour % 10 << ':' << min / 10 << min % 10 << ':'
         << sec / 10 << sec % 10 << endl;
}
