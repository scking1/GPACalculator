/*
Scott King
Created: Dec 17, 2024

This program will calculate the term GPA for a student.

*/

//#include "FileIO.hpp"
#include "Menu.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::cout << "Scott King's GPA Calculator!\n";

	std::vector<std::string> s{ "Add Course","Load Courses","Display Courses","Calculate Term GPA","Exit" };
	Menu m(s);
	std::vector<Course> courses;

	for (;;) {
		std::cout << '\n';
		m.display_selections();

		unsigned int choice{ m.get_selection_choice() };

		switch (choice) {
		case 1:
			std::cout << '\n';
			m.add_course(courses);
			continue;
		case 2:
			std::cout << '\n';
			m.load_courses(courses);
			continue;
		case 3:
			std::cout << '\n';
			m.display_courses(courses);
			continue;
		case 4: {
			double termGPA{ m.calculate_term_gpa(courses) };
			if (termGPA == -1) {
				std::cout << "No courses for the term" << std::endl;
				continue;
			}

			std::cout << "\nTerm GPA achieved: " << termGPA << std::endl;
			continue;
		}
		default:
			std::cout << "\nExiting program..." << std::endl;
			return EXIT_SUCCESS;

		}

	}
}
