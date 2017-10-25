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

#include "Employee.h"
#include <iostream>

int main() {
	Employee e = Employee();
	std::cin >> e;
	std::cout << e;
	Employee e2 = Employee(e);
	std::cout << e2;
}