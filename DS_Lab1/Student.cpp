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
	for (int i = 0; i < 100; i++) {
		if (Classes[i].name == className) {
			return Classes[i].letterGrade;
		}
	}

	return '-1';
}

std::string Student::GetClassSemester(Student obj, std::string className) {
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

	std::cout << "\nEnter the name of the class: ";
	std::cin.ignore(100, '\n');
	while (!(getline(std::cin, className))) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "\aYou have entered invalid data - your input should be a string.\n";
		std::cout << "(i.e. English, Calculus, Art)\n\n";
		std::cout << "Try again: ";
	}

	std::cout << "\nEnter the grade received for this class (integer): ";
	while (!(std::cin >> gradeValue) || !(gradeValue > 0 && gradeValue <= 100)) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "\aYou have entered invalid data - your input should be an integer between 0 and 100 inclusive.\n";
		std::cout << "(i.e 93, 67, 76)\n\n";
		std::cout << "Try again: ";
	}

	std::cout << "\nEnter the semester that this grade was taken: ";
	while (!(std::cin >> semesterInput)) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "\aYou have entered invalid data - your input should be a string.\n";
		std::cout << "(i.e. Fall or Spring)\n\n";
		std::cout << "Try again: ";
	}

	obj.Classes[classIndex].name = className;
	obj.Classes[classIndex].gradeValue = gradeValue;
	obj.Classes[classIndex].letterGrade = SetLetterGrade(gradeValue);
	obj.Classes[classIndex].semester = semesterInput;
	obj.classIndex++; //Increments class index for next class entered.
}

//Other Methods
void Student::CalculateGpa() {
	float sum = 0.0;
	int i = 0, j = 0;
	if (Classes[i].gradeValue == NULL && Classes[i].semester == "") {
		std::cout << "\nYou haven't entered any grades yet.\n\n";
	}
	else {
		//Loop through array of class records while i is less than 100 AND the next record isn't empty.
		for (i = 0; i < 100; i++) {
			if (Classes[i].gradeValue != NULL) {
				sum += Classes[i].gradeValue;
				j++;
			}
		}
		std::cout << std::setprecision(4) << "GPA: " << float(sum) / j << std::endl;
	}
}

void Student::MatchGrade(char inputGrade) {

	int i = 0;
	if (Classes[i].gradeValue == NULL && Classes[i].semester == "") {
		std::cout << "\nThere are no grades to match.\n\n";
	}
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
		}
		else {
			for (int i = 0; i < 100; i++) {
				if (Classes[i].gradeValue != NULL && Classes[i].letterGrade != NULL) {
					std::cout << "\nClass name: " << Classes[i].name << std::endl;
					std::cout << "Class grade value: " << Classes[i].gradeValue << std::endl;
					std::cout << "Class letter grade: " << Classes[i].letterGrade << std::endl;
					if (Classes[i].semester == "") {
						std::cout << "Semester taken: semester not entered.\n" << std::endl;
					} else {
						std::cout << "Semester taken: " << Classes[i].semester << std::endl;
					}
				}
			}
		}
}