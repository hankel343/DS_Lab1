#include "Student.h"
#include <iostream>


using namespace std;

int main() {

	Student Me;
	Me.SetName("Hankel");
	Me.SetId(123456);

	Me.GetName();
	Me.GetId();
	
	Me.SetClassGrade(0, 89);
	Me.SetClassSemester(0, "Spring");

	Me.SetClassGrade(1, 91);
	Me.SetClassSemester(1, "Spring");

	Me.SetClassGrade(2, 76);
	Me.SetClassSemester(2, "Spring");

	Me.SetClassGrade(3, 93);
	Me.SetClassSemester(3, "Spring");

	Me.SetClassGrade(4, 95);
	Me.SetClassSemester(4, "Spring");

	Me.SetClassGrade(5, 71);
	Me.SetClassSemester(5, "Spring");

	Me.MatchGrade('q');

	Me.CalculateGpa();

	

	return 0;
}