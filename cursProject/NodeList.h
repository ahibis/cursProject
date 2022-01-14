#pragma once
#include "Stack.h"
class NodeList //класс узла списка
{
public:
	NodeList* next = 0;//указатель на следующий элемент
	NodeList* prev = 0;//указатель на предыдущий элемент
	Stack* value = 0;// значение стэка
};

