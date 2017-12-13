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

#include "SSLStack.h"

#include <cstdlib>
#include <iostream>
#include <string>

SLLStack::SLLStack () : num(0) {
};

SLLStack::SLLStack (const SLLStack &s) : num(s.size()) {
	Lnode *copy = s.head;
	Lnode *temp;
	for(int i=0;i<num;i++) {
		if(i == 0){
			temp = new Lnode(copy->NewEmployee);
		} else {
			Lnode *oldtemp = temp;
			temp = new Lnode(copy->NewEmployee);
			temp->next = oldtemp;
		}
		copy = copy->next;
	}

	for(int i=0;i<num;i++) {
		if(i == 0){
			head = new Lnode(temp->NewEmployee);
		} else {
			Lnode *oldhead = head;
			head = new Lnode(temp->NewEmployee);
			head->next = oldhead;
		}
		temp = temp->next;
	}
};

SLLStack::~SLLStack () {
	
};

void SLLStack::push(const std::string &e) {
	if(num == 0) {
		head = new Lnode(e);
	} else {
		Lnode *oldhead = head;
		head = new Lnode(e);
		head->next = oldhead;
	}
	num++;
};

std::string SLLStack::pop() {
	if(num == 0) {
		throw;
	}
	num--;
	std::string x = head->NewEmployee;
	head = head->next;
	return x;
};

std::string& SLLStack::top() const {
	if(num == 0) {
		throw;
	}
	return head->NewEmployee;
};

bool SLLStack::is_empty() const {
	return (num == 0);
};

int SLLStack::size() const {
	return num;
};

void SLLStack::print() const {
	if(num == 0) {
		return;
	}
	Lnode *copy = head;

	for(int i=0;i<num;i++) {
		std::cout << copy->NewEmployee;
		if (i != num - 1) {
			std::cout << "; ";
		}
		copy = copy->next;
	}
};

void SLLStack::print(std::ofstream &o) const {
	if(num == 0) {
		return;
	}
	Lnode *copy = head;

	for(int i=0;i<num;i++) {
		o << copy->NewEmployee;
		if (i != num - 1) {
			o << "; ";
		}
		copy = copy->next;
	}
};

bool SLLStack::operator == (const SLLStack &s) {
	SLLStack c1 = SLLStack(s);
	Lnode *c2 = head;

	if(s.size() != num) {
		return false;
	}

	for(int i=0;i<s.size();i++) {
		if((c1.top() == c2->NewEmployee)) {
			c1.pop();
			c2 = c2->next;
		} else {
			return false;
		}
	}
	return true;
};



