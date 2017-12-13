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

#include "HashTable.h"
#include "SSLStack.h"
#include <fstream>

HashTable::HashTable() {
	stack = new SLLStack[MaxHashSize];
};

HashTable::~HashTable() {
	delete[] stack;
};

bool HashTable::insert(unsigned long key, std::string name) {
	stack[key].push(name);
	return true;
};

bool HashTable::search(unsigned long key, std::string name) {
	if(stack[key].size() == 0) {
		return false;
	} else {
		SLLStack copy = stack[key];

		for(int i=0;i<copy.size();i++) {
			if(copy.top() == name) {
				return true;
			}
			copy.pop();
		}
		return false;
	}
};

bool HashTable::del(unsigned long key, std::string name) {
	if(stack[key].size() == 0) {
		return false;
	} else {
		SLLStack copy = stack[key];
		SLLStack c2 = SLLStack();
		bool found = false;

		for(int i=0;i<copy.size();i++) {
			if(copy.top() == name) {
				found = true;
			} else {
				c2.push(copy.pop());
			}
		}
		if(found) {
			stack[key] = c2;
		}
		return found;
	}
};

unsigned long HashTable::djb2(const unsigned char *str) {
	unsigned long hash = 5381;

	int c;
	while(c = *str++) {
		hash = ((hash << 5) + hash) + c;
	};
	
	return hash;
};

unsigned long HashTable::sdbm(const unsigned char *str) {
	unsigned long hash = 0;

	int c;
	while(c = *str++) {
		hash = c + (hash << 6) + (hash << 16) - hash;
	};
	
	return hash;
};

void HashTable::logFile(std::string n) {
	std::ofstream o(n.c_str());
	std::string el = "\n";
	int longest = 0;
	int empties = 0;
	o << "Summary at end of file" << el;
	o << "----------------------------------------------------------------------" << el;
	o << "Bucket	Keys" << el;
	o << "----------------------------------------------------------------------" << el;

	for(int i=0;i<MaxHashSize;i++) {
		if(stack[i].size() == 0) {
			empties++;
			o << i << "	EMPTY" << el;
		} else {
			if(longest < stack[i].size()) {
				longest = stack[i].size();
			}
			o << i << "	";
			stack[i].print(o);
			o << el;
		}
	}

	o << el << "----------------------------------------------------------------------" << el;
	o << "Summary: " << el;
	o << "Longest Bucket:	" << longest << el;
	o << "Empty Buckets:	" << empties << el;
};



























