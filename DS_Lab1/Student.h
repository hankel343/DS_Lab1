#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

struct ClassRecord { //Record for storing class information
	float grade = 0;
	std::string semester = "";
};

class Student {
private:
	std::string name;
	int id;
	struct ClassRecord Classes[100]; //Array of records that stores class info.
	float gpa;

public:
	//Constructor:
	Student();

	//Getters:
	std::string GetName();
	int GetId();
	float GetClassGrade(int classNumber);
	std::string GetClassSemester(int classNumber);

	//Setters:
	void SetName(std::string inputName);
	void SetId(int inputId);
	void SetClassGrade(int classNumber, char inputGrade);
	void SetClassSemester(int classNumber, std::string inputSemester);

	//Other methods:
	float CalculateGpa();
	void MatchGrade(char inputGrade);
};


#endif /*STUDENT_H_*/