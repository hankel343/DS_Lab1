#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

struct ClassRecord { //Record for storing class information
	std::string name = "";
	int gradeValue = NULL;
	float gpaEquivalent = NULL;
	char letterGrade = NULL;
	std::string semester = "";
};

class Student {
public:
	std::string name = "Hankel";
	int id = NULL;
	int classIndex = 0;
	struct ClassRecord Classes[100]; //Array of records that store class info.
	float gpa = 0.0;

	//Private methods for setting grade information.
	char SetLetterGrade(int inputGradeValue);
	//Pre: A valid integer for a grade has been entered.
	//Post: The corresponding letter grade is recorded for the class.

	float ConvertToGpaScale(int inputGradeValue);
	//Pre: A valid integer representing a grade has been entered.
	//Post: The corresponding gpa value is recorded for the class.

	//Constructor:
	Student();

	//Getters:
	void GetName();
	//Pre: Student object exists.
	//Post: Name field returned

	void GetId();
	//Pre: Student object exists.
	//Post: Id field returned

	char GetClassGrade(Student obj, std::string className);
	//Pre: Student object exists.
	//Post: Class grade returned

	std::string GetClassSemester(Student obj, std::string className);
	//Pre: Student object exists.
	//Post: Class semester returned

	//Setters:
	void SetName(std::string inputName);
	//Pre: Student object exists.
	//Post: Student name returned.

	void SetId(int studentId);
	//Pre: Student object exists.
	//Post: Student id is returned.

	void CreateClass(Student &obj);
	//Pre: Student object exists.
	//Post: Student object now contains a class.

	//Other methods:
	void CalculateGpa();
	//Pre: Student object exists.
	//Post: GPA is calculated and returned.

	void MatchGrade(char inputGrade);
	//Pre: Student object exists.
	//Post: All classes that have a matching grade to the input value are printed to the screen.

	void PrintClasses();
	//Pre: Student object exists.
	//Post: All classes are printed to the console terminal.
};


#endif /*STUDENT_H_*/