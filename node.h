#include <iostream>
#include <cstring>
#include <vector>

#ifndef NODE_H
#define NODE_H

#include "student.h"

using namespace std;

class Node{ //initialize functions
 public:
  Node(); //constructor
  void setStudent(Student*);
  Student* getStudent();
  void setNext(Node* newNext); // set next pointer to corresponding node pointer
  Node* getNext(); //get next node pointer
  ~Node(); // destructor
 private:
  //char* nodeName; //is thi
  Student* student;
  Node* next;

};

#endif