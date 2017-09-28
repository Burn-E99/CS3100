#include "Qqueue.h"
#include <iostream>

// Constructor
Qqueue::Qqueue(int c) : Capacity(c) {
	DynamicQueue = new std::string[Capacity];
	
	front = 0;
	back = 0;
	num = 0;
};
//Copier
Qqueue::Qqueue(const Qqueue& q) : Capacity(q.size()) {
	DynamicQueue = new std::string[Capacity];
	front = 0;
	back = q.size();
	num = q.size();

	for (int i=0;i<num;i++) {
		try {
			std::cout<<*(&q.getfront() + i);
			DynamicQueue[i] = *(&q.getfront() + i);
		}
		catch(...) {
			break;
		}
	}
	for (int i=0;i<num;i++) {
		try {
			std::cout<<*(&q.getback() + i);
			DynamicQueue[num - 1 - i] = *(&q.getback() - i);
		}
		catch(...) {
			break;
		}
	}
};

Qqueue::~Qqueue() {
	delete DynamicQueue;
};

void Qqueue::enqueue(const std::string& s) {
	if (num == Capacity) {
		throw;
	}

	DynamicQueue[back%Capacity] = s;
	back++;
	num++;
};

std::string Qqueue::dequeue() {
	if (num == 0) {
		throw;
	}
	std::string temp = DynamicQueue[front];
	DynamicQueue[front] = "";
	front++;
	num--;

	if (front == Capacity) {
		front = 0;
	}

	return temp;
};

std::string& Qqueue::getfront() const {
	if(num == 0) {
		throw;
	}
	return DynamicQueue[front];
};

std::string& Qqueue::getback() const {
	if(num == 0) {
		throw;
	}
	return DynamicQueue[(back-1)%Capacity];
};

bool Qqueue::IsEmpty() const {
	return num == 0;
};

void Qqueue::print() const {

	for (int i=0;i<num;i++) {
		std::cout<<DynamicQueue[(front+i)%Capacity];

		if (i != num - 1) {
			std::cout << ", ";
		}
	}
};

int Qqueue::size() const {
	return num;
};

int Qqueue::getCapacity() const {
	return Capacity;
};

bool Qqueue::equals(const Qqueue& q) const {
	if (num != q.size()) {
		return false;
	}
	bool endCond = true;

	for (int i=0;i<num;i++) {
		if(DynamicQueue[(front+i)%Capacity] != *(&q.getfront() + i)) {
			endCond = false;
			break;
		}
	}
	
	return endCond;
};