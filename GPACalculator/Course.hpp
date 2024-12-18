#pragma once
/*
Scott King

A header file to declare and implement a Course class

*/
#include <string>

class Course {
	std::string courseName_;
	double grade_;

public:
	Course() = default;

	//custom constructor
	Course(std::string n, double g) : courseName_(n), grade_(g) {}

	//accessors
	std::string get_course_name() const { return courseName_; }
	double get_grade() const { return grade_; }
};