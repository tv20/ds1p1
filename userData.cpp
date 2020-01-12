#include "userData.hpp"

UserData::UserData()
{
	this->userId = "";
	this->randomPw = "";
	this->encryptedPw = "";
}

UserData::UserData(std::string userId, std::string encryptedPw)
{
	this->userId = userId;
	this->randomPw = "";
	this->encryptedPw = encryptedPw;
}

void UserData::SetUserId(std::string userId)
{
	this->userId = userId;	
}

void UserData::SetRandomPw()
{
	int randomNum;
	char tempPw[10];
	char alphabet[] = {'a','b','c','d','e','f','g','h','i',
			   'j','k','l','m','n','o','p','q','r',
			   's','t','u','v','w','x','y','z'};

	for(int i = 0; i < 9; i++)
	{
		randomNum = rand() % 26;
		tempPw[i] = alphabet[randomNum];
	}

	this->randomPw = tempPw;

	SetEncryptedPw();
}

void UserData::SetEncryptedPw()
{
	int position;
	int secondPosition;
	char letterToEncrypt;
	char tempEncryptedPw[10];
	char vigenere[][27]={{'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i'},
	  		     {'o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n'},
			     {'n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m'},
			     {'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d'},
			     {'s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r'}};
	
	for(int i = 0; i < 9; i++)
	{
		position = i % 5;
		letterToEncrypt = this->randomPw[i];
		
		switch(letterToEncrypt)
		{
			case 'a':
				secondPosition = 0;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'b':
				secondPosition = 1;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'c':
				secondPosition = 2;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'd':
				secondPosition = 3;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'e':
				secondPosition = 4;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'f':
				secondPosition = 5;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'g':
				secondPosition = 6;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'h':
				secondPosition = 7;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'i':
				secondPosition = 8;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'j':
				secondPosition = 9;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'k':
				secondPosition = 10;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'l':
				secondPosition = 11;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'm':
				secondPosition = 12;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'n':
				secondPosition = 13;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'o':
				secondPosition = 14;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'p':
				secondPosition = 15;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'q':
				secondPosition = 16;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'r':
				secondPosition = 17;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 's':
				secondPosition = 18;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 't':
				secondPosition = 19;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'u':
				secondPosition = 20;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'v':
				secondPosition = 21;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'w':
				secondPosition = 22;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'x':
				secondPosition = 23;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'y':
				secondPosition = 24;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
			case 'z':
				secondPosition = 25;
				letterToEncrypt = vigenere[position][secondPosition];
				break;
		}		
		tempEncryptedPw[i] = letterToEncrypt;
	}
	
	this->encryptedPw = tempEncryptedPw;	
}

std::string UserData::GetUserId()
{
	return this->userId;
}

std::string UserData::GetRandomPw()
{
	return this->randomPw;
}

std::string UserData::GetEncryptedPw()
{
	return this->encryptedPw;
}

void UserData::PrintInfo()
{
	std::cout << std::setw(15) << this->userId 
		  << std::setw(15) << this->randomPw 
		  << std::setw(15) << this->encryptedPw << std::endl;
}
