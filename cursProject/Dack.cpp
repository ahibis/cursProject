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
		printf("������� %i ��������\n", value);
		return;
	}
	if (node == lastEl) // ���� node ���������, �� ������ el ���������
		lastEl = el;
	if (node->next) //���� ���������� ��������� ������� �� node
	{
		el->next = node->next; //�� ������ ��������� ������� el ������� ���������� node
		node->next->prev = el; // � ��������
	}
	el->prev = node; //������ ���������� ��������� el ��� node
	node->next = el; //������ ��������� ������� node ��� el
	printf("������� %i ��������\n", value);
}
void Dack::addBeforeNode(NodeDack *node, int value) //���������� �������� ����� node
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
		printf("������� %i ��������\n", value);
		return;
	}
	if (node == firstEl) // ���� node ������, �� ������ el ������
		firstEl = el;
	if (node->prev) //���� ���������� ���������� ������� �� node
	{
		el->prev = node->prev; //�� ������ ���������� ������� el ������� ����������� node
		node->prev->next = el;
	}
	el->next = node; //������ ��������� ��������� el ��� node
	node->prev = el; //������ ���������� ������� node ��� el
	printf("������� %i ��������\n", value);
}
bool Dack::DeleteNode(NodeDack *node) //�������� ���� node
{
	if (!node) //���� node �� ����������
	{
		printf("�� ������� ������� �������\n\n\n");
		return false;
	}
	NodeDack *prev = node->prev; //��������� �� ���������� ������� node
	NodeDack *next = node->next; //��������� �� ����������� ������� node
	if (!prev && !next)			 //���� ������� ��������� �������, �� ������� ���� ���
	{
		firstEl = 0;
		lastEl = 0;
		printf("������� %i ������\n", node->value);
		delete[] node;
		return true;
	}
	if (next) //���� ���������� ��������� �������
	{
		next->prev = prev;	 // ���������� next �������� ������ ����������
		if (node == firstEl) //���� node ������ �������
			firstEl = next;	 //������ ������� ������ ������ ����������
	}
	if (prev) //���� ���������� ���������� �������
	{
		prev->next = next;	//��������� prev �������� ������ ���������
		if (node == lastEl) //���� node ��������� �������
			lastEl = prev;	//��������� ������� ������ ������ prev
	}
	printf("������� %i ������\n", node->value);
	delete[] node; //������� node
	return true;
}
void Dack::changeValueOfEl(NodeDack *node, int value) //��������� ���� node
{
	if (!node) //���� node �� ���������
	{
		printf("�������� �� ���������� \n");
		return;
	}
	if (node)
		node->value = value; //�������� �������� node
	printf("������� �������\n");
}
void Dack::print() //����� ���� ��������� ����
{
	if (!firstEl) //���� ��� ������� ��������
	{
		printf("��� ����");
	}
	else
	{
		NodeDack *el = firstEl;
		while (el) //������� ��� �������� ���� ����� ������
		{
			printf("%i ", el->value);
			el = el->next;
		}
	}
	printf("\n");
}
void Dack::clear() //�������� ����
{
	if (!firstEl) //���� ��� ��������� �������
		return;
	NodeDack *el = firstEl;
	NodeDack *next;
	while (el) //����������� ������� ��� �������� � ����
	{
		next = el->next;
		DeleteNode(el);
		el = next;
	}
	printf("��� ������\n");
}
void Dack::showValueOfEl(NodeDack *node) //�������� �������� ���� node
{
	if (!node)
		printf("�������� �� ����������\n");
	if (node)
		printf("�������� �������� %i\n", node->value);
}
void Dack::isEmpty() // �������� �� ������� ����
{
	if (!firstEl) //���� �� ���������� ������� ��������
	{
		printf("��� ������\n");
		return;
	}
	printf("��� �� ������\n");
}
Dack::~Dack() //���������� ����
{
	clear(); //������� ��� ��������
}
void Dack::showValueOfHead() //�������� �������� � ������ ����
{
	showValueOfEl(firstEl); //���������� �������� firstEl
}
void Dack::showValueOfEnd() //�������� �������� � ����� ����
{
	showValueOfEl(lastEl); //���������� �������� lastEl
}
void Dack::deleteValueOfHead() //������� �������� � ������ ����
{
	DeleteNode(firstEl); //������� ���� firstEl
}
void Dack::deleteValueOfEnd() //������� �������� � ����� ����
{
	DeleteNode(lastEl); //������� ���� lastEl
}
void Dack::takeValueOfHead() //����� ������ �������
{
	showValueOfEl(firstEl); //���������� �������� firstEl
	DeleteNode(firstEl);	//������� ���� firstEl
}
void Dack::takeValueOfEnd() //����� ��������� �������
{
	showValueOfEl(lastEl); //���������� �������� lastEl
	DeleteNode(lastEl);	   //������� ���� lastEl
}
void Dack::changeValueOfHead(int value) //�������� �������� � ������ ����
{
	changeValueOfEl(firstEl, value); //�������� �������� ���� firstEl
}
void Dack::changeValueOfEnd(int value) //�������� �������� � ����� ����
{
	addBeforeNode(firstEl, value); //�������� �������� ���� lastEl
}
void Dack::addValueOfHead(int value) //�������� �������� � ������ ����
{
	addBeforeNode(firstEl, value); //��������� ������� ����� ���� firstEl
}
void Dack::addValueOfEnd(int value) //�������� �������� � ������ ����
{
	addAfterNode(lastEl, value); //��������� ������� ����� ���� lastEl
}
void Dack::Menu() //���� ����
{
	puts("\n1 ������� ��� ������\n \
		\r2 ��������:��� ����/�� ����\n \
		\r3 �������� �������� � ������ ����\n \
		\r4 �������� �������� � ����� ����\n \
		\r5 ������� ������ ����\n \
		\r6 ������� ����� ����\n \
		\r7 ����� ������� �� ������ ����\n \
		\r8 ����� ������� �� ����� ����  \n \
		\r9 �������� �������� �������� � ������ ����\n \
		\r10 �������� �������� �������� � ����� ����\n \
		\r11 �������� ������� � ������ ����\n \
		\r12 �������� ������� � ����� ����\n \
		\r13 ��������� ������ � �����\n");
}
void Dack::Close() {
	isOpen = false;
}
void Dack::Open() //������ ������ � �����
{
	isOpen = true;
	while (isOpen) //���� ������ � ����� �� ���������
	{
		system("cls"); //������� �����
		print();	   //������� ������
		Menu();		   //������� ����
		printf("�������=");
		int option, value;
		scanf_s("%i", &option);			 //������ �����
		if (option >= 9 && option <= 12) //���� ����� �� 9 �� 12
		{
			printf("��������=");
			scanf_s("%i", &value); //������ ��������
		}
		switch (option) //��� ������ ����� �������� ��������� � ��� �������
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
			Close();
			break;
		default:
			printf("����� �� �������������");
			break;
		}
		Sleep(500); //������ �������� 0.5�
	}
}