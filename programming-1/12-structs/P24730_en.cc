//NURSERY SCHOOL

//Write a program that reads a list with the given presents, and prints the 
//sorted list of the teachers, from best to worst. 

//Input consists of a natural n followed by an empty line and of n cases, 
//separated by lines in white. Each case consists of a natural t ≥ 1 that 
//indicates the number of teachers. t lines follow, each one with the name of 
//the teacher, the number of given sweets, and the number of given carrots. 
//All the names of the same case are different.
//Output: For each case, print the sorted list of the teachers, from best to 
//worst. It must print each name in a different line, and an empty line at 
//the end of each case.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Defines a type with a teacher's data.
struct Teachers {
    string name;
    int sweets;
    int carrots;
};

//Reads a sequence of teachers data and stores it into a vector.
//Pre: ---------------
//Post: returns Vec.
vector<Teachers> read_data() {
    int size; //vector size
    cin >> size;
    
    vector<Teachers> Vec(size);
    
    //Reads the data
    for (int i = 0; i < size; ++i) {
        cin >> Vec[i].name >> Vec[i].sweets >> Vec[i].carrots;
    }
    
    return Vec;
}

//Compares two teachers's data, following the conditions given.
//Pre: two teacher's data, T1 and T2.
//Post: returns true if T1 follows the conditions. Otherwhise, returns false.
bool compare(Teachers &T1, Teachers &T2) {
    bool result = false;
    
    //Looks the number of sweets
    if (T1.sweets == T2.sweets) {
        //Looks the number of carrots
        if (T1.carrots == T2.carrots) {
            //Looks the name size
            if (T1.name.size() == T2.name.size()) {
                //Looks the lexicographic size
                result = T1.name < T2.name;
            }
            else result = T1.name.size() < T2.name.size();
        }
        else result = T1.carrots > T2.carrots;
    }
    else result = T1.sweets > T2.sweets;
    
    return result;
}

//Prints the elements of a vector
//Pre: a vector of teachers data
//Post: -----------
void print_data(const vector<Teachers> &Vec) {
    int sizeVec = Vec.size();
    
    //Prints the data
    for (int i = 0; i < sizeVec; ++i) {
        cout << Vec[i].name << endl;
    }
}

//Reads, sorts and prints a sequence of teacher vectors
//Pre: ----------
//Post: ----------
void vector_seq() {
    int elemseq; //natural number
    cin >> elemseq;
    
    //Reads and treats every element of the sequence
    for (int i = 0; i < elemseq; ++i) {
        vector<Teachers> Vec = read_data();
        //Sorts the vector following the condition of compare
        sort(Vec.begin(), Vec.end(), compare);       
        //Prints the vector
        print_data(Vec);
        cout << endl;
    }
}

int main() {
    vector_seq();
}
