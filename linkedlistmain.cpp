//raymond baartmans
//linked list pt2
//12-19-2019

#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

Node* startnode = NULL;//first node in linked list

void ADD(Node* prev, int id, char* name, float gpa);//adds student to linked list
void PRINT(Node* next);//prints students in linked list out
void DELETE(Node* prev, Node* next, int id);//deletes students from linked list
float AVERAGE(Node* next);//averages grades in linked list

int main()
{
  bool done = false;

  while (!done)
    {
      //vars for user input
      char* input = new char[30];
      int id = 0; float gpa = 0;

      cout << "Enter 'ADD', 'PRINT', 'DELETE', 'AVERAGE', or 'EXIT'. Program is case-sensitive." << endl;
      cin.getline(input, 25, '\n');

      if(strcmp(input, "ADD") == 0)
	{
	  Node* thenode = startnode;
	  
	  cout << "Enter Student Name" << endl;
	  cin.getline(input, 25, '\n');
	  cout << "Enter ID" << endl;
	  cin >> id; cin.clear(); cin.ignore(555555, '\n');
	  cout << "Enter GPA" << endl;
	  cin >> gpa; cin.clear(); cin.ignore(555555, '\n');

	  ADD(thenode, id, input, gpa);//Add it into the list now. 
	}
      else if (strcmp(input, "PRINT") == 0)
	{
	  PRINT(startnode);//Prints out list
	}
      else if (strcmp(input, "DELETE") == 0)
	{
	  if (startnode == NULL)//if no students in list
	  {
	    cout << "List is Empty." << endl;
	  }
	  else
	  {
	    cout << "Enter ID of student to delete." << endl;
	    cin >> id; cin.clear(); cin.ignore(555555, '\n');
	    DELETE(startnode, NULL, id);//deletes student
	  }
	}
      else if (strcmp(input, "AVERAGE") == 0)
	{
	   if (startnode == NULL)//no students
	   {
	     cout << "List is Empty." << endl;
	   }
	   else
	   {
	     cout << "Average GPA: " << AVERAGE(startnode) << endl;//averages gpas and prints them out
	   }
	}
      else if (strcmp(input, "EXIT") == 0)
	{
	  done = true;//Exits
	}
      else//invalid input
	{
	  cout << "Invalid Input. Try Again." << endl;
	}
    }
}

void ADD(Node* prev, int id, char* name, float gpa)
{
  Student* newGuy = new Student(name, id, gpa);
  if(prev == NULL)
  {
    startnode = new Node(newGuy);
    startnode->setStudent(newGuy);
  }

  else if (prev < getStudent()->getID())
  {
    while(prev->getNext() != NULL)
    {
      prev = prev->getNext();
    }
    prev->setNext(new Node(newGuy));
    prev->getNext()->setStudent(newGuy);
  }  
  else
  {
    ADD(prev->getNext(), id, name, gpa);
  }
}

void PRINT(Node* next)
{
  cout << "-Students-" << endl;
  if(next != NULL)
  {//repeat as long as not empty
    cout << "Name: " << next->getStudent()->getName() << ". Student ID: " << next->getStudent()->getID() << ". GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << ". "<<endl;//print student's details
    PRINT(next->getNext());//recursion here until end
  }
}

void DELETE(Node* prev, Node* next, int id)
{

}

float AVERAGE(Node* next)
{
  float sum = 0;//holds the running total for calculating average
  int counter = 0;
  if (next == startnode)
  {
    sum += next -> getStudent() -> getGpa();
    counter++;//adding this counter for when we divide
  }
  while (next -> getNext() != NULL)//run until end of list
  {
    sum += next -> getNext() -> getStudent() -> getGpa();
    counter++;
    next = next -> getNext();
  }
  return (sum/counter);//calculate average
}
