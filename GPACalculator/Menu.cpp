/*
Scott King
Created: Dec 18, 2024

Menu class definition

*/

#include "Menu.hpp"

void Menu::display_selections() {
	std::for_each(begin(_selections), end(_selections), [i = 0](auto e) mutable { std::cout << ++i << ". " << e << std::endl; });
}

unsigned int Menu::get_selection_choice() {
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
	for (;;) {
		std::cout << "Enter course name (leave blank when done): ";
		std::string courseName;
		std::getline(std::cin, courseName);

		if (courseName.empty())
			break;

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
}

void Menu::display_courses(const std::vector<Course>& courses) {
	if (courses.empty()) {
		std::cout << "No courses to be displayed" << std::endl;
		return;
	}

	for (const auto& c : courses)
		std::cout << c << std::endl;
}

void Menu::load_courses(std::vector<Course>& courses) {
	std::cout << "Enter path to file: ";
	std::string filePath;
	std::getline(std::cin, filePath);

	std::ifstream inFile(filePath);

	if (!inFile) {
		//file doesn't exist
		std::cout << "No such file found." << std::endl;
		return;
	}

	std::string courseDataStr;
	while (std::getline(inFile, courseDataStr)) {
		std::istringstream iss(courseDataStr);

		std::string courseName;
		std::getline(iss, courseName, ',');

		double grade;
		iss >> grade;

		courses.push_back(Course(courseName, grade));
	}
}

double Menu::calculate_term_gpa(const std::vector<Course>& courses) {
	if (courses.empty())
		return -1;
	
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

	return totalGPA / courses.size();
}