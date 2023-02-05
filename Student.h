//Student.h Header File for Class Declaration, Attributes, and Methods
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

//Student Class
class Student {
	//private Attributes
	string name;
	float GPA;

	//Student Methods
public:

	//Print Method
	void Print() {
		cout << name << "\t" << GPA << endl;	}

	//Constructor
	Student(string name, double GPA) {
		this->name = name;
		this->GPA = GPA;
	}

	//Get Name Method
	string getName() {
		return name;
	}

	//Set Name Method
	void setName(string name) {
		this->name = name;
	}

	//Get GPA Method
	double getGPA() {
		return GPA;
	}

	//Set GPA Method
	void setGPA(double GPA) {
		this->GPA = GPA;
	}
};


