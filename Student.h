#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Degree.h"
using namespace std;

class Student { //D1 create the class student.

public:
	const static int dayArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddr;
	int studentAge;
	int* numDays;
	DegreeProgram type;

public:

	
	Student(); // empty constructor
	
	Student(string sID, string fName, string lName, string eAddr, int age, int nDays[], DegreeProgram dType);

	// D2A Create Accessors(Getters)
	string GetID(); 
	string GetFirstName();
	string GetLastName();
	string GetEmailAdd();
	int GetAge();
	int* GetNumDays();
	DegreeProgram GetType();

	//Setters

	void SetID(string sID);
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmailAdd(string eAddr);
	void SetAge(int age);
	void SetNumDays(int nDays[]);
	void SetType(DegreeProgram type);
	
	void Print();


	~Student(); 


};