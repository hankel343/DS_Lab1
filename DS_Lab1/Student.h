#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

struct ClassRecord { //Record for storing class information
	int gradeValue = NULL;
	char letterGrade;
	std::string semester = "";
};

class Student {
private:
	std::string name;
	int id = NULL;
	struct ClassRecord Classes[100]; //Array of records that stores class info.
	float gpa;

	//Private method for setting grade letter:
	char SetLetterGrade(int inputGradeValue);

public:
	//Constructor:
	Student();

	//Getters:
	void GetName();
	//Pre: Student object exists.
	//Post: Name field returned

	void GetId();
	//Pre: Student object exists.
	//Post: Id field returned

	void GetClassGrade(int classNumber);
	//Pre: Student object exists.
	//Post: Class grade returned

	void GetClassSemester(int classNumber);
	//Pre: Student object exists.
	//Post: Class semester returned

	//Setters:
	void SetName(std::string inputName);
	//Pre: Student object exists.
	//Post: Student name returned.

	void SetId(int inputId);
	//Pre: Student object exists.
	//Post: Student id returned

	void SetClassGrade(int classNumber, int inputGrade);
	//Pre: Student object exists.
	//Post: Class grade returned.

	void SetClassSemester(int classNumber, std::string inputSemester);
	//Pre: Student object exists.
	//Post: Class semester returned.

	//Other methods:
	void CalculateGpa();
	//Pre: Student object exists.
	//Post: GPA is calculated and returned.

	void MatchGrade(char inputGrade);
	//Pre: Student object exists.
	//Post: All classes that have a matching grade to the input value are printed to the screen.

	void PrintClasses();
};


#endif /*STUDENT_H_*/