/*
Scott King

Course class definition

*/
#include "Course.hpp"

std::ostream& operator << (std::ostream& _os, const Course& _c) {
	return _os << _c.get_course_name() << ": " << _c.get_grade() << "% ";
}