/*
Scott King

This program will calculate the term GPA for a student.

*/

#include "FileIO.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::cout << "Scott King's GPA Calculator!\n";

    std::vector<Course> courses;
    FileIO fileIO{ "./course_term_grades_2.csv" };

    //populate the vector
    fileIO.parse_file(courses);

    double totalGPA{};
    for (const auto& c : courses) {
		double grade{ c.get_grade() };

		if (grade >= 90 && grade <= 100)
			totalGPA += 4.2;
		else if (grade >= 80 && grade < 90)
			totalGPA += 4.0;
		else if (grade >= 75 && grade < 80)
			totalGPA += 3.5;
		else if (grade >= 70 && grade < 75)
			totalGPA += 3.0;
		else if (grade >= 65 && grade < 70)
			totalGPA += 2.5;
		else if (grade >= 60 && grade < 65)
			totalGPA += 2.0;
		else if (grade >= 55 && grade < 60)
			totalGPA += 1.5;
		else if (grade >= 50 && grade < 55)
			totalGPA += 1.0;
    }

	std::cout << std::fixed << std::setprecision(2);
    std::cout << "Term GPA achieved: " << totalGPA / courses.size() << std::endl;

    std::cout << "\nCourses:" << std::endl;
    for (const auto& c : courses) {
        std::cout << c << std::endl;
    }

}
