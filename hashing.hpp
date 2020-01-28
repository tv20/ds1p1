/***************************************************
Thati Vang
hashing.hpp
Project 1
***************************************************/

#ifndef HASHING_HPP
#define HASHING_HPP

#include <fstream>
#include <cctype>
#include <cmath>
#include "userData.hpp"
#include "linkedList.hpp"

class Hashing{
	static const int TABLESIZE = 90000;
	LinkedList* linkedList;	
	std::ifstream openTest;
	std::ofstream writeLinkedList;
		/************************************************************
		This->writeLinkedList will write the linked list out 
		to "linkedList.txt"  that is used for making sure the 
		linked list is performing correctly.
		************************************************************/
	int Hash(std::string);	
		//use of random prime numbers for each letter
public:
	Hashing(std::vector<UserData>);	
		//constructor that takes in vector<UserData> and calls Hash()
		//has the algorithm to write out to "linkedList.txt"	
	void Test();
		/************************************************************
		Opens "raw.txt" and takes the first 5 user IDs and 
		unencrypted pw.
		Encrypt the pw, then searchs through the linked list 
		and matches the encrypted pw.
		Also test for failure by changing one letter to the 
		pw and then encrypt it.
		Writes out to console.
		************************************************************/
};

#endif
