/***************************************************
Thati Vang
linkedList.cpp
Project 1
***************************************************/

#include "linkedList.hpp"

LinkedList::LinkedList()
{
	this->head = nullptr;
	this->occupy = false;
}

LinkedList::LinkedList(std::string userId, std::string encryptedPw)
{
	InsertAtHead(userId, encryptedPw);
}

void LinkedList::SetOccupy(bool occupy)
{
	this->occupy = occupy;
}

bool LinkedList::GetOccupy()
{
	return this->occupy;
}

void LinkedList::InsertAtHead(std::string userId, std::string encryptedPw)
{
	Node* tempNode = new Node(userId, encryptedPw);
	
	//set new node's next to the head node's next in case the head points to an existing node
	tempNode->SetNextNode(this->head); 
	
	this->head = tempNode;
	SetOccupy(true);
}

Node* LinkedList::GetHead()
{
	return this->head;
}
