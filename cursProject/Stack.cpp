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
	printf("���� ���������\n");
}
void Stack::isEmpty()
{
	if (!lastEl)
	{
		printf("���� ������\n");
		return;
	}
	printf("���� �� ������\n");
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
		printf("�� ������� �������� ������ ��� ���\n");
		return;
	}
	el->value = value;
	if (!node)
	{
		lastEl = el;
		printf("��� ��� ��������\n");
		return;
	}
	if (node == lastEl)
		lastEl = el;
	el->prev = node;
	printf("��� ��� ��������\n");
	print();
}
bool Stack::deleteElement()
{
	NodeStack *node = lastEl;
	if (!node)
	{
		printf("��� �� ����� ���� ������\n\n\n");
		return false;
	}
	NodeStack *prev = node->prev;
	if (!prev)
	{
		lastEl = 0;
		printf("��� ��� ������\n");
		delete[] node;
		return true;
	}
	if (prev)
	{
		if (node == lastEl)
			lastEl = prev;
	}
	printf("��� ��� ������\n");
	delete[] node;
	return true;
}
void Stack::changeElement()
{
	NodeStack *node = lastEl;
	if (!node)
	{
		printf("�������� �� ����������\n");
		return;
	}
	node->value->Open();
	printf("��� �������\n");
}
void Stack::print()
{
	if (!lastEl)
	{
		printf("��� ����\n");
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
		printf("�������� ��������\n");
		node->value->print();
		return;
	}
	printf("�������� �� ����������\n");
}
void Stack::takeElement()
{
	showElement();
	deleteElement();
}

void Stack::Menu()
{
	puts("\n1 ������� ���� ������\n \
		\r2 �������� ���� ����/�� ����\n \
		\r3 �������� �������� ������� �����\n \
		\r4 ������� ������� �����\n \
		\r5 ����� ������� �� �����\n \
		\r6 �������� �������� ������� �����\n \
		\r7 �������� ������� � ����\n \
		\r8 ��������� ������ �� ������ \n ");
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
		printf("�������=");
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
			printf("����� �� �������������");
			break;
		}
		Sleep(500);
	}
}
