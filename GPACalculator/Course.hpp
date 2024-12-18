#pragma once
/*
Scott King

Course class declaration

*/
#include <string>
#include <ostream>

class Course {
	std::string _courseName;
	double _grade;
	double _gradePoint;

public:
	Course() = default;

	//custom constructor
	Course(std::string n, double g);
	//accessors
	std::string get_course_name() const { return _courseName; }
	double get_grade() const { return _grade; }
	double get_grade_point() const { return _gradePoint; }
};

std::ostream& operator << (std::ostream& _os, const Course& _c);