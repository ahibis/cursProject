#pragma once
class NodeDack //класс узла дека
{
public:
	NodeDack* next = 0;//указатель на следующий элемент
	NodeDack* prev = 0;//указатель на предыдущий элемент
	int value = 0;// значение дека
};

