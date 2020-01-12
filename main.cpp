#include <iostream>
#include <vector>
#include <ctime>

#include "programManager.hpp"
#include "userData.hpp"

int main()
{
	srand(time(0));

	ProgramManager programManager;

	programManager.OutputFile();

//	programManager.TestProgram();

	return 0;
}
