#include "Student.h"
#include <iostream>

using namespace std;

int main() {

	Student Me;
	Me.SetName("Betty");
	Me.SetId(123456);
	Me.SetClassGrade(0, 89);
	cout << Me.GetClassGrade(0) << endl;

	return 0;
}