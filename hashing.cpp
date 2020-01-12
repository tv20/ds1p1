#include "hashing.hpp"

Hashing::Hashing(std::vector<UserData> toHash)
{
	this->linkedList = new LinkedList[this->TABLESIZE];
	int hashNumber = 0;

	for(unsigned int i = 0; i < toHash.size(); i++)
	{
		//int hashNumber = hash(toHash.at(i));
		this->linkedList[hashNumber].InsertAtHead(toHash.at(i).GetUserId(),toHash.at(i).GetEncryptedPw());		
	}

/*
	Node* tempPointer = linkedList[0].GetHead();

	while(true)
	{
		std::cout << tempPointer->GetUserId() << std::endl;
		tempPointer = tempPointer->GetNextNode();
		
		if(tempPointer->GetNextNode() == nullptr)
		{
			std::cout << tempPointer->GetUserId() << std::endl;
			return;
		}
	}
*/
	//std::cout << this->linkedList[0].GetHead()->GetEncryptedPw() << std::endl;
	//std::cout << this->linkedList[0].GetHead()->GetNextNode()->GetUserId() << std::endl;
	//std::cout << this->linkedList[0].GetHead()->GetNextNode()->GetNextNode()->GetUserId() << std::endl;
}

int Hashing::Hash(std::string userId)
{
	return 1;
}
