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

#include <algorithm>
#include <iostream>
#include <fstream>
#include "Employee.h"
#include "SSLStack.h"

int main() {
	std::string el = "\n";
	std::string userCommand;
	SLLStack s = SLLStack();

	std::cout << "CS3100 Project 2: SLLStack" << el;

	while(true) {
		std::cout << el << el << "----------------------------------------------------------------------" << el;
		std::cout << el << "Allowed Operations:" << el;
		std::cout << "	Command		Description" << el;
		std::cout << "----------------------------------------------------------------------" << el;
		std::cout << "	P			Push: Add an item to the stack" << el;
		std::cout << "	R			Pop: Remove item[s] from the stack" << el;
		std::cout << "	T			Top: Get the top item" << el;
		std::cout << "	O			Print: Print the whole stack" << el;
		std::cout << "	S			Save: Save all the elements to the disk" << el;
		std::cout << "	Q			Quit: Clear the stack, delete stack, and exit" << el;
		std::cout << el << "Enter the first letter, or full word for each command: ";
		std::cin >> userCommand;

		std::transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);
		std::cout << el << "----------------------------------------------------------------------" << el << el;

		if (userCommand[0] == 'p') {
			Employee e;
			std::cout << "Creating a new Employee" << el;
			std::cin >> e;
			s.push(e);

			std::cout << el << "Total items in stack: " << s.size();
			std::cout << el << "Last five in stack (most recent entry is first in this list): ";

			if (s.size() < 5) {
				s.print();
			} else {
				SLLStack copy = SLLStack(s);
				for (int i=4;i>=0;i--) {
					std::cout << copy.pop();
					if (i != 0) {
						std::cout << "; ";
					}
				}
			}
		} else if (userCommand[0] == 'r') {
			int amount;
			std::cout << "How many items do you want to pop: ";
			std::cin >> amount;
			if (std::cin.fail()) {
				std::cout << "Thats not a number.  Please enter a number between 1 and " << s.size();
				std::cin.clear();
				std::cin.ignore(10, '\n');
			}

			if (amount > s.size()) {
				amount = s.size();
			}

			for (int i=0;i<amount;i++){
				std::cout << s.pop();
				if (i != amount-1) {
					std::cout << "; ";
				}
			}

			std::cout << el << "Total items in stack: " << s.size();
		} else if (userCommand[0] == 't') {
			std::cout << s.top();
		} else if (userCommand[0] == 'o') {
			std::cout << "[ID] Lastname, Firstname" << el;
			s.print();
		} else if (userCommand[0] == 's') {
			std::ofstream out("Stack.txt");
			SLLStack copy = SLLStack(s);
			for (int i=0;i<s.size();i++) {
				out << copy.pop();
				if (i != s.size()-1) {
					out << "; ";
				}
			}
			out.close();
			std::cout << "Stack saved to Stack.txt";
		} else if (userCommand[0] == 'q') {
			while (s.size() != 0) {
				s.pop();
			}
			//delete &s;

			std::cout << "Bye" << el;

			return 1;
		} else {
			std::cout << "Invalid Command " << userCommand << ".  Please try again" << el;
		}
	}
}



