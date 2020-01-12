#ifndef PROGRAMMANAGER_HPP
#define PROGRAMMANAGER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "userData.hpp"

class ProgramManager{
	std::vector<UserData> userData;
	std::ifstream openFile;
	std::ofstream writeFile;
	void LoadNames();
public:
	ProgramManager(); //opens lastNames.txt in constructor
	void OutputFile();
	void TestProgram();
};

#endif
