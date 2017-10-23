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
	void Employee::setFirstName(string first);
	void Employee::setLastName(string last);
	void Employee::setID(int IdNum);
	int getID();
	std::string getLastName();
	std::string getFirstName();
	friend std::ostream& operator<<(std::ostream &outs, Employee &person);
	friend std::istream& operator>>(std::istream &ins, Employee &person);
private:
	int ID;
	std::string lastname;
	std::string firstname;

	
};


#endif