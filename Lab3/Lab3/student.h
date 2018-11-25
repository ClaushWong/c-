#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
	public:
		Student(string n) { name = n; }
		void GetPointers() {
			for (int i = 0; i < 4; i++) {
				cout << "For subject no. " << i + 1 << endl;
				cout << "Insert the marks          : "; cin >> points[i];
				cout << "Insert the credit hour(s) : "; cin >> creditHour[i];
				cout << endl;
			}
		}
		void Display() {
			cout << "Student Name : " << name << endl;
			cout << "Student GPA  : ";
			cout << setw(4) << setprecision(3) << CalculateGPA() << endl;
		}
	private:
		double points[4];
		int creditHour[4];
		string name;
		double CalculateGPA() {
			double creditHours = 0;
			double totalPoints = 0;

			for (int i = 0; i < 4; i++) {
				creditHours += creditHour[i];
				totalPoints += (points[i] * creditHour[i]);
			}

			return totalPoints / creditHours;
		}
};
#endif