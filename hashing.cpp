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
