#include <iostream>
#include <iomanip>
#include <string>
#include "Roster.h"
using namespace std;


int main()
{
	// F1   Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Course Title: Scripting and Programming - Applications__C867" << endl;
	cout << "LANGUAGE USED: C++" << endl;
	cout << "STUDENT ID: 001070408" << endl;
	cout << "STUDENT NAME: ANDREW SKINNER" << endl;

	cout << endl;


	classRoster* ros = new classRoster(numRecords);
	cout << "Parsing data and adding records:\t"; // F3  Add each student to classRoster.
	for (int i = 0; i < numRecords; i++)
	{
		ros->Add(studentData[i]);
	}


	cout << "COMPLETE." << endl;
	cout << "Displaying all records:" << endl;
	ros->PrintAll(); // F4 Prints all records

	cout << endl;

	ros->PrintInvalidEmails(); // Displays invalid emails.

	cout << endl;

	//Print average days in course

	for (int i = 0; i < numRecords; i++) {

		ros->PrintAvgDaysInCourse(ros->classRosterArray[i]->GetID());
	}
	cout << endl;
	ros->PrintByDegreeProgram(SOFTWARE); // Prints by degree type.

	cout << endl;

	cout << "Removing A3:" << endl; // REMOVE RECORD A3
	ros->Remove("A3");

	ros->PrintAll();


	cout << endl;

	cout << "Removing A3:" << endl;
	ros->Remove("A3");


	return 0;
}