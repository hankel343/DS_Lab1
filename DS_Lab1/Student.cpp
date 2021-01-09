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

void Student::GetClassGrade(int classNumber) {
	if (Classes[classNumber].gradeValue != NULL) {
		std::cout << "Grade: " << Classes[classNumber].letterGrade << std::endl;
		std::cout << "Value: " << Classes[classNumber].gradeValue << std::endl;
	} else {
		std::cout << "\nThis class has no input grade.\n\n";
	}
}

void Student::GetClassSemester(int classNumber) {
	if (Classes[classNumber].semester == "") {
		std::cout << "\nNo semester has been entered for this class.\n\n";
	} else {
		std::cout << Classes[classNumber].semester << std::endl;
	}
}

//Setters
void Student::SetName(std::string inputName) {
	name = inputName;
}

void Student::SetId(int inputId) {
	id = inputId;
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

void Student::SetClassGrade(int classNumber, int inputGrade) {
	Classes[classNumber].letterGrade = SetLetterGrade(inputGrade);
	Classes[classNumber].gradeValue = inputGrade;
}

void Student::SetClassSemester(int classNumber, std::string inputSemester) {
	Classes[classNumber].semester = inputSemester;
}

//Other Methods
void Student::CalculateGpa() {
	float sum = 0.0;
	int i = 0;
	if (Classes[i].gradeValue == NULL && Classes[i].semester == "") {
		std::cout << "\nYou haven't entered any grades yet.\n\n";
	}
	else {
		//Loop through array of class records while i is less than 100 AND the next record isn't empty.
		while (i < 100 && (Classes[i].gradeValue != NULL && Classes[i].semester != "")) {
			sum += Classes[i].gradeValue;
			i++;
		}
		std::cout << std::setprecision(4) << "GPA: " << float(sum) / i << std::endl;
	}
}

void Student::MatchGrade(char inputGrade) {

	int i = 0;
	if (Classes[i].gradeValue == NULL && Classes[i].semester == "") {
		std::cout << "\nThere are no grades to match.\n\n";
	}
	while (i < 100 && (Classes[i].letterGrade != NULL && Classes[i].semester != "")) {
		if (toupper(inputGrade) == Classes[i].letterGrade) {
			std::cout << "Class number: " << i << std::endl;
			std::cout << "Letter grade: " << Classes[i].letterGrade << std::endl;
			std::cout << "Grade value: " << Classes[i].gradeValue << std::endl;
			std::cout << std::endl;
		}
		i++;
	}
}

void Student::PrintClasses() {
		if (Classes[0].gradeValue == NULL && Classes[0].semester == "") {
			std::cout << "\nThere are no classes entered currently.\n\n";
		}
		else {
			int i = 0;
			while (Classes[i].gradeValue != NULL && Classes[i].semester != "") {
				std::cout << "Class number: " << i << std::endl;
				std::cout << "Class grade value: " << Classes[i].gradeValue << std::endl;
				std::cout << "Class letter grade: " << Classes[i].letterGrade << std::endl << std::endl;
				i++;
			}
		}
}