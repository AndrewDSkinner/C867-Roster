#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddr = "";
	this->studentAge = 0;
	this->numDays = new int[dayArraySize];
	for (int i = 0; i < dayArraySize; i++) {
		this->numDays[i] = 0;
	}
	type = UNDECIDED;

}

Student::Student(string sID, string fName, string lName, string eAddr, int age, int nDays[], DegreeProgram dType) {

	this->studentID = sID;
	this->firstName = fName;
	this->lastName = lName;
	this->emailAddr = eAddr;
	this->studentAge = age;

	for (int i = 0; i < dayArraySize; i++) {
		this->numDays[i] = nDays[i];
	}
	this->type = dType;
	


}

// GETTERS

string Student::GetID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAdd() {
	return emailAddr;
}

int Student::GetAge() {
	return studentAge;
}

int * Student::GetNumDays() {
	return numDays;
}
DegreeProgram Student::GetType() {
	return type;
}

// Setters

void Student::SetID(string sID)
{
	studentID = sID;
}

void Student::SetFirstName(string fName)
{
	firstName = fName;
}

void Student::SetLastName(string lName)
{
	lastName = lName;
}

void Student::SetEmailAdd(string eAddr)
{
	emailAddr = eAddr;
}

void Student::SetAge(int age)
{
	studentAge = age;
}

void Student::SetNumDays(int nDays[])
{
	for (int i = 0; i < dayArraySize; i++) {
		numDays[i] = nDays[i];
	}
}



void Student::SetType(DegreeProgram type) {
	this->type = type;
}

void Student::Print() {

	cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << studentAge << "\t" <<
		"daysinCourse: " << "{" << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "} " << "Degree Program: " << degreeProgramString[GetType()];

	/*
	cout << left << setw(3) << studentID;
	cout << left << setw(7) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(24) << emailAddr;
	cout << left << setw(4) << studentAge;
	cout << right << setw(10) << numDays[0];
	cout << right << setw(10) << numDays[1];
	cout << right << setw(10) << numDays[2];
	cout << right << setw(9) << degreeProgramString[GetType()];
*/}

Student::~Student() {

	if (numDays != nullptr) {
		delete[] numDays;
		numDays = nullptr;
	}

}