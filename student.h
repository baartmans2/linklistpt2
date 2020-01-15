//raymond baartmans
//linked lists one
//student.h

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(const char*, int, float);   //construct
  ~Student();//destruct
  char* getName();//get student name
  int getID();//get id
  float getGpa();
 private:
  char* name =  new char[50];//holds name of the student
  int id;//id of the student
  float gpa;
};

#endif
