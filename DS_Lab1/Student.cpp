#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>

//Constructor
Student::Student() {};

//Getters
void Student::GetName() {
	if (name == "") {
		std::cout << "\nYou haven't entered a name yet.\n\n";
	} else {
		std::cout << "Student name: " << name << std::endl << std::endl;
	}
}

void Student::GetId() { 
	if (id == NULL) {
		std::cout << "\nYou haven't entered a student id yet.\n\n";
	} else {
		std::cout << "Student id: " << id << std::endl;
	}
}

char Student::GetClassGrade(Student obj, std::string className) {
	//For loop scans through array of structs to find a class with a matching name field and returns its letter grade.
	for (int i = 0; i < 100; i++) {
		if (Classes[i].name == className) {
			return Classes[i].letterGrade;
		}
	}

	//Returns -1 as a flag that the class was not found to print the appropriate message.
	return -1;
}

std::string Student::GetClassSemester(Student obj, std::string className) {
	//For loop scans through array of class structs in Student object to find a matching class name and prints its semester.
	for (int i = 0; i < 100; i++) {
		if (Classes[i].name == className) {
			return Classes[i].semester;
		}
	}

	return "\nUser entered class name does not have an associated semester field.\n";
}

//Setters
void Student::SetName(std::string inputName) {
	name = inputName;
}

void Student::SetId(int studentId) {
	id = studentId;
}

char Student::SetLetterGrade(int inputGradeValue) {
	if (inputGradeValue >= 90 && inputGradeValue <= 100) {
		return 'A';
	} else if (inputGradeValue >= 80 && inputGradeValue < 90) {
		return 'B';
	} else if (inputGradeValue >= 70 && inputGradeValue < 80) {
		return 'C';
	} else if (inputGradeValue >= 60 && inputGradeValue < 70) {
		return 'D';
	} else {
		return 'F';
	}
}

void Student::CreateClass(Student &obj) {
	std::string className, semesterInput;
	int gradeValue;

	//Statement checks if the user has reached the limit of 100 entries for classes.
	if (obj.classIndex == 100) {
		std::cout << "\nThe number of classes allowed has been reached.\n";
		return;
	}

	std::cout << "\nEnter the name of the class: ";
	std::cin.ignore(100, '\n');
	while (!(getline(std::cin, className))) { //While loop used for case of bad data entered into cin stream
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "\aYou have entered invalid data - your input should be a string.\n";
		std::cout << "(i.e. English, Calculus, Art)\n\n";
		std::cout << "Try again: ";
	}

	std::cout << "\nEnter the grade received for this class (integer): ";
	while (!(std::cin >> gradeValue) || !(gradeValue > 0 && gradeValue <= 100)) { //While loop used for case of bad data entered into cin stream
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "\aYou have entered invalid data - your input should be an integer between 0 and 100 inclusive.\n";
		std::cout << "(i.e 93, 67, 76)\n\n";
		std::cout << "Try again: ";
	}

	std::cout << "\nEnter the semester that this grade was taken: ";
	while (!(std::cin >> semesterInput)) { //While loop used for case of bad data entered into cin stream
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "\aYou have entered invalid data - your input should be a string.\n";
		std::cout << "(i.e. Fall or Spring)\n\n";
		std::cout << "Try again: ";
	}

	//Class attributes are set by the following statements from the user's input.
	obj.Classes[classIndex].name = className;
	obj.Classes[classIndex].gradeValue = gradeValue;
	obj.Classes[classIndex].letterGrade = SetLetterGrade(gradeValue);
	obj.Classes[classIndex].gpaEquivalent = ConvertToGpaScale(gradeValue);
	obj.Classes[classIndex].semester = semesterInput;
	obj.classIndex++; //Increments class index for next class entered.
}

//Other Methods
void Student::CalculateGpa() {
	float sum = 0.0;
	int i = 0, j = 0;
	if (Classes[i].gradeValue == NULL && Classes[i].semester == "") { //Checks to see if no data has been entered yet.
		std::cout << "\nYou haven't entered any grades yet.\n\n";
	} else {
		//Loop through array of struct classes and sum all gpa entries that are not empty.
		for (i = 0; i < 100; i++) {
			if (Classes[i].gpaEquivalent != NULL) {
				sum += Classes[i].gpaEquivalent;
				j++; //j counts how many non-zero entries for gpa are found
			}
		}
		std::cout << std::setprecision(4) << "GPA: " << sum / j << std::endl;
	}
}

void Student::MatchGrade(char inputGrade) {

	int i = 0;
	if (Classes[i].gradeValue == NULL && Classes[i].semester == "") { //Checks to see if any grades have been entered yet.
		std::cout << "\nThere are no grades to match.\n\n";
		return;
	}
	//Loop scans through array of struct classes to find structs that have matching letterGrade attributes.
	for (i = 0; i < 100; i++) {
		if (toupper(inputGrade) == Classes[i].letterGrade) {
			std::cout << "Class name: " << Classes[i].name << std::endl;
			std::cout << "Letter grade: " << Classes[i].letterGrade << std::endl;
			std::cout << "Grade value: " << Classes[i].gradeValue << std::endl;
			std::cout << std::endl;
		}
	}
}

void Student::PrintClasses() {
		if (classIndex == 0 && Classes[0].name == "") {
			std::cout << "\nThere are no classes entered currently.\n\n";
			return;
		} else {
			//Scan through array struct classes. Find and print all non-zero entries.
			for (int i = 0; i < 100; i++) {
				if (Classes[i].gradeValue != NULL && Classes[i].letterGrade != NULL) {
					std::cout << "\nClass name: " << Classes[i].name << std::endl;
				}
			}
		}
}

float Student::ConvertToGpaScale(int inputGradeValue) {
	if (inputGradeValue <= 100 && inputGradeValue >= 93) {
		return 4.0;
	} else if (inputGradeValue <= 92 && inputGradeValue >= 90) {
		return 3.7;
	} else if (inputGradeValue <= 89 && inputGradeValue >= 87) {
		return 3.3;
	} else if (inputGradeValue <= 86 && inputGradeValue >= 83) {
		return 3.0;
	} else if (inputGradeValue <= 82 && inputGradeValue >= 80) {
		return 2.7;
	} else if (inputGradeValue <= 79 && inputGradeValue >= 77) {
		return 2.3;
	} else if (inputGradeValue <= 76 && inputGradeValue >= 73) {
		return 2.0;
	} else if (inputGradeValue <= 72 && inputGradeValue >= 70) {
		return 1.7;
	} else if (inputGradeValue <= 69 && inputGradeValue >= 67) {
		return 1.3;
	} else if (inputGradeValue <= 66 && inputGradeValue >= 65) {
		return 1.0;
	} else {
		return 0.0;
	}
}