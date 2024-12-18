#pragma once
/*
Scott King

A header file to declare a FileIO class

*/

#include "Course.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class FileIO {
	std::ifstream inFile_;
public:
	//constructor
	FileIO(std::string file) : inFile_(file) {}

	//helper functions
	void parse_file(std::vector<Course>&);
};