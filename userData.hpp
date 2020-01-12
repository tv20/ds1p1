#ifndef USERDATA_HPP
#define USERDATA_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class UserData{
	std::string userId;
	std::string randomPw;
	std::string encryptedPw;
	void SetEncryptedPw();
public:
	UserData();
	void SetUserId(std::string);
	void SetRandomPw();
	std::string GetUserId();
	std::string GetRandomPw();
	std::string GetEncryptedPw();
	void PrintInfo(); //function to print out info for testing
};

#endif
