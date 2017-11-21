/**********************************************************
 * 
 * Author: Ean Milligan
 * Email: milligan.20@wright.edu || ean.milligan@gmail.com
 * Course: CS 3100
 * Prof: Meilin Liu
 * Date: 11/20/17
 * Title: Project 3, Binary Search Tree
 * 
**********************************************************/
////Employee.h provided by Dr. Meilin Liu, and you can modify it if you want.


#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_
#include <iostream>
#include <cstdlib>
#include "Employee.h"

class BinaryTreeNode{
	public:
		Employee person;
		BinaryTreeNode * parent;
		BinaryTreeNode * left;
		BinaryTreeNode * right;
		
		BinaryTreeNode(Employee &newEmployee, BinaryTreeNode *parentptr = NULL, BinaryTreeNode *rightptr = NULL, BinaryTreeNode *leftptr = NULL) {
			person = newEmployee;
			parent = parentptr;
			left = leftptr;
			right = rightptr;
		};

		~BinaryTreeNode() {};
	};
#endif



















