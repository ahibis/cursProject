#include "Dack.h"
void Dack::addAfterNode(NodeDack *node, int value) //���������� �������� ����� node
{
	NodeDack *el = new NodeDack(); //������� ����� ����
	if (!el)
	{
		printf("�� ������� �������� ������ ��� �������\n");
		return;
	}
	el->value = value; //�������� �������� ������ ����
	if (!node)		   //���� node �� ��������� ������ el ������ � ����
	{
		firstEl = el;
		lastEl = el;
		printf("??????? %i ??? ????????\n", value);
		return;
	}
	if (node == lastEl)
		lastEl = el; //???? ??????? ????? ???????? ??????????? ??????? ?????????, ?? ?????? ????????? ????? ???????
	if (node->next)
	{ //???? ?????????? ????????? ???? ?????? ?????? ????? ???????? ?? node ? ????????
		el->next = node->next;
		node->next->prev = el;
	}
	el->prev = node; //????????? ?????? ?????? ???? ?? ?????????? ???????
	node->next = el; //????????? ?????? ?? ????????? ???????
	printf("??????? %i ??? ????????\n", value);
}
void Dack::addBeforeNode(NodeDack *node, int value)
{								   //?????????? ???? ????? ????? node
	NodeDack *el = new NodeDack(); //??????? ????? ???? ????
	if (!el)
	{
		printf("?? ??????? ???????? ?????? ??? ???????\n");
		return;
	}
	el->value = value; //???????? ???????? ????
	if (!node)
	{ //???? ??? ???? ????????? ??????? ??????
		firstEl = el;
		lastEl = el;
		printf("??????? %i ??? ????????\n", value);
		print();
		return;
	}
	if (node == firstEl)
		firstEl = el; //???? ??????? ????? ??????? ??????????? ??????? ??????, ?? ?????? ?????? ????? ???????
	if (node->prev)
	{ //???? ?????????? ?????????? ???? ?????? ?????? ????? ???????? ?? node ? ????????
		el->prev = node->prev;
		node->prev->next = el;
	}
	el->next = node; //????????? ?????? ?????????? ???? ?? ?????????? ???????
	node->prev = el; //????????? ?????? ?? ?????????? ??????? ? node
	printf("?????? %i ??? ????????\n", value);
	print();
}
bool Dack::DeleteNode(NodeDack *node)
{ //???????? ???? node
	if (!node)
	{ //???? ???????? ?? ??????????, ??????? ?? ???????
		printf("??????? ?? ????? ???? ??????\n\n\n");
		return false;
	}
	NodeDack *prev = node->prev; //????????? ?????????? ??????? ????
	NodeDack *next = node->next; //????????? ????????? ??????? ????
	if (!prev && !next)
	{ //???? ??????? ????????? ?? ???????? ???? ???
		firstEl = 0;
		lastEl = 0;
		printf("??????? %i ??? ??????\n", node->value);
		delete[] node;
		return true;
	}
	if (next)
	{					   //???? ?????????? ????????? ????
		next->prev = prev; // ?? ???????? ?????? ??????????? ???????? ?????????? ?? node ????
		if (node == firstEl)
			firstEl = next; //???? node ??????, ?? ?????? ????????? ?? ??? ??????
	}
	if (prev)
	{					   //???? ?????????? ?????????? ????
		prev->next = next; // ?? ???????? ?????? ?????????? ???????? ??????????? ?? node ????
		if (node == lastEl)
			lastEl = prev; //???? node ?????????, ?? ?????? ????????? ?? ??? ?????????
	}
	printf("???????t %i ??? ??????\n", node->value);
	delete[] node; //??????? ???? node
	return true;
}
void Dack::changeValueOfEl(NodeDack *node, int value)
{ //??????? ???????? ? ???? node
	if (!node)
	{ //???? ???????? ???, ???????
		printf("??????? ?? ??????????\n");
		return;
	}
	if (node)
		node->value = value; //???????? ????????
	printf("??????? ???????\n");
}
void Dack::print()
{ //????? ???? ????????? ? ??????
	if (!firstEl)
	{ //???? ??? ??????? ????????
		printf("??? ????");
	}
	else
	{
		NodeDack *el = firstEl;
		while (el) //??????? ?????????? ??? ???????? ????? ??????
		{
			printf("%i ", el->value);
			el = el->next;
		}
	}
	printf("\n");
}
void Dack::clear()
{ //??????? ????
	if (!firstEl)
		return; //???? ????????? ???, ?????? ??????? ??????
	NodeDack *el = firstEl;
	NodeDack *next;
	while (el)
	{ //??????? ?????? ??????? ?????????? ? ????
		next = el->next;
		DeleteNode(el);
		el = next;
	}
	printf("??? ?????????\n");
}
void Dack::showValueOfEl(NodeDack *node)
{ //????? ???????? ? ???? node
	if (!node)
		printf("??????? ?? ??????????\n");
	if (node)
		printf("???????? ???????? %i\n", node->value);
}
void Dack::isEmpty()
{
	if (!firstEl)
	{ //???? ??? ??????? ????????, ?? ??? ?????? ????? ?? ??????
		printf("??? ??????\n");
		return;
	}
	printf("??? ?? ??????\n");
}
Dack::~Dack()
{			 //??????????
	clear(); //??????? ??? ????????
}
void Dack::showValueOfHead()
{							//????? ??????? ???????? ????
	showValueOfEl(firstEl); //?????????? ?????? ???????, ????????? ? ???????? node ?????? ????
}
void Dack::showValueOfEnd()
{						   //????? ?????????? ???????? ????
	showValueOfEl(lastEl); //?????????? ????????? ???????, ????????? ? ???????? node ????????? ????
}
void Dack::deleteValueOfHead()
{						 //???????? ??????? ???????? ????
	DeleteNode(firstEl); //??????? ?????? ???????, ????????? ? ???????? node ?????? ????
}
void Dack::deleteValueOfEnd()
{
	DeleteNode(lastEl);
}
void Dack::takeValueOfHead()
{
	showValueOfEl(firstEl);
	DeleteNode(firstEl);
}
void Dack::takeValueOfEnd()
{
	showValueOfEl(lastEl);
	DeleteNode(lastEl);
}
void Dack::changeValueOfHead(int value)
{
	changeValueOfEl(firstEl, value);
}
void Dack::changeValueOfEnd(int value)
{
	addBeforeNode(firstEl, value);
}
void Dack::addValueOfHead(int value)
{
	addBeforeNode(firstEl, value);
}
void Dack::addValueOfEnd(int value)
{
	addAfterNode(lastEl, value);
}
void Dack::Menu()
{
	puts("\n1 ??????? ??? ??????\n \
		\r2 ???????? ??? ????/?? ????\n \
		\r3 ???????? ???????? ? ?????? ????\n \
		\r4 ???????? ???????? ? ????? ????\n \
		\r5 ??????? ?????? ????\n \
		\r6 ??????? ????? ????\n \
		\r7 ????? ??????? ?? ?????? ????\n \
		\r8 ????? ??????? ?? ????? ???? \n \
		\r9 ???????? ???????? ???????? ? ?????? ????\n \
		\r10 ???????? ???????? ???????? ? ????? ????\n \
		\r11 ???????? ??????? ? ?????? ????\n \
		\r12 ???????? ??????? ? ????? ????\n \
		\r13 ????????? ?????? ? ?????\n");
}
void Dack::Open()
{
	bool flag = true;
	system("cls");
	while (flag)
	{
		system("cls");
		print();
		Menu();
		printf("???????=");
		int option, value;
		scanf_s("%i", &option);
		if (option >= 9 && option <= 12)
		{
			printf("????????=");
			scanf_s("%i", &value);
		}
		switch (option)
		{
		case 1:
			clear();
			break;
		case 2:
			isEmpty();
			break;
		case 3:
			showValueOfHead();
			break;
		case 4:
			showValueOfEnd();
			break;
		case 5:
			deleteValueOfHead();
			break;
		case 6:
			deleteValueOfEnd();
			break;
		case 7:
			takeValueOfHead();
			break;
		case 8:
			takeValueOfEnd();
			break;
		case 9:
			changeValueOfHead(value);
			break;
		case 10:
			changeValueOfEnd(value);
			break;
		case 11:
			addValueOfHead(value);
			break;
		case 12:
			addValueOfEnd(value);
			break;
		case 13:
			flag = false;
			break;
		default:
			printf("????? ?? ?????????????");
			break;
		}
		Sleep(500);
	}
}