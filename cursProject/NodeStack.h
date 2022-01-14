#pragma once
#include "Dack.h"
class NodeStack //класс узла стека
{
public:
	NodeStack* prev = 0;//указатель на предыдущий элемент
	Dack* value = 0;// значение стэка
};

