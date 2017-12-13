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

#ifndef _HashTable_
#define _HashTable_

#include <string>
#include "SSLStack.h"

#define MaxHashSize 88801

class HashTable
{
	public:
		HashTable();
		~HashTable();
		bool insert(unsigned long a, std::string b);
		bool search(unsigned long a, std::string b);
		bool del(unsigned long a, std::string b);
		static unsigned long djb2(const unsigned char *str);
		static unsigned long sdbm(const unsigned char *str);
		void logFile(std::string name);
	private:
		SLLStack* stack;


};

#endif


















