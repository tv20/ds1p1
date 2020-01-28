/***************************************************
Thati Vang
node.cpp
Project 1
***************************************************/

#include "node.hpp"

Node::Node()
{
	this->userId = "";
	this->encryptedPw = "";
	this->next = nullptr;
}

Node::Node(std::string userId, std::string encryptedPw)
{
	this->userId = userId;
	this->encryptedPw = encryptedPw;
	this->next = nullptr;
}

std::string Node::GetUserId()
{
	return this->userId;
}

std::string Node::GetEncryptedPw()
{
	return this->encryptedPw;
}

Node* Node::GetNextNode()
{
	return this->next;
}

void Node::SetNextNode(Node* next)
{
	this->next = next;
}
