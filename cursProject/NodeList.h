#pragma once
#include "Stack.h"
class NodeList
{
public:
	NodeList* next = 0;
	NodeList* prev = 0;
	Stack* value = 0;
};

