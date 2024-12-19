#pragma once
/*
Scott King
Created: Dec 18, 2024

Menu class declaration

*/

#include "Course.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

class Menu {
	std::vector<std::string> _selections;

public:
	//constructor
	Menu(std::vector<std::string> s) : _selections(s) {}

	//methods
	void display_selections();
	unsigned int get_selection_choice();
	void add_course(std::vector<Course>&);
	void display_courses(const std::vector<Course>&);
	void load_courses(std::vector<Course>&);
	double calculate_term_gpa(const std::vector<Course>&);
};