//STUDENTS

//Using the definition "Student" implement the procedure "information"
//that computes the minimum mark (min), the maximum mark (max) and the 
//average mark (avg) of all the students of the table stu that have taken the 
//exam and that are not repeaters. If none of the students that has these 
//requirements, the value of these parameters must be −1.

#include <iostream>
#include <vector>

using namespace std;

//Defines the academic data of a student
struct Student {
    int idn;
    string name;
    // The mark is a value between 0 and 10, or -1 that represents NP
    double mark; 
    bool repeater;
};

//Reads a sequence of students academic data and stores it into a vector.
//Pre: a vector of Student type.
//Post: returns Vec.
void read_data(vector<Student> &Vec) {
    int sizeVec = Vec.size();
    
    //Reads the sequence of students academic data.
    for (int i = 0; i < sizeVec; ++i) {
        cin >> Vec[i].idn >> Vec[i].name >> Vec[i].mark;
        
        string rep; //in lowercase
        cin >> rep;
        
        if (rep == "yes") Vec[i].repeater = true;
        else Vec[i].repeater = false;
    }
}

//Calculates the maximum, minimum and average mark of a vector of students.
//Pre: enters a vector of students academic data. max, min and avg are output 
//parameters.
//Post: returns min, max and avg.
void information(const vector<Student>& stu, double& min, double& max, 
                 double& avg) {
    //We don't know if there are presented students or not.
    min = max = avg = -1;
    
    int vecSize = stu.size();
//     double sum = 0; //sum of marks
    int students = 0; //presented and non-repeater students
    
    //Calculates max, min and sum
    for (int i = 0; i < vecSize; ++i) {
        //Only calculates if the student is presented and it doesn't repeat.
        if (stu[i].mark != -1 and not stu[i].repeater) {
            //First student
            if (min == -1) {
                min = stu[i].mark;
                avg = 0;
            }
                
            //Looks for max and min
            if (stu[i].mark > max) max = stu[i].mark;
            else if (stu[i].mark < min) min = stu[i].mark;
                        
            avg += stu[i].mark;
            ++students;
        }
    }
    
    //Calculates average
    if (avg != -1) avg = avg / students;
}

int main() {
    int size; //vector size
    
    while (cin >> size) {
        //Stores the data into a vector.
        vector<Student> Stu(size);
        read_data(Stu);
        
        //Looks for min, max and avg.
        double min, max, avg;
        information(Stu, min, max, avg);
        
        cout << min << ' ' << max << ' ' << avg << endl;
    }
}
