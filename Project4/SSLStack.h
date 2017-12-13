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
//The Singly Linked List based Stack header file, SSLStack.h, provided by Dr. Meilin Liu, and you can you can modify it if you want. 

#ifndef _SLLStack_
#define _SLLStack_

#include "Lnode.h"
#include <fstream>

class SLLStack

// This implementation of a Stack using a Singly Linked List.
{
	public:
		SLLStack();
		// Initialize a new stack so that it is empty. 
		SLLStack(const SLLStack &s);
		// The copy constructor (performs initialization).

		~SLLStack();
		// Perform actions needed when stack goes out of scope.

		void push(const std::string &new_item);
		// Place a new item on top of the stack. 
		std::string pop(); 
		// Remove and return the top stack item. Check if stack is empty.
		std::string& top() const;
		// Return top stack item without removing it. 

		// = Check boundary conditions for Stack operations.
		bool is_empty() const;
		// Returns true if the stack is empty, otherwise returns false.

		int size() const;
		// Returns the number of elements in the stack.

		void print() const;
		void print(std::ofstream &s) const;
		//Print all the elements in the stack onto the screen. 

		bool operator == (const SLLStack &s);
		// Checks for Stack equality.

	private:
		Lnode *head;
		// Head of the linked list of <Lnode>.
		int num; 
		//the number of elements in the stack.

};

#endif



