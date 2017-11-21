//Employee.h provided by Dr. Meilin Liu, and you can modify it if you want. 


#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>

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

	bool operator>(const Employee &person);
	bool operator<(const Employee &person);
	bool operator>=(const Employee &person);
	bool operator<=(const Employee &person);
	bool operator==(const Employee &person);
	bool operator!=(const Employee &person);

private:
	int ID;
	std::string lastname;
	std::string firstname;

	
};



#endif