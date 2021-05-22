//Elisheva Medioni 337628390
//sadna c++
//ex11 question2
//  Student.h
//  Created by Elish on 14/06/2020.
//  Copyright © 2020 Elish. All rights reserved.

#ifndef Student_h
#define Student_h
#include <string>
using namespace std;

class Student{
private:
    string id;
    string lastName;
    string firstName;
public:
    Student(){};
    Student(string,string,string):id(" "),lastName(" "),firstName(" "){};
    Student(Student& s):id(s.getId()),lastName(s.getLastName()),firstName(s.getFirstName()){};
    bool operator<(Student);
    bool operator<=(Student);
    Student& operator=(const Student&);
    bool operator==(Student);
    friend ostream& operator<<(ostream& os, Student s);
    friend istream& operator>>(istream& is, Student& s);
    string getId() const {return id;};
    string getLastName() const {return lastName;};
    string getFirstName() const {return firstName;};
    
};

#endif /* Student_h */
