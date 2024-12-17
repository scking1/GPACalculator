#pragma once
/*
Scott King

A header file to declare and implement a Course class

*/
#include <string>

class Course {
	std::string name;
	double grade;

public:
	//custom constructor
	Course(std::string n, double g) : name(n), grade(g) {}

	std::string get_name() const { return name; }
	double get_grade() const { return grade; }
};