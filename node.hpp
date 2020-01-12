#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node{
	std::string userId;
	std::string encryptedPw;
	Node* next;
public:
	Node();	
	Node(std::string,std::string);
	std::string GetUserId();
	std::string GetEncryptedPw();
	Node* GetNextNode();
	void SetNextNode(Node*);
};

#endif
