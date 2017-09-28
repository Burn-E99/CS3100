#include <iostream>
#include <string>
#include "Qqueue.h"

int main(){
	Qqueue test = Qqueue(4);
	std::cout<<test.IsEmpty();
	test.print();
	test.enqueue("1");
	test.enqueue("2");
	test.enqueue("3");
	test.enqueue("4");
	test.print();
	test.dequeue();
	std::cout<<std::endl;
	test.enqueue("5");
	test.dequeue();
	test.dequeue();
	test.dequeue();
	test.enqueue("6");
	test.enqueue("7");
	test.enqueue("8");

	std::cout<<test.getfront();
	std::cout<<test.getback();
	std::cout<<test.IsEmpty();
	std::cout<<test.size();
	
	test.print();

	std::cout<<std::endl;

	Qqueue test2 = Qqueue(test);
	test.dequeue();
	test.enqueue("penis");
	
	test2.print();

	std::cout<<test.equals(test2);
}