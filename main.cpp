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
	
	hashing.Test();
	
	return 0;
}
