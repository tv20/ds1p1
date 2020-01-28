/***************************************************
Thati Vang
userData.hpp
Project 1
***************************************************/

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
		//constructor that sets instance variables to blank strings
	UserData(std::string,std::string,bool);
		//constructor with parameters that takes in user ID, pw, and bool
		//it will set the name, but depending on the bool value it will
		//either set the argument to randomPw or encryptedPw
	void SetUserId(std::string);
		//set the userId
	void SetRandomPw();
		//random pw seeded with time
	void SetEncryptedPw();
		//encrypted pw is JONES Vigenere Ciper in 2D array
		//use of switch statement to decide which letter to encrypt
	std::string GetUserId();
	std::string GetRandomPw();
	std::string GetEncryptedPw();
	void ChangeOneLetter();
		//changes the first letter of the random pw
};

#endif
