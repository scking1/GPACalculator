/*
Scott King
Created: Dec 18, 2024

Menu class definition

*/

#include "Menu.hpp"

void Menu::display_selections() {
	std::for_each(begin(_selections), end(_selections), [i = 0](auto e) mutable { std::cout << ++i << ". " << e << std::endl; });
}

unsigned int Menu::get_selection_input() {
	for (;;) {
		std::string inputStr;
		std::getline(std::cin, inputStr);

		std::istringstream iss(inputStr);
		
		unsigned int input;
		if (!(iss >> input)) {
			//input is not a valid number
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (input <= 0 || input > _selections.size()) {
			//input is not within range of selections
			std::cout << "Input must be between 1-" << _selections.size() << std::endl;
			continue;
		}

		return input;
	}
}

void Menu::add_course(std::vector<Course>& courses) {
	std::cout << "Enter course name: ";
	std::string courseName;
	std::getline(std::cin, courseName);

	for (;;) {
		std::cout << "Enter final course grade: ";

		std::string gradeStr;
		std::getline(std::cin, gradeStr);

		std::istringstream iss(gradeStr);

		double grade;
		if (!(iss >> grade)) {
			//grade not a number
			std::cout << "Invalid input" << std::endl;
			continue;
		}

		if (grade < 0 || grade > 100) {
			//grade not within valid range
			std::cout << "Grade must be between 0-100" << std::endl;
			continue;
		}

		courses.push_back(Course(courseName, grade));
		break;
	}
}

void Menu::display_courses(const std::vector<Course>& courses) {
	if (courses.empty()) {
		std::cout << "No courses to be displayed" << std::endl;
		return;
	}

	for (const auto& c : courses)
		std::cout << c << std::endl;
}
