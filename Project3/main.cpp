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

#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string>

int main() {
	std::string el = "\n";
	std::string userCommand;
	BinarySearchTree s = BinarySearchTree();

	std::cout << "CS3100 Project 3: BinarySearchTree" << el;

	while(true) {
		std::cout << el << el << "----------------------------------------------------------------------" << el;
		std::cout << el << "Allowed Operations:" << el;
		std::cout << "	Command		Description" << el;
		std::cout << "----------------------------------------------------------------------" << el;
		std::cout << "	I			Insert new record" << el;
		std::cout << "	D			Delete record" << el;
		std::cout << "	E			Search for employee" << el;
		std::cout << "	S			Save all the elements to the disk" << el;
		std::cout << "	Q			Clear the stack, delete stack, and exit" << el;
		std::cout << el << "Enter the command: ";
		std::cin >> userCommand;

		std::transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);
		std::cout << el << "----------------------------------------------------------------------" << el << el;

		if (userCommand[0] == 'i') {
			Employee e;
			std::cout << "Creating a new Employee" << el;
			std::cin >> e;
			
			bool result = s.insert(e);

			if(result) {
				std::cout << el << "Inserted record: " << e << el;
			} else {
				std::cout << el << "Failed to insert: " << e << el;
			}
		} else if (userCommand[0] == 'd') {
			int amount;
			std::cout << "Record ID: ";
			std::cin >> amount;
			if (std::cin.fail()) {
				std::cout << "Thats not a number.";
				std::cin.clear();
				std::cin.ignore(10, '\n');
			}

			bool result = s.remove(amount);

			if(result) {
				std::cout << el << "Success" << el;
			} else {
				std::cout << el << "ID does not exist" << el;
			}
		} else if (userCommand[0] == 'e') {
			int amount;
			std::cout << "Record ID: ";
			std::cin >> amount;
			if (std::cin.fail()) {
				std::cout << "Thats not a number.";
				std::cin.clear();
				std::cin.ignore(10, '\n');
			}

			Employee result = s.search(amount);

			std::cout << el << "Success, found 1 record out of " << s.BSTsize() << "." << el;
			std::cout << el << result << el;
		} else if (userCommand[0] == 's') {
			s.save();

			std::cout << el << "Saved to inorder.txt, preoder.txt, and postorder.txt" << el;
		} else if (userCommand[0] == 'q') {
			s.clear();

			std::cout << "Bye" << el;

			return 1;
		} else {
			std::cout << "Invalid Command " << userCommand << ".  Please try again" << el;
		}
	}
}





















