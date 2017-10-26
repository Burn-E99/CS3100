/**********************************************************
 * 
 * Author: Ean Milligan
 * Email: milligan.20@wright.edu || ean.milligan@gmail.com
 * Course: CS 3100
 * Prof: Meilin Liu
 * Date: 10/25/17
 * Title: Project 2, Singly Linked List
 * 
**********************************************************/
//The Singly Linked List node header file Lnode.h provided by Dr. Meilin Liu, and you can modify it if you want. 

#ifndef _Lnode_
#define  _Lnode_

#include <cstdlib>

class Lnode
{
	public:
		Employee NewEmployee;
		Lnode *next;
		Lnode(Employee NewPerson) {NewEmployee = NewPerson; next = NULL;}
};


#endif



