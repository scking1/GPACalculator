/*
Scott King

Course class definition

*/
#include "Course.hpp"

Course::Course(std::string n, double g) : _courseName(n), _grade(g) {
	if (_grade >= 90 && _grade <= 100)
		_gradePoint = 4.2;
	else if (_grade >= 80 && _grade < 90)
		_gradePoint = 4.0;
	else if (_grade >= 75 && _grade < 80)
		_gradePoint = 3.5;
	else if (_grade >= 70 && _grade < 75)
		_gradePoint = 3.0;
	else if (_grade >= 65 && _grade < 70)
		_gradePoint = 2.5;
	else if (_grade >= 60 && _grade < 65)
		_gradePoint = 2.0;
	else if (_grade >= 55 && _grade < 60)
		_gradePoint = 1.5;
	else if (_grade >= 50 && _grade < 55)
		_gradePoint = 1.0;
	else
		_gradePoint = 0;
}

std::ostream& operator << (std::ostream& _os, const Course& _c) {
	return _os << _c.get_course_name() << ": " << _c.get_grade() << "% " << "(" << _c.get_grade_point() << ")";
}