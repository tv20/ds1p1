#include "hashing.hpp"

Hashing::Hashing(std::vector<UserData> toHash)
{
	this->linkedList = new LinkedList[this->TABLESIZE];
	int hashNumber;

	for(unsigned int i = 0; i < toHash.size(); i++)
	{
		hashNumber = Hash(toHash.at(i).GetUserId());
		this->linkedList[hashNumber].InsertAtHead(toHash.at(i).GetUserId(),toHash.at(i).GetEncryptedPw());		
	}
/*
	//table used for visualization of linked list
	Node* tempPointer;
	
	for(int i = 0; i < this->TABLESIZE; i++)
	{
		tempPointer = linkedList[i].GetHead();
		
		if(linkedList[i].GetOccupy())
		{
			std::cout << "linkedList[" << i << "]: ";
			
			while(tempPointer != nullptr)
			{
				std::cout << std::setw(14) << std::left << tempPointer->GetUserId();
				tempPointer = tempPointer->GetNextNode();
				
				if(tempPointer == nullptr)
				{
					std::cout << std::endl;
				}
			}
		}
		else
		{
			std::cout << "linkedList[" << i << "]: " << std::endl;
		}
	}
*/
}

int Hashing::Hash(std::string userId)
{
	int hashAlgorithm[] = { 1,  2,  3,  7, 11, 13, 17, 19, 23, 
                               29, 31, 27, 41, 43, 47, 53, 59, 61, 
			       67, 71, 73, 79, 83, 91, 97, 101};

	int digit[userId.length()];
	int position;

	for(unsigned int i = 0; i < userId.length(); i++)
	{
		switch(tolower(userId.at(i)))
		{
			case 'a':
				position = 0;
				break;
			case 'b':
				position = 1;
				break;
			case 'c':
				position = 2;
				break;
			case 'd':
				position = 3;
				break;
			case 'e':
				position = 4;
				break;
			case 'f':
				position = 5;
				break;
			case 'g':
				position = 6;
				break;
			case 'h':
				position = 7;
				break;
			case 'i':
				position = 8;
				break;
			case 'j':
				position = 9;
				break;
			case 'k':
				position = 10;
				break;
			case 'l':
				position = 11;
				break;
			case 'm':
				position = 12;
				break;
			case 'n':
				position = 13;
				break;
			case 'o':
				position = 14;
				break;
			case 'p':
				position = 15;
				break;
			case 'q':
				position = 16;
				break;
			case 'r':
				position = 17;
				break;
			case 's':
				position = 18;
				break;
			case 't':
				position = 19;
				break;
			case 'u':
				position = 20;
				break;
			case 'v':
				position = 21;
				break;
			case 'w':
				position = 22;
				break;
			case 'x':
				position = 23;
				break;
			case 'y':
				position = 24;
				break;
			case 'z':
				position = 25;
				break;
			default:
				break;
		}	
		digit[i] = hashAlgorithm[position];
	}

	//need enough memory to store total using the hashing algorithm, ranges from 0 - 2^64
	unsigned long long int total = 13;

	for(unsigned int i = 0; i < userId.size(); i++)
	{
		if(i % 2 == 0)
		{
			total = total * digit[i];
		}
		else
		{
			total = total + digit[i];
		}
	}	
	
//	std::cout << total << std::endl;

	return total % this->TABLESIZE;
}

void Hashing::Test()
{
	this->openTest.open("raw.txt");
	
	if(this->openTest.fail())
	{
		std::cout << "ERROR" << std::endl;
		exit(-1);
	}

	std::vector<UserData> toTest;
	std::string tempName;
	std::string tempPw;

	for(int i = 0; i < 5; i++)
	{
		this->openTest >> tempName >> tempPw;
		UserData tempUser(tempName, tempPw, 0);
		toTest.push_back(tempUser);
	}
	std::cout << std::setw(44) << "" << std::setw(20) << "ENCRYPTED" << std::endl;
	std::cout << std::setw(41) << "" << std::setw(20) << "IN" << std::endl;
	std::cout << std::setw(15) << std::left << "NAME"
		  << std::setw(20) << std::left << "UNENCRYPTED"
		  << std::setw(20) << std::left << "ENCRYPTED"
		  << std::setw(20) << std::left << "LINKEDLIST"
		  << std::endl;

	for(int i = 0; i < 65; i++)
	{
		std::cout << "-";
	}
	
	std::cout << std::endl << "PASS:" << std::endl << std::endl;

	//test for passing
	for(int i = 0; i < 5; i++)
	{
		int afterHash = Hash(toTest.at(i).GetUserId());
		Node* listPosition = this->linkedList[afterHash].GetHead();
		
		while(listPosition->GetUserId() != toTest.at(i).GetUserId())
		{
			listPosition = listPosition->GetNextNode();
		}
		
		toTest.at(i).SetEncryptedPw();
				
		if(toTest.at(i).GetEncryptedPw() == listPosition->GetEncryptedPw())
		{
			
			std::cout << std::setw(15) << std::left << toTest.at(i).GetUserId()
			          << std::setw(20) << std::left << toTest.at(i).GetRandomPw()
				  << std::setw(14) << std::left << toTest.at(i).GetEncryptedPw() << "=     "
				  << std::setw(20) << std::left << listPosition->GetEncryptedPw()
				  << std::endl;
		}
		else
		{
			std::cout << std::setw(15) << std::left << toTest.at(i).GetUserId()
			          << std::setw(20) << std::left << toTest.at(i).GetRandomPw()
				  << std::setw(13) << std::left << toTest.at(i).GetEncryptedPw() << "!=     "
				  << std::setw(20) << std::left << listPosition->GetEncryptedPw()
				  << std::endl;
		}
	}

	for(int i = 0; i < 65; i++)
	{
		std::cout << "-";
	}
	
	std::cout << std::endl << "FAIL:" << std::endl << std::endl;

	//test for failing
	for(int i = 0; i < 5; i++)
	{
		int afterHash = Hash(toTest.at(i).GetUserId());
		Node* listPosition = this->linkedList[afterHash].GetHead();
		
		while(listPosition->GetUserId() != toTest.at(i).GetUserId())
		{
			listPosition = listPosition->GetNextNode();
		}
		
		toTest.at(i).ChangeOneLetter();
		toTest.at(i).SetEncryptedPw();
			
		if(toTest.at(i).GetEncryptedPw() == listPosition->GetEncryptedPw())
		{
			std::cout << std::setw(15) << std::left << toTest.at(i).GetUserId()
			          << std::setw(20) << std::left << toTest.at(i).GetRandomPw()
				  << std::setw(14) << std::left << toTest.at(i).GetEncryptedPw() << "=     "
				  << std::setw(20) << std::left << listPosition->GetEncryptedPw()
				  << std::endl;
		}
		else
		{
			std::cout << std::setw(15) << std::left << toTest.at(i).GetUserId()
			          << std::setw(20) << std::left << toTest.at(i).GetRandomPw()
				  << std::setw(13) << std::left << toTest.at(i).GetEncryptedPw() << "!=     "
				  << std::setw(20) << std::left << listPosition->GetEncryptedPw()
				  << std::endl;
		}
	}
	this->openTest.close();
}