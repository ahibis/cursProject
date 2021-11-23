#include "Stack.h"
void Stack::clear()
{
	if (!lastEl)
		return;
	NodeStack *el = lastEl;
	NodeStack *next;
	while (el)
	{
		deleteElement();
		el = lastEl;
	}
	printf("Стек опустошен\n");
}
void Stack::isEmpty()
{
	if (!lastEl)
	{
		printf("стек пустой\n");
		return;
	}
	printf("стек не пустой\n");
}
Stack::~Stack()
{
	clear();
}
void Stack::addElement(Dack *value)
{
	NodeStack *node = lastEl;
	NodeStack *el = new NodeStack();
	if (!el)
	{
		printf("не удалось выделить память под дек\n");
		return;
	}
	el->value = value;
	if (!node)
	{
		lastEl = el;
		printf("дек был добавлен\n");
		return;
	}
	if (node == lastEl)
		lastEl = el;
	el->prev = node;
	printf("дек был добавлен\n");
	print();
}
bool Stack::deleteElement()
{
	NodeStack *node = lastEl;
	if (!node)
	{
		printf("дек не может быть удален\n\n\n");
		return false;
	}
	NodeStack *prev = node->prev;
	if (!prev)
	{
		lastEl = 0;
		printf("дек был удален\n");
		delete[] node;
		return true;
	}
	if (prev)
	{
		if (node == lastEl)
			lastEl = prev;
	}
	printf("дек был удален\n");
	delete[] node;
	return true;
}
void Stack::changeElement()
{
	NodeStack *node = lastEl;
	if (!node)
	{
		printf("элемента не существует\n");
		return;
	}
	node->value->Open();
	printf("дек изменен\n");
}
void Stack::print()
{
	if (!lastEl)
	{
		printf("дек пуст\n");
	}
	else
	{
		NodeStack *el = lastEl;
		while (el)
		{
			el->value->print();
			el = el->prev;
		}
	}
}

void Stack::showElement()
{
	NodeStack *node = lastEl;
	if (node)
	{
		printf("значение элемента\n");
		node->value->print();
		return;
	}
	printf("элемента не существует\n");
}
void Stack::takeElement()
{
	showElement();
	deleteElement();
}

void Stack::Menu()
{
	puts("\n1 Сделать стек пустым\n \
		\r2 проверка стек пуст/не пуст\n \
		\r3 Показать значение вершины стека\n \
		\r4 Удалить вершину стека\n \
		\r5 Взять элемент из стека\n \
		\r6 Изменить значение вершины стека\n \
		\r7 Добавить элемент в стек\n \
		\r8 Закончить работу со стеком \n ");
}
void Stack::Open()
{
	bool flag = true;
	system("cls");
	while (flag)
	{
		system("cls");
		print();
		Menu();
		printf("Введите=");
		int option;
		Dack *value;
		scanf_s("%i", &option);
		switch (option)
		{
		case 1:
			clear();
			break;
		case 2:
			isEmpty();
			break;
		case 3:
			showElement();
			break;
		case 4:
			deleteElement();
			break;
		case 5:
			takeElement();
			break;
		case 6:
			changeElement();
			break;
		case 7:
			value = new Dack();
			value->Open();
			addElement(value);
			break;
		case 8:
			flag = false;
			break;
		default:
			printf("Опция не действительна");
			break;
		}
		Sleep(500);
	}
}
