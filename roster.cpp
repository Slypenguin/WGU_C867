#include "roster.h"
void Roster::parse(string studentData)
{
	int rightSide = studentData.find(",");
	string studentID = studentData.substr(0, rightSide);

	int leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string firstN = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string lastN = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string emailAdrs = studentData.substr(leftSide, rightSide - leftSide);

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int age = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int dIC1 = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int dIC2 = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int dIC3 = stoi(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	DegreeProgram degreeProgram = SECURITY;
	if (studentData.substr(leftSide, rightSide - leftSide) == "NETWORK") degreeProgram = NETWORK;
	else if (studentData.substr(leftSide, rightSide - leftSide) == "SOFTWARE") degreeProgram = SOFTWARE;
		
	//studentData.substr(leftSide, rightSide - leftSide); enum -> string??

	add(studentID, firstN, lastN, emailAdrs, age, dIC1, dIC2, dIC3, degreeProgram);

}

/*adds student information to classRosterArray*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[0]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[1]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = (Roster::classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos || (emailAddress.find('.') == string::npos || (emailAddress.find(' ') != string::npos)))
		{
			any = true;
			cout << classRosterArray[i]->getStudentID() << ": " << emailAddress << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}


void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getStudentID() << ": ";
		cout << (classRosterArray[i]->getDaysInCourse()[0]
			+ classRosterArray[i]->getDaysInCourse()[1]
			+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
	}
	cout << std::endl;
}

void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << "removed from roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}