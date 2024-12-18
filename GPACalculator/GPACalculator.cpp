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

    for (const auto& c : courses) {
        std::cout << c.get_course_name() << " " << c.get_grade() << std::endl;
    }

}
