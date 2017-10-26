/**********************************************************
 * 
 * Author: Ean Milligan
 * Email: milligan.20@wright.edu || ean.milligan@gmail.com
 * Course: CS 3100
 * Prof: Meilin Liu
 * Date: 10/25/17
 * Title: Project 2, Singly Linked List
 * 
**********************************************************/
//Employee.h provided by Dr. Meilin Liu, and you can modify it if you want. 

#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>

class Employee{

public:
	Employee();
	Employee(int IdNum, std::string last, std::string first);
	Employee(const Employee &person);
	~Employee();
	void setFirstName(std::string first);
	void setLastName(std::string last);
	void setID(int IdNum);
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	friend std::ostream& operator<<(std::ostream &outs, const Employee &person);
	friend std::istream& operator>>(std::istream &ins, Employee &person);
private:
	int ID;
	std::string lastname;
	std::string firstname;
};

#endif



