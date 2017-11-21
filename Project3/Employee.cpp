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

#include "Employee.h"

Employee::Employee() {
	ID = -1;
	lastname = "";
	firstname = "";
};

Employee::Employee(int i, std::string l, std::string f) : ID(i), lastname(l), firstname(f) {};

Employee::Employee(const Employee& e) {
	ID = e.getID();
	firstname = e.getFirstName();
	lastname = e.getLastName();
};

Employee::~Employee() {};

void Employee::setFirstName(std::string f) {
	firstname = f;
};

void Employee::setLastName(std::string l) {
	lastname = l;
};

void Employee::setID(int i) {
	ID = i;
};

int Employee::getID() const {
	return ID;
};

std::string Employee::getFirstName() const {
	return firstname;
};

std::string Employee::getLastName() const {
	return lastname;
};

std::ostream& operator<<(std::ostream& outs, const Employee& e) {
	outs << "[" << e.getID() << "] " << e.getLastName() << ", " << e.getFirstName();
	return outs;
};

std::istream& operator>>(std::istream& ins, Employee& e) {
	int i;
	std::string f;
	std::string l;
	std::cout << "Enter ID: ";
	ins >> i;
	std::cout << "Enter First Name: ";
	ins >> f;
	std::cout << "Enter Last Name: ";
	ins >> l;
	e.setID(i);
	e.setFirstName(f);
	e.setLastName(l);
	return ins;
};

bool Employee::operator > (const Employee &person) {
	return (ID > person.getID());
}
bool Employee::operator < (const Employee &person) {
	return (ID < person.getID());
}
bool Employee::operator >= (const Employee &person) {
	return (ID >= person.getID());
}
bool Employee::operator <= (const Employee &person) {
	return (ID <= person.getID());
}
bool Employee::operator == (const Employee &person) {
	return (ID == person.getID());
}
bool Employee::operator != (const Employee &person) {
	return (ID != person.getID());
}














