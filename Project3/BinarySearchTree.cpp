#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>

BinarySearchTree::BinarySearchTree () : size(0) {
};

BinarySearchTree::~BinarySearchTree () {
};

bool BinarySearchTree::clear() {
	BinaryTreeNode *c = root;
	BinaryTreeNode *d;
	while(root != NULL) {
		if(c->left != NULL) {
			c = c->left;
		} else {
			if(c->right != NULL) {
				c = c->right;
			} else {
				d = c->parent;
				delete c;
				c = d;
			}
		}
	}
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
			// delete
			d = c;
			BinaryTreeNode *p = c->parent;
			BinaryTreeNode *l = c->left;
			BinaryTreeNode *r = c->right;

			if(l == NULL && r == NULL) {
				delete d;
				return true;
			} else if(l == NULL && r != NULL) {
				delete d;
				if(p->person > r->person) {
					p->right = r;
				} else {
					p->left = r;
				}
				return true;
			} else if(l != NULL && r == NULL) {
				delete d;
				if(p->person > l->person) {
					p->right = l;
				} else {
					p->left = l;
				}
				return true;
			} else if(l != NULL && r != NULL) {
				// literal fucking hell that is on fucking fire and needs to fucking fuck off and burn in a fucking hole
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
	BinaryTreeNode *c = root;
	int t = 0;
	std::ofstream out("tree.txt");
	while(t < size) {
		t++;
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

		out << "[" << c->person.getID() << "] " << c->person.getLastName() << ", " << c->person.getFirstName() << "; ";
	}
	out.close();
	return true;
};