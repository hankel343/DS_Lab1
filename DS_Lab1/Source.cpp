#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

void ProgramMenu(Student &obj);
void ProcessSelection(Student &obj, char selection);

int main()
{
	Student test;
	ProgramMenu(test);
	cout << "Goodbye...\n";
	return 0;
}

void ProgramMenu(Student &obj) {
	char selection;

	do
	{
		cout << "Enter your choice from the menu below: \n\n";

		cout << "1 - Set name\n";
		cout << "2 - Set id\n";
		cout << "3 - Create class\n";
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
	case '1': {
		string name;
		cout << "Enter the name of the student: ";
		cin.ignore(100, '\n');
		getline(cin, name);
		obj.SetName(name);
		break;
	} case '2': {
		int id;
		cout << "Enter the student's id: ";
		cin >> id;
		obj.SetId(id);
		break;
	} case '3': {
		obj.CreateClass(obj);
		break;
	} case '4': {
		obj.GetName();
		break;
	} case '5': {
		obj.GetId();
		break;
	} case '6': {
		string className = "";
		cout << "Here is the list of classes the student has taken: ";
		obj.PrintClasses();
		cout << "\n\nEnter the class name you want the grade for: ";
		cin >> className;
		if (obj.GetClassGrade(obj, className) != '-1') {
			cout << "\n\nEntered class name " << "\"" << className << "\" was not found.\n" << endl;
		} else {
			cout << "Grade for " << "\"" << className << "\": " << obj.GetClassGrade(obj, className) << endl;
		}
		break;
	} case '7': {
		string className;
		cout << "Enter the class name you want the semester for: ";
		cin >> className;
		cout << obj.GetClassSemester(obj, className) << endl;
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