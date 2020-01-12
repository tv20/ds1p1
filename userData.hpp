#ifndef USERDATA_HPP
#define USERDATA_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

class UserData{
	std::string userId;
	std::string randomPw;
	std::string encryptedPw;
public:
	UserData();
	UserData(std::string,std::string,bool);
	void SetUserId(std::string);
	void SetRandomPw();
	void SetEncryptedPw();
	std::string GetUserId();
	std::string GetRandomPw();
	std::string GetEncryptedPw();
	void ChangeOneLetter();
};

#endif
