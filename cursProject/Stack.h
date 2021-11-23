#pragma once
#include <iostream>
#include "NodeStack.h"
#include "Dack.h"
#include "windows.h"

class Stack
{
	NodeStack* lastEl = 0;
	void Menu();
public:
	void print();
	~Stack();
	void Open();
	void clear();
	void isEmpty();
	void showElement();
	bool deleteElement();
	void changeElement();
	void takeElement();
	void addElement( Dack* value);
};

