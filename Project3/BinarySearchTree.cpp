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

#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>

BinarySearchTree::BinarySearchTree () : size(0) {
};

BinarySearchTree::~BinarySearchTree () {
};

bool BinarySearchTree::clear() {
	delpost(root);
};

bool BinarySearchTree::insert(Employee& emp) {
	if(size == 0) {
		size++;

		root = new BinaryTreeNode(emp);
		return true;
	} else {
		size++;
		BinaryTreeNode *current = root;
		BinaryTreeNode *currentParent = root;

		while(current != NULL) {
			if(current->person == emp) {
				size--;
				return false;
			} else if(current->person > emp) {
				// Less
				currentParent = current;
				current = current->left;
			} else {
				// Greater
				currentParent = current;
				current = current->right;
			}
		}

		BinaryTreeNode *newNode = new BinaryTreeNode(emp);

		if(currentParent->person > emp) {
			currentParent->left = newNode;
		} else {
			currentParent->right = newNode;
		}
		return true;
	}

};

Employee& BinarySearchTree::search(int k) {
	BinaryTreeNode *c = root;
	int t = 0;
	while(t < size) {
		t++;
		if(c->person.getID() != k) {
			if(c->left == NULL) {
				if(c->right != NULL) {
					c = c->right;
				} else {
					bool a = false;
					while(!a) {
						try {
							c = c->parent;
						}
						catch (exception){}
						if(c->right == NULL) {
							a = false;
						} else {
							a = true;
						}
					}
				}
			} else {
				c = c->left;
			}
		} else {
			return c->person;
		}
	}
};

bool BinarySearchTree::remove(int k) {
	BinaryTreeNode *c = root;
	BinaryTreeNode *d;
	int t = 0;
	while(t < size) {
		t++;
		if(c->person.getID() != k) {
			if(c->left == NULL) {
				if(c->right != NULL) {
					c = c->right;
				} else {
					bool a = false;
					while(!a) {
						c = c->parent;
						if(c->right == NULL) {
							a = false;
						} else {
							a = true;
						}
					}
				}
			} else {
				c = c->left;
			}
		} else {
			size--;
			// delete
			d = c;
			BinaryTreeNode *p = c->parent;
			BinaryTreeNode *l = c->left;
			BinaryTreeNode *r = c->right;

			if(l == NULL && r == NULL) {
				d = NULL;
				return true;
			} else if(l == NULL && r != NULL) {
				d = NULL;
				if(p->person > r->person) {
					p->right = r;
				} else {
					p->left = r;
				}
				return true;
			} else if(l != NULL && r == NULL) {
				d = NULL;
				if(p->person > l->person) {
					p->right = l;
				} else {
					p->left = l;
				}
				return true;
			} else if(l != NULL && r != NULL) {
				// literal fucking hell that is on fucking fire and needs to fucking fuck off and burn in a fucking hole
				BinaryTreeNode *x = r;
				while(x->left != NULL) {
					x = x->left;
				}
				d = x;
				c->person = x->person;
				//delete d;
				d = NULL;
				if(x->right != NULL) {
					x->right->parent = x->parent;
				}
			}

			return true;
		}
	}
	return false;
};

int BinarySearchTree::BSTsize() {
	return size;
};

bool BinarySearchTree::save() {
	std::ofstream outin("inorder.txt");
	std::ofstream outpre("preorder.txt");
	std::ofstream outpost("postorder.txt");
	
	in(root, outin);
	pre(root, outpre);
	post(root, outpost);

	outin.close();
	outpre.close();
	outpost.close();
	return true;
};

void BinarySearchTree::post(struct BinaryTreeNode* node, std::ofstream &s) {
	if (node == NULL)
		return;

	// first recur on left subtree
	post(node->left, s);

	// then recur on right subtree
	post(node->right, s);

	// now deal with the node
	s << "[" << node->person.getID() << "] " << node->person.getLastName() << ", " << node->person.getFirstName() << "; ";
};

void BinarySearchTree::in(struct BinaryTreeNode* node, std::ofstream &s) {
	if (node == NULL)
		return;

	/* first recur on left child */
	in(node->left, s);

	/* then print the data of node */
	s << "[" << node->person.getID() << "] " << node->person.getLastName() << ", " << node->person.getFirstName() << "; ";  

	/* now recur on right child */
	in(node->right, s);
};

void BinarySearchTree::pre(struct BinaryTreeNode* node, std::ofstream &s) {
	if (node == NULL)
		return;

	/* first print data of node */
	s << "[" << node->person.getID() << "] " << node->person.getLastName() << ", " << node->person.getFirstName() << "; ";  

	/* then recur on left sutree */
	pre(node->left, s);  

	/* now recur on right subtree */
	pre(node->right, s);
};

void BinarySearchTree::delpost(BinaryTreeNode* n) {
	if(n!=NULL) {
		delpost(n->left);
		delpost(n->right);
		n = NULL;
	}
};



























