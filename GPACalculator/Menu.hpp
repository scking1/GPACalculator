#pragma once
/*
Scott King
Created: Dec 18, 2024

Menu class declaration

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class Menu {
	std::vector<std::string> _selections;

public:
	//constructor
	Menu(std::vector<std::string> s) : _selections(s) {}

	//methods
	void display_selections();

	unsigned int get_selection_input();
};