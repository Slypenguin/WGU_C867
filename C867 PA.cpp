#include <iostream>
#include <string>
#include "roster.h"
using std::cout;
using std::string;


int main()

/*STUDENT DATA TABLE INFO*/
{
	cout << "Scripting and Programming - Applications - C867 | C++ | #001117759 | Jacob Brinck" << std::endl;
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jacob,Brinck,jbrinc1@wgu.edu,26,175,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;

	//parse through and print all of the studentData
	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	//invalid email call
	cout << "Displaying students with invalid emails" << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	//avg days in course
	cout << "Displaying average days in course: " << std::endl;
	classRoster.printAverageDaysInCourse("A5");
	cout << std::endl;

	//by degree program
	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	//remove student A3
	cout << "removing student" << std::endl;
	classRoster.remove("A3");
	cout << "removed" << std::endl;

	classRoster.printAll();
	classRoster.remove("A3");


	//All done!
	system("pause");
	return 0;
}