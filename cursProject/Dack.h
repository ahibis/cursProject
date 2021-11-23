#pragma once
#include <iostream>
#include "NodeDack.h"
#include "windows.h"

class Dack {
	NodeDack* firstEl = 0;
	NodeDack* lastEl = 0;
	void addAfterNode(NodeDack* node, int value);
	void addBeforeNode(NodeDack* node, int value);
	bool DeleteNode(NodeDack* node);
	void changeValueOfEl(NodeDack* node, int value);
	void showValueOfEl(NodeDack* node);
	void Menu();
public:
	~Dack();
	void print();
	void Open();
	void clear();
	void isEmpty();
	void showValueOfHead();
	void showValueOfEnd();
	void deleteValueOfHead();
	void deleteValueOfEnd();
	void takeValueOfHead();
	void takeValueOfEnd();
	void changeValueOfHead(int value);
	void changeValueOfEnd(int value);
	void addValueOfHead(int value);
	void addValueOfEnd(int value);
};