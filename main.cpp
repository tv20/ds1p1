#include <iostream>
#include <vector>
#include <ctime>

#include "programManager.hpp"
#include "userData.hpp"
#include "hashing.hpp"

int main()
{
	srand(time(0));

	ProgramManager programManager;

	programManager.WriteRawFile();
	programManager.ReadRawFile();

	std::vector<UserData> toHash;
	programManager.ReadEncryptedFile(toHash);

	Hashing hashing(toHash);
/*
	for(unsigned int i = 0; i < toHash.size(); i++)
	{
		std::cout << std::setw(14) << toHash.at(i).GetUserId()
			  << std::setw(14) << toHash.at(i).GetEncryptedPw()
			  << std::endl;
	}
*/
	return 0;
}
