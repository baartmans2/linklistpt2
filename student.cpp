//raymond baartmans
//linked lists one
//student.cpp

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(const char* setName, int setID, float setGpa){  //construct
  strcpy(name, setName);//sets the name to the input
  id = setID;//sets id
  gpa = setGpa; //this sets the gpa
}

Student::~Student(){//destruct
  delete name;
}

char* Student::getName(){//returns the name
  return name;//retruns name
}

int Student::getID(){//returns id
  return id; //returns id
}

float Student::getGpa(){//returns gpa
  return gpa; //returns gpa
}
