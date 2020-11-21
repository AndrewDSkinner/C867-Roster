#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"
using namespace std;


const int numRecords = 5;

static string studentData[numRecords] =

{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
  "A5,Andrew,Skinner,Askin19@wgu.edu,31, 30,25,15,SOFTWARE"
};


class classRoster { //Stores student records. F2.  Create an instance of the Roster class called classRoster.

private:
	int final; //last student record in roster
	int totalSize; // The maximum size of the roster.
	

public:
	Student** classRosterArray; // Array of pointers.

	classRoster();
	classRoster(int totalSize);
	void Add(string rosterRow); // parses and adds to roster
	void Remove(string sID); // removes from roster per ID
	void PrintAll(); // prints all roster records
	void PrintAvgDaysInCourse(string sID); // Prints average days of course based on Student ID
	void PrintInvalidEmails(); //Prints invalid emails
	void PrintByDegreeProgram(DegreeProgram degreeProgram); // Prints records by degree type
	~classRoster(); // Destroys roster and resources requested
};


