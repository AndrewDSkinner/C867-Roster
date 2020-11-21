#include <string>
#include <iostream>
#include <iomanip>
#include "Roster.h"
using namespace std;


classRoster::classRoster() { // Empty constructor

	this->totalSize = 0;
	this->final = -1;
	this->classRosterArray = nullptr;
}


classRoster::classRoster(int totalSize) {
	this-> totalSize = totalSize;
	this->final = -1;
	this->classRosterArray = new Student * [totalSize]; // creates array of pointers 

}

void classRoster::Add(string rosterRow) // ADD FUNCTION
{
	if (final < totalSize) {
		final++;
		int rArray[Student::dayArraySize];
		
		if (rosterRow[rosterRow.size() - 1] == 'D')
		{
			this->classRosterArray[final] = new Student();
			classRosterArray[final]->SetType(UNDECIDED);
		}
		
		else if (rosterRow[rosterRow.size() - 1] == 'Y')
		{
			this->classRosterArray[final] = new Student();
			classRosterArray[final]->SetType(SECURITY);
		}
		
		else if (rosterRow[rosterRow.size() - 1] == 'K')
		{
			this->classRosterArray[final] = new Student();
			classRosterArray[final]->SetType(NETWORK);
		}

		else if (rosterRow[rosterRow.size() - 1] == 'E')
		{
			this->classRosterArray[final] = new Student();
			classRosterArray[final]->SetType(SOFTWARE);
		}

		else
		{
			cerr << "INVALID DEGREE TYPE! EXITING!" << endl;
			exit(-1);
		}
		//Sets Student ID
		int rhs = studentData[final].find(",");
		classRosterArray[final]->SetID(studentData[final].substr(0, rhs));
		
		//Sets First Name
		int lhs = rhs + 1;
		rhs = studentData[final].find(",", lhs);
		classRosterArray[final]->SetFirstName(studentData[final].substr(lhs, rhs - lhs));

		//Sets Last Name
		lhs = rhs + 1;
		rhs = studentData[final].find(",", lhs);
		classRosterArray[final]->SetLastName(studentData[final].substr(lhs, rhs - lhs));

		//Sets Email Address
		lhs = rhs + 1;
		rhs = studentData[final].find(",", lhs);
		classRosterArray[final]->SetEmailAdd(studentData[final].substr(lhs, rhs - lhs));

		//Convert string to int for student age and sets Student Age
		lhs = rhs + 1;
		rhs = studentData[final].find(",", lhs);
		classRosterArray[final]->SetAge(stoi(studentData[final].substr(lhs, rhs - lhs)));


		//Convert string to int for days in course array
	
		lhs = rhs + 1;
		rhs = studentData[final].find(",", lhs);
		rArray[0] = stoi(studentData[final].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[final].find(",", lhs);
		rArray[1] = stoi(studentData[final].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[final].find(",", lhs);
		rArray[2] = stoi(studentData[final].substr(lhs, rhs - lhs));

		//Sets Number of Days
		classRosterArray[final]->SetNumDays(rArray);
	
	}
	
	else
	{
		cerr << "ERROR! EXCEEDING MAX CAPACITY" << endl << "EXITING NOW!";
		exit(-1); 
	}
	return;

}
void classRoster::PrintAll() // PRINT ALL
{
	for (int i = 0; i <= this->final; i++)
	{
		(this->classRosterArray)[i]->Print();
		cout << endl;
		cout << endl;
	}
}

void classRoster::Remove(string sID)
{
	bool found = false;

	for(int i = 0; i <= final; i++)
	{
			if (this->classRosterArray[i]->GetID() == sID)
			{
				found = true;

				delete this->classRosterArray[i];
				this->classRosterArray[i] = this->classRosterArray[final];
				final = i + 1;
			}
		}
	if (!found) cout << "ERROR: " << sID << " NOT FOUND";
	}
	





void classRoster::PrintAvgDaysInCourse(string sID) // PRINT AVG DAYS
{
	bool found = false;
	for (int i = 0; i <= final; i++)
	{
		if (this->classRosterArray[i]->GetID() == sID)
		{
			found = true;
			int* d = classRosterArray[i]->GetNumDays();
			cout << "Average number of days " << sID << " is " << (d[0] + d[1] + d[2]) / 3 << "." << endl;
		}
	}
	if (!found) cout << "Record not found!" << endl;
}

void classRoster::PrintInvalidEmails() // PRINT INVALID EMAILS
{
	cout << "Displaying invalid emails." << endl;

	for (int i = 0; i <= final; i++)
	{
		string email = classRosterArray[i]->GetEmailAdd();
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
			cout << "The student email address for: " << classRosterArray[i]->GetEmailAdd() << " is invalid:" << email << endl;
		}

	}
}

void classRoster::PrintByDegreeProgram(DegreeProgram degreeProgram) // PRINT BY DEGREE
{
	cout << "Printing degrees of type " << degreeProgramString[degreeProgram] << endl;
	for (int i = 0; i <= final; i++) {
		if (this->classRosterArray[i]->GetType() == degreeProgram) this->classRosterArray[i]->Print();
		cout << endl;
	}
	
}

classRoster::~classRoster() // F5 Implement the destructor to release the memory that was allocated dynamically in Roster.
{
	for (int i = 0; i < numRecords; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}



