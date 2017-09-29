/**********************************************************
 * 
 * Author: Ean Milligan
 * Email: milligan.20@wright.edu || ean.milligan@gmail.com
 * Course: CS 3100
 * Prof: Meilin Liu
 * Date: 9/28/17
 * Title: Project 1, Qqueue
 * 
**********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Qqueue.h"

int main(){
	std::string el = "\n";
	std::string userCommand;
	Qqueue q = Qqueue(1000);

	std::cout << "CS3100 Project 1: Qqueue" << el;

	while(true) {
		std::cout << el << el << "----------------------------------------------------------------------" << el;
		std::cout << el << "Allowed Operations:" << el;
		std::cout << "	Enqueue: Add an item to the queue" << el;
		std::cout << "	Dequeue: Remove item[s] from the queue" << el;
		std::cout << "	Front: Get the first item" << el;
		std::cout << "	Back: Get the last item" << el;
		std::cout << "	Print: Print the whole queue" << el;
		std::cout << "	Save: Save all the elements to the disk" << el;
		std::cout << "	Quit: Clear the queue, delete queue, and exit" << el;
		std::cout << el << "Enter the first letter, or full word for each command: ";
		std::cin >> userCommand;

		std::transform(userCommand.begin(), userCommand.end(), userCommand.begin(), ::tolower);
		std::cout << el << "----------------------------------------------------------------------" << el << el;

		if (userCommand[0] == 'e') {
			std::string lastname;
			std::cout << "Enter a last name: ";
			std::cin >> lastname;
			q.enqueue(lastname);

			Qqueue t = Qqueue(q);

			std::cout << el << "Total items in queue: " << t.size();
			std::cout << el << "Last five in queue (most recent entry is last in this list): ";

			if (t.size() < 5) {
				t.print();
			} else {
				for (int i=4;i>=0;i--) {
					std::cout << *(&t.getback() - i);
					if (i != 0) {
						std::cout << ", ";
					}
				}
			}

		} else if (userCommand[0] == 'd') {
			int amount;
			std::cout << "How many items do you want to dequeue: ";
			std::cin >> amount;
			if (std::cin.fail()) {
				std::cout << "Thats not a number.  Please enter a number between 1 and " << q.size();
				std::cin.clear();
				std::cin.ignore(10, '\n');
			}

			if (amount > q.size()) {
				amount = q.size();
			}

			for (int i=0;i<amount;i++){
				std::cout << q.dequeue();
				if (i != amount-1) {
					std::cout << ", ";
				}
			}

			std::cout << el << "Total items in queue: " << q.size();

		} else if (userCommand[0] == 'f') {
			std::cout << q.getfront();
		} else if (userCommand[0] == 'b') {
			std::cout << q.getback();
		} else if (userCommand[0] == 'p') {
			q.print();
		} else if (userCommand[0] == 's') {
			std::ofstream out("Qqueue.txt");
			Qqueue t = Qqueue(q);
			for (int i=0;i<t.size();i++) {
				out << *(&t.getfront() + i);
				if (i != t.size()-1) {
					out << ", ";
				}
			}
			out.close();

			std::cout << "Queue saved to Qqueue.txt";
		} else if (userCommand[0] == 'q') {
			while (q.size() != 0) {
				q.dequeue();
			}
			
			std::cout << "Bye" << el;

			return 1;
		} else {
			std::cout << "Invalid Command " << userCommand << ".  Please try again" << el;
		}
	}
}

/*
Initial method testing

Qqueue test = Qqueue(4);
std::cout << test.IsEmpty();
test.print();
test.enqueue("1");
test.enqueue("2");
test.enqueue("3");
test.enqueue("4");
test.print();
test.dequeue();
std::cout << std::endl;
test.enqueue("5");
test.dequeue();
test.dequeue();
test.dequeue();
test.enqueue("6");
test.enqueue("7");
test.enqueue("8");

std::cout << test.getfront();
std::cout << test.getback();
std::cout << test.IsEmpty();
std::cout << test.size();

test.print();

std::cout << std::endl;

Qqueue test2 = Qqueue(test);
test.dequeue();
test.enqueue("penis");
test.print();
test2.print();

std::cout << test.equals(test2);
std::cout << std::endl;
*/