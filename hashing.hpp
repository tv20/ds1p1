#ifndef HASHING_HPP
#define HASHING_HPP

#include "userData.hpp"
#include "linkedList.hpp"

class Hashing{
	static const int TABLESIZE = 90000;
	LinkedList* linkedList;	
public:
	Hashing(std::vector<UserData>);	
	int Hash(std::string);
};

#endif
