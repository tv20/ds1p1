#ifndef HASHING_HPP
#define HASHING_HPP

#include <fstream>
#include <cctype>
#include "userData.hpp"
#include "linkedList.hpp"

class Hashing{
	static const int TABLESIZE = 90000;
	LinkedList* linkedList;	
	std::ifstream openTest;
public:
	Hashing(std::vector<UserData>);	
	int Hash(std::string);
	void Test();
};

#endif
