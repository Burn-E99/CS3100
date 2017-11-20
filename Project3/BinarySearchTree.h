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
};


#endif
 
