#include "Student.h"
#include <iostream>

using namespace std;

void ProgramMenu(Student &obj);
void ProcessSelection(Student &obj, char selection);

int main()
{
	Student test;
	ProgramMenu(test);

	return 0;
}

void ProgramMenu(Student &obj) {
	char selection;

	do
	{
		cout << "Enter your choice from the menu below: \n\n";

		cout << "0 - Set name\n";
		cout << "1 - Set id\n";
		cout << "2 - Set class grade\n";
		cout << "3 - Set class semester\n";
		cout << "4 - Get name\n";
		cout << "5 - Get id\n";
		cout << "6 - Get class grade\n";
		cout << "7 - Get class semester\n";
		cout << "8 - Calculate GPA\n";
		cout << "9 - Match a specific grade\n";
		cout << "P - Print all classes\n";
		cout << "Q - Quit\n";

		cout << "Enter your selection: ";
		cin >> selection;

		system("cls");

		ProcessSelection(obj, selection);
		
	} while (toupper(selection) != 'Q');
}

void ProcessSelection(Student &obj, char selection) {

	switch (toupper(selection)) {
	case '0': {
		string name;
		cout << "Enter the name of the student: ";
		cin >> name;
		obj.SetName(name);
		break;
	} case '1': {
		int id;
		cout << "Enter the student's id: ";
		cin >> id;
		obj.SetId(id);
		break;
	} case '2': {
		int classNum, gradeValue;
		cout << "Enter the class number: ";
		cin >> classNum;
		cout << "\nEnter the grade received (integer): ";
		cin >> gradeValue;
		obj.SetClassGrade(classNum, gradeValue);
		break;
	} case '3': {
		int classNum;
		string inputSemester;
		cout << "Enter the class number: ";
		cin >> classNum;
		cout << "\nEnter the semester the class was taken (fall/spring): ";
		cin >> inputSemester;
		obj.SetClassSemester(classNum, inputSemester);
		break;
	} case '4': {
		obj.GetName();
		break;
	} case '5': {
		obj.GetId();
		break;
	} case '6': {
		int classNum;
		cout << "Enter the class number you want the grade for: ";
		cin >> classNum;
		obj.GetClassGrade(classNum);
		break;
	} case '7': {
		int classNum;
		cout << "Enter the class number you want the semester for: ";
		cin >> classNum;
		obj.GetClassSemester(classNum);
		break;
	} case '8': {
		obj.CalculateGpa();
		break;
	} case '9': {
		char letterGrade;
		cout << "Enter the letter grade you want to match: ";
		cin >> letterGrade;
		obj.MatchGrade(letterGrade);
		break;
	} case 'P': {
		obj.PrintClasses();
	} case 'Q': {
		break;
	} default: {
		cout << "Unknown selection - try again.\n";
		break;
	}
	}

	
}