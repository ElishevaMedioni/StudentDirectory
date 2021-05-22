//Elisheva Medioni
//sadna c++
//  Student.cpp
//  Created by Elish on 14/06/2020.
//  Copyright © 2020 Elish. All rights reserved.

#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

bool Student::operator<(Student s){
    if(lastName<s.lastName)
       return true;
    if(lastName==s.lastName)
        if(firstName<s.firstName)
            return true;
    return false;
}

bool Student::operator<=(Student s){
    if(lastName<s.lastName or lastName==s.lastName)
        return true;
    return false;
}

bool Student::operator==(Student s){
    return lastName==s.lastName and firstName==s.firstName;
}

Student& Student::operator=(const Student & s){
    id=s.getId();
    lastName=s.getLastName();
    firstName=s.getFirstName();
    return *this;
}

ostream& operator<<(ostream& os, Student s){
    os<<s.id;
    os<<" ";
    os<<s.lastName;
    os<<" ";
    os<<s.firstName;
    os<<endl;
    return os;
}

istream& operator>>(istream& is, Student& s){
    is>>s.id;
    is>>s.lastName;
    is>>s.firstName;
    return is;
}
