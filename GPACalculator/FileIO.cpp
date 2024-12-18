/*
Scott King
Created: Dec 17, 2024

A cpp file to implement a FileIO class

*/

#include "FileIO.hpp"

void FileIO::parse_file(std::vector<Course>& courses) {
	std::string courseDataStr;

	while (std::getline(inFile_, courseDataStr)) {
		std::istringstream iss(courseDataStr);

		std::string courseName;
		std::getline(iss, courseName, ',');

		double grade;
		iss >> grade;

		courses.push_back(Course(courseName, grade));
	}

}