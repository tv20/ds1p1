/***************************************************
Thati Vang
programManager.hpp
Project 1
***************************************************/

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
	void WriteEncryptedFile(std::vector<UserData>);  
		//writes user IDs and encrypted pw to encrypted.txt
	void LoadNames();    
		//stores name in userData and generate a random pw
public:
	ProgramManager();  
		//opens lastNames.txt in constructor and calls LoadNames()
	void WriteRawFile(); 
  		//writes user IDs and pw to raw.txtญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญญ
	void ReadRawFile();  
		//reads raw.txt and encrypt pw, calls WriteEncryptedFile()
	void ReadEncryptedFile(std::vector<UserData> &);
		//reads encrypted.txt and store user IDs and encrypted pw in vector of UserData

};

#endif
