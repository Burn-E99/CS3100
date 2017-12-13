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
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string>

int main() {
	std::string el = "\n";
	std::string userCommand;

	HashTable m1 = HashTable();
	HashTable m2 = HashTable();

	std::ifstream allLasts("all.last.txt");
	for(std::string l; getline(allLasts, l);) {
		const unsigned char *m = reinterpret_cast<const unsigned char *>(l.c_str());
		m1.insert(m1.djb2(m)%MaxHashSize, l);
		m2.insert(m2.sdbm(m)%MaxHashSize, l);
	}

	std::cout << "CS3100 Project 4: HashTable" << el;

	while(true) {
		std::cout << el << el << "----------------------------------------------------------------------" << el;
		std::cout << el << "Allowed Operations:" << el;
		std::cout << "	Command		Description" << el;
		std::cout << "----------------------------------------------------------------------" << el;
		std::cout << "	I			Insert new record" << el;
		std::cout << "	D			Delete record" << el;
		std::cout << "	S			Search by last name" << el;
		std::cout << "	L			LogFile" << el;
		std::cout << "	Q			Clear the stack, delete stack, and exit" << el;
		std::cout << el << "Enter the command: ";
		std::cin >> userCommand;

		std::transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);
		std::cout << el << "----------------------------------------------------------------------" << el << el;

		if (userCommand[0] == 'i') {
			std::string l;
			std::cout << "Creating a new record (Capitalization MatTeRS): " << el;
			std::cin >> l;
			
			const unsigned char *m = reinterpret_cast<const unsigned char *>(l.c_str());
			bool result1 = m1.insert(m1.djb2(m)%MaxHashSize, l);
			bool result2 = m2.insert(m2.sdbm(m)%MaxHashSize, l);

			if(result1) {
				std::cout << el << "Inserted record into djb2 HashTable: " << m1.djb2(m)%MaxHashSize << " " << l << el;
			} else {
				std::cout << el << "Failed to insert into djb2 HashTable: " << m1.djb2(m)%MaxHashSize << " " << l << el;
			}
			if(result1) {
				std::cout << el << "Inserted record into sdbm HashTable: " << m2.sdbm(m)%MaxHashSize << " " << l << el;
			} else {
				std::cout << el << "Failed to insert into sdbm HashTable: " << m2.sdbm(m)%MaxHashSize << " " << l << el;
			}
		} else if (userCommand[0] == 'd') {
			std::string l;
			std::cout << "Record to delete (Capitalization MatTeRS): " << el;
			std::cin >> l;
			
			const unsigned char *m = reinterpret_cast<const unsigned char *>(l.c_str());
			bool result1 = m1.del(m1.djb2(m)%MaxHashSize, l);
			bool result2 = m2.del(m2.sdbm(m)%MaxHashSize, l);

			if(result1) {
				std::cout << el << "Deleted record in djb2 HashTable: " << m1.djb2(m)%MaxHashSize << " " << l << el;
			} else {
				std::cout << el << "Failed to delte in djb2 HashTable: " << m1.djb2(m)%MaxHashSize << " " << l << el;
			}
			if(result1) {
				std::cout << el << "Deleted record in sdbm HashTable: " << m2.sdbm(m)%MaxHashSize << " " << l << el;
			} else {
				std::cout << el << "Failed to delete in sdbm HashTable: " << m2.sdbm(m)%MaxHashSize << " " << l << el;
			}
		} else if (userCommand[0] == 's') {
			std::string l;
			std::cout << "Record to find (Capitalization MatTeRS): " << el;
			std::cin >> l;
			
			const unsigned char *m = reinterpret_cast<const unsigned char *>(l.c_str());
			bool result1 = m1.search(m1.djb2(m)%MaxHashSize, l);
			bool result2 = m2.search(m2.sdbm(m)%MaxHashSize, l);

			if(result1) {
				std::cout << el << "Found record in djb2 HashTable: " << m1.djb2(m)%MaxHashSize << " " << l << el;
			} else {
				std::cout << el << "Failed to find in djb2 HashTable: " << m1.djb2(m)%MaxHashSize << " " << l << el;
			}
			if(result1) {
				std::cout << el << "Found record in sdbm HashTable: " << m2.sdbm(m)%MaxHashSize << " " << l << el;
			} else {
				std::cout << el << "Failed to find in sdbm HashTable: " << m2.sdbm(m)%MaxHashSize << " " << l << el;
			}
		} else if (userCommand[0] == 'l') {
			m1.logFile("djb2.txt");
			m2.logFile("sdbm.txt");

			std::cout << el << "Saved to djb2.txt and sdbm.txt" << el;
		} else if (userCommand[0] == 'q') {

			std::cout << "Bye" << el;

			return 1;
		} else {
			std::cout << "Invalid Command " << userCommand << ".  Please try again" << el;
		}
	}
}





















