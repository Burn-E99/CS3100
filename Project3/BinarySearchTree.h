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
//Employee.h provided by Dr. Meilin Liu, and you can modify it if //you want.

#ifndef _BinarySearchTree_
#define _BinarySearchTree_

#include <cstdlib>
#include "BinaryTreeNode.h"
#include "Employee.h"

using namespace std;

class BinarySearchTree {
	public:
		BinarySearchTree();	//constructor
		~BinarySearchTree();	//destructor
		bool clear();
		bool insert(Employee & emp);
		Employee& search(int k);
		bool remove(int k);
		int BSTsize();
		bool save();
	private:
		BinaryTreeNode * root;
		int size;
		void in(BinaryTreeNode* n, std::ofstream& s);
		void pre(BinaryTreeNode* n, std::ofstream& s);
		void post(BinaryTreeNode* n, std::ofstream& s);
		void delpost(BinaryTreeNode* n);
};


#endif
 

















