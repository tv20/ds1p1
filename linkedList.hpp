/***************************************************
Thati Vang
linkedList.hpp
Project 1
***************************************************/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "node.hpp"

class LinkedList{
	Node* head;
	bool occupy;
	void InsertAtHead(std::string,std::string);
public:
	LinkedList();
	LinkedList(std::string,std::string);
		//calls InsertAtHead()
	void SetOccupy(bool);
	bool GetOccupy();
	Node* GetHead();
};

#endif
