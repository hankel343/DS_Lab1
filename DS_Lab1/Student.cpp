#include "Student.h"
#include <iostream>
#include <string>

//Constructor
Student::Student() {};

//Getters
std::string Student::GetName() { return name; }

int Student::GetId() { return id; }

float Student::GetClassGrade(int classNumber) {
	return Classes[classNumber].grade;
}

std::string Student::GetClassSemester(int classNumber) {
	return Classes[classNumber].semester;
}

//Setters
void Student::SetName(std::string inputName) {
	name = inputName;
}

void Student::SetId(int inputId) {
	id = inputId;
}

void Student::SetClassGrade(int classNumber, char inputGrade) {
	Classes[classNumber].grade = inputGrade;
}

void Student::SetClassSemester(int classNumber, std::string inputSemester) {
	Classes[classNumber].semester = inputSemester;
}

//Other Methods
float Student::CalculateGpa() {
	float sum = 0.0;
	int i = 0;
	if (Classes[i].grade == NULL && Classes[i].semester == "") {
		std::cout << "\nYou haven't entered any grades yet.\n";
	}
	else {
		//Loop through array of class records while i is less than 100 AND the next record isn't empty.
		while (i < 100 && (Classes[i++].grade != NULL && Classes[i++].semester != "")) {
			sum += Classes[i].grade;
			i++;
		}
	}

	return sum / i;
}