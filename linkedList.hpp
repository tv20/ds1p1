#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "node.hpp"

class LinkedList{
	Node* head;
	bool occupy;
public:
	LinkedList();
	LinkedList(std::string,std::string);
	void SetOccupy(bool);
	bool GetOccupy();
	void InsertAtHead(std::string,std::string);
	Node* GetHead();
};

#endif
