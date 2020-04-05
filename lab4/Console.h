#pragma once
#include "Service.h"
class Console {
private:
	Service s;
public:
	Console();
	void add();
	void remove();
	void update();
	void print();
	void run();
	~Console();
};
void printMenu();