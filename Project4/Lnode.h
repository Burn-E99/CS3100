/**********************************************************
 * 
 * Author: Ean Milligan
 * Email: milligan.20@wright.edu || ean.milligan@gmail.com
 * Course: CS 3100
 * Prof: Meilin Liu
 * Date: 12/12/17
 * Title: Project 4, Hash Table
 * 
**********************************************************/
//The Singly Linked List node header file Lnode.h provided by Dr. Meilin Liu, and you can modify it if you want. 

#ifndef _Lnode_
#define  _Lnode_

#include <cstdlib>
#include <string>

class Lnode
{
	public:
		std::string NewEmployee;
		Lnode *next;
		Lnode(std::string NewPerson) {NewEmployee = NewPerson; next = NULL;}
};


#endif



