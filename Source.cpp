//Source.cpp File That Carries Out Student File Input, Sorting, and Display
#include"Student.h"
#include <iostream>

//Function Prototypes
void Display(vector<Student> vec);
void Sort(vector<Student> &vec);

using namespace std;

int main() {
	//Variable Declaration
	string name;
	float GPA;
	vector<Student> vec;

	//File Input Declaration
	ifstream students;

	//Set Display to Look Neater
	cout << setprecision(2) << fixed << showpoint;

	//Open Text File
	students.open("Student.txt");


	//Successful Input File Check
	if (!students) {
		cout << "File Cannot be Opened For Reading." << endl;
		exit(1);
	}
	//Else Carry Out Retreiving Information
	else {
		while (students >> name >> GPA) {
			Student func(name, GPA);
			vec.push_back(func);
		}

		//Explicit Close of File
		students.close();
	}

	//Display Information Before Sorting 
	cout << "Student Information Before Sorting: " << endl;
	//Display Function Call
	Display(vec);
	
	//Sort Function Call
	Sort(vec);

	//Display Sorted Information
	cout << endl;
	cout << "Student Information After Sorting: " << endl;
	//Display Function Call
	Display(vec);

	return 0;
}

//Function to Display Information
void Display(vector<Student> vec) {
	cout << "Name \t GPA" << endl;
	cout << "---------" << endl;
	//For Loop to Display Information
	for (int x = 0; x < vec.size(); x++) {
		vec[x].Print();
	}
}

//Function to Sort Information
void Sort(vector<Student> &vec) {

	//Temp Variables to Hold Values While Sorting
	float temp;
	string stringTemp;

	//Loops to Sort Information
	for (int x = 0; x < vec.size(); x++) {
		for (int y = 1 + x; y < vec.size(); y++) {
			if (vec[x].getGPA() > vec[y].getGPA()) {
				temp = vec[x].getGPA();
				vec[x].setGPA(vec[y].getGPA());
				vec[y].setGPA(temp);

				stringTemp = vec[x].getName();
				vec[x].setName(vec[y].getName());
				vec[y].setName(stringTemp);
			}
			//Sort by Name if Duplicate GPA's
			else if (vec[x].getGPA() == vec[y].getGPA()) {
				temp = vec[x].getGPA();
				vec[x].setGPA(vec[y].getGPA());
				vec[y].setGPA(temp);

				stringTemp = vec[x].getName();
				vec[x].setName(vec[y].getName());
				vec[y].setName(stringTemp);
			}
		}
	}
}
