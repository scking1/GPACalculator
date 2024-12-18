/*
Scott King

This program will calculate the term GPA for a student.

*/

#include "FileIO.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Scott King's GPA Calculator!\n";

    std::vector<Course> courses;
    FileIO fileIO{ "./course_term_grades.csv" };

    //populate the vector
    fileIO.parse_file(courses);

    double totalGPA{};
    for (const auto& c : courses)
        totalGPA += c.get_grade_point();

    std::cout << "Term GPA achieved: " << totalGPA / courses.size() << std::endl;

    std::cout << "\nCourses:" << std::endl;
    for (const auto& c : courses) {
        std::cout << c << std::endl;
    }

}
