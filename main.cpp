//Elisheva Medioni
//sadna c++
//  main.cpp
//  Created by Elish on 14/06/2020.
//  Copyright © 2020 Elish. All rights reserved.
//A program that manages the registration of students at the institution

#include <iostream>
using namespace std;
#include "SearchTree.h"
#include "Student.h"

int main()
{
    SearchTree<Student> T1;
    char x;
    Student s(" "," "," ");
    cout<<"enter a-e "<<endl;
    cin >> x;
    while (x != 'e')
    {
        switch (x)
        {
            case 'a': cout << "enter a student "<<endl;
                cin>>s;
                T1.add(s);
                break;
            case 'b': cout << "enter a student " <<endl;
                cin>>s;
                T1.remove(s);
                break;
            case 'c':
                cout << "enter a student "<<endl;
                cin>>s;
                if (T1.search(s))
                    cout<<"exist"<<endl;
                 else
                    cout<<"not exist"<<endl;
                break;
            case 'd':
                T1.inOrder();
                cout << endl;
                break;
        }
        cout << "enter a-e\n";
        cin >> x;
    }
    return 0;
}

/*
 OUTPUT:
 
 enter a-e
 a
 enter a student
 2 b b
 enter a-e
 a
 enter a student
 5 e e
 enter a-e
 a
 enter a student
 1 a a
 enter a-e
 a
 enter a student
 4 d d
 enter a-e
 a
 enter a student
 7 g g
 enter a-e
 a
 enter a student
 3 c c
 enter a-e
 b
 enter a student
 5 e e
 enter a-e
 d
 1 a a
  2 b b
  3 c c
  4 d d
  7 g g
  
 enter a-e
 e
 Program ended with exit code: 0
 */
