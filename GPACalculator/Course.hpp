#pragma once
/*
Scott King
Created: Dec 17, 2024

Course class declaration

*/
#include <string>
#include <ostream>

class Course {
	std::string _courseName;
	double _grade;

public:
	Course() = default;

	//custom constructor
	Course(std::string n, double g) : _courseName(n), _grade(g) {}

	//accessors
	std::string get_course_name() const { return _courseName; }
	double get_grade() const { return _grade; }
};

std::ostream& operator << (std::ostream& _os, const Course& _c);