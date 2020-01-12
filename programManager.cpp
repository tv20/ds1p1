#include "programManager.hpp"

ProgramManager::ProgramManager()
{
	this->openFile.open("lastNames.txt");

	if(this->openFile.fail())
	{
		std::cout << "ERROR" << std::endl << std::endl;
		exit(-1);
	}

	LoadNames();

	this->openFile.close();
}

void ProgramManager::LoadNames()
{
	UserData tempUserData;
	std::string tempName;

	while(std::getline(this->openFile, tempName, ' '))
	{
		//move file to next line
		this->openFile.ignore(50,'\n');
	
		//store userId, generate a random pw and encrypt it into a temp variable	
		tempUserData.SetUserId(tempName);
		tempUserData.SetRandomPw();
		
		this->userData.push_back(tempUserData);	
	}
	
}

void ProgramManager::WriteRawFile()
{
	this->writeFile.open("raw.txt");
	
	for(unsigned int i = 0; i < this->userData.size(); i++)
	{
		this->writeFile << std::setw(15) << std::left << userData.at(i).GetUserId() 
			        << std::setw(15) << std::left << userData.at(i).GetRandomPw() << std::endl; 
		//	 	<< std::setw(15) << std::left << userData.at(i).GetEncryptedPw() << std::endl;
	}

	this->writeFile.close();
}

void ProgramManager::ReadRawFile()
{
	this->openFile.open("raw.txt");
	
	if(this->openFile.fail())
	{
		std::cout << "ERROR" << std::endl << std::endl;
		exit(-1);
	}

	std::string tempUserId;
	std::string tempUnencryptedPw;
	std::vector<UserData> toWrite;
	
	while(openFile >> tempUserId >> tempUnencryptedPw)
	{
		UserData tempUserData(tempUserId, tempUnencryptedPw, 0);
		tempUserData.SetEncryptedPw();
		toWrite.push_back(tempUserData);
	}

	this->openFile.close();

	WriteEncryptedFile(toWrite);
}

void ProgramManager::WriteEncryptedFile(std::vector<UserData> toWrite)
{
	this->writeFile.open("encrypted.txt");

	for(unsigned int i = 0; i < toWrite.size(); i++)
	{
		this->writeFile << std::setw(15) << std::left << toWrite.at(i).GetUserId() 
			 	<< std::setw(15) << std::left << toWrite.at(i).GetEncryptedPw() 
				<< std::endl;
	}

	this->writeFile.close();
}

void ProgramManager::ReadEncryptedFile(std::vector<UserData> &toHash)
{
	std::string tempUserId;
	std::string tempEncryptedPw;
	
	this->openFile.open("encrypted.txt");

	if(this->openFile.fail())
	{
		std::cout << "ERROR" << std::endl << std::endl;
		exit(-1);
	}
	
	while(this->openFile >> tempUserId >> tempEncryptedPw)
	{
		UserData tempToHash(tempUserId, tempEncryptedPw, 1);
		toHash.push_back(tempToHash);
	}

}
