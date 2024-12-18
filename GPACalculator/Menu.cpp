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
