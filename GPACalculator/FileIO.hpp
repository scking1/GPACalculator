#pragma once
/*
Scott King

A header file to declare and implement a FileIO class

*/

#include <fstream>
#include <sstream>
#include <string>

class FileIO {
	std::ifstream inFile{};
	std::ofstream outFile{};
public:
	//constructor
	FileIO() = default;
};