#pragma once
#include <iostream>
#include "NodeList.h"
#include "Stack.h"
#include "windows.h"

class List
{
	NodeList* firstEl = 0;
	NodeList* lastEl = 0;
	NodeList* pointer = 0;
	bool DeleteNode(NodeList* node);
	void changeValueOfEl(NodeList* node);
	void movePointerToEl(NodeList* node);
	bool isPointerAt(NodeList* node);
	void showValueOfEl(NodeList* node);
	void Menu();
public:
	void print();
	~List();
	void Open();
	void clear();
	void isEmpty();
	void movePointerToHead();
	void movePointerToEnd();
	void isPointerAtHead();
	void isPointerAtEnd();
	void movePointerToPrev();
	void movePointerToNext();
	void showValueAfterPointer();
	void showValueBeforePointer();
	void deleteValueAfterPointer();
	void deleteValueBeforePointer();
	void takeValueAfterPointer();
	void takeValueBeforePointer();
	void changeValueAfterPointer();
	void changeValueBeforePointer();
	void addValueAfterPointer(Stack* value);
	void addValueBeforePointer(Stack* value);
	void addAfterNode(NodeList* node, Stack* value);
	void addBeforeNode(NodeList* node, Stack* value);
};

