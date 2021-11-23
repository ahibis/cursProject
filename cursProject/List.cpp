#include "List.h"
void List::addAfterNode(NodeList *node, Stack *value) //���������� �������� ����� node
{
	NodeList *el = new NodeList(); //������� ����� ����
	if (!el)
	{
		printf("�� ������� �������� ������ ��� ������\n");
		return;
	}
	el->value = value; //�������� �������� ������ ����
	if (!node)		   //���� node �� ��������� ������ el ������ � ����
	{
		firstEl = el;
		lastEl = el;
		pointer = el;
		printf("������� %i ��������\n");
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
	printf("������� ��������\n\n");
}
void List::addBeforeNode(NodeList *node, Stack *value) //���������� �������� ����� node
{
	NodeList *el = new NodeList();
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
		pointer = el;
		printf("������� ��������\n");
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
	printf("������� ��������\n");
}
bool List::DeleteNode(NodeList *node) //�������� ���� node
{
	if (!node) //���� node �� ����������
	{
		printf("�� ������� ������� �������\n\n\n");
		return false;
	}
	NodeList *prev = node->prev; //��������� �� ���������� ������� node
	NodeList *next = node->next; //��������� �� ����������� ������� node
	if (!prev && !next)			 //���� ������� ��������� �������, �� ������� ���� ���
	{
		firstEl = 0;
		lastEl = 0;
		pointer = 0;
		printf("������� ������\n");
		delete[] node;
		return true;
	}
	if (next) //���� ���������� ��������� �������
	{
		next->prev = prev;	 // ���������� next �������� ������ ����������
		if (node == firstEl) //���� node ������ �������
			firstEl = next;	 //������ ������� ������ ������ ����������
		if (node == pointer) //���� node ���������
			pointer = next;	 //��������� ������ ������ ����������
	}
	if (prev) //���� ���������� ���������� �������
	{
		prev->next = next;	 //��������� prev �������� ������ ���������
		if (node == lastEl)	 //���� node ��������� �������
			lastEl = prev;	 //��������� ������� ������ ������ prev
		if (node == pointer) //���� node ���������
			pointer = prev;	 //��������� ������ ������ �����������
	}
	printf("������� ������\n");
	delete[] node; //������� node
	return true;
}
void List::movePointerToEl(NodeList *node) //����� ��������� �� ���� node
{
	if (node) //���� node ����������
	{
		pointer = node;
		printf("��������� �������\n");
	}
	else
		printf("�� ������� �������� ���������\n");
}
bool List::isPointerAt(NodeList *node) //�������� ��������� �� �������
{
	return pointer == node;
}
void List::changeValueOfEl(NodeList *node)
{
	if (!node) //���� node �� ���������
	{
		printf("�������� �� ���������� \n");
		return;
	}
	if (node)
		node->value->Open(); //��������� ���� ��������
	printf("������� �������\n");
}
void List::print() //����� ���� ��������� ������
{
	if (!firstEl) //���� ��� ������� ��������
	{
		printf("������ ����");
	}
	else
	{
		NodeList *el = firstEl;
		while (el) //����������� �� ���� ��������� ������
		{
			if (el == pointer) //���� ������� ����� ���������
			{
				el->value->print(); //������� �������� ��������
				printf("^^^^^^^^^^^^^^^^^^\n");
				el = el->next;
				continue;
			}
			el->value->print(); //������� �������� ��������
			printf("################\n");
			el = el->next;
		}
	}
	printf("\n");
}
void List::clear() //�������� ������
{
	if (!firstEl) //���� ��� ��������� �������
		return;
	NodeList *el = firstEl;
	NodeList *next;
	while (el) //����������� ������� ��� �������� � ������
	{
		next = el->next;
		DeleteNode(el);
		el = next;
	}
	printf("������ ������\n");
}
void List::showValueOfEl(NodeList *node) //�������� �������� �������� node
{
	if (node) //���� node ����������
	{
		printf("�������� ��������\n");
		node->value->print();
		return;
	}
	printf("�������� �� ����������\n");
}
void List::isEmpty() // �������� �� ������� ������
{
	if (!firstEl) //���� �� ���������� ������� ��������
	{
		printf("������ ����\n");
		return;
	}
	printf("������ �� ����\n");
}
List::~List() //���������� ������
{
	clear(); //������� ��� ��������
}
void List::movePointerToHead() //�������� ��������� � ������
{
	movePointerToEl(firstEl); //�������� ��������� �� firstEl
}
void List::movePointerToEnd() //�������� ��������� � �����
{
	movePointerToEl(lastEl); //�������� ��������� �� lastEl
}
void List::isPointerAtHead() //��������: ��������� � ������
{
	if (isPointerAt(firstEl)) //���� ��������� �� firstEl
		printf("��������� � ������\n");
	else
		printf("��������� �� � ������");
}
void List::isPointerAtEnd() //��������: ��������� � �����
{
	if (isPointerAt(lastEl)) //���� ��������� �� lastEl
		printf("��������� � �����\n");
	else
		printf("��������� �� � �����\n");
}
void List::movePointerToPrev() //�������� ��������� �����
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������\n");
		return;
	}
	movePointerToEl(pointer->prev); //�������� ��������� �� ������� ��������� �� ����������
}
void List::movePointerToNext() //�������� ��������� ������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������\n");
		return;
	}
	movePointerToEl(pointer->next); //�������� ��������� �� ������� ��������� �� ����������
}
void List::showValueAfterPointer() //�������� �������� ����� ���������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	showValueOfEl(pointer->next); //���������� �������� ����� ���������
}
void List::showValueBeforePointer() //�������� �������� ����� ����������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	showValueOfEl(pointer->prev); //���������� �������� ����� ����������
}
void List::deleteValueAfterPointer() //������� �������� ����� ���������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	DeleteNode(pointer->next); //������� �������� ����� ���������
}
void List::deleteValueBeforePointer() //������� �������� ����� ����������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	DeleteNode(pointer->prev); //������� �������� ����� ����������
}
void List::takeValueAfterPointer() //����� �������� ����� ���������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	showValueOfEl(pointer->next); //���������� �������� ����� ���������
	DeleteNode(pointer->next);	  //������� �������� ����� ���������
}
void List::takeValueBeforePointer() //����� �������� ����� ����������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	showValueOfEl(pointer->prev); //���������� �������� ����� ����������
	DeleteNode(pointer->prev);	  //������� �������� ����� ���������
}
void List::changeValueAfterPointer() //�������� �������� ����� ���������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	changeValueOfEl(pointer->next); //�������� �������� ���� ����� ���������
}
void List::changeValueBeforePointer() //�������� �������� ����� ����������
{
	if (!pointer) //���� ��������� ���
	{
		printf("��������� �� ������");
		return;
	}
	changeValueOfEl(pointer->prev); //�������� �������� ����� ���������
}
void List::addValueAfterPointer(Stack *value) //�������� �������� ����� ���������
{
	addAfterNode(pointer, value); //��������� �������� ����� ���������
}
void List::addValueBeforePointer(Stack *value) //�������� �������� ����� ����������
{
	addBeforeNode(pointer, value); //��������� �������� ����� ����������
}
void List::Menu()
{
	puts("\n1 ������� ������ ������\n \
		\r2 ��������:������ ����/�� ���� \n \
		\r3 ���������� ������� ��������� � ������ ������\n \
		\r4 ���������� ������� ��������� � ����� ������\n \
		\r5 ��������:������� ��������� � ������ ������\n \
		\r6 ��������:������� ��������� � ����� ������\n \
		\r7 ����������� ������� ��������� ������ ������\n \
		\r8 ����������� ������� ��������� ������ �����\n \
		\r9 �������� �������� �������� ������ �� ���������\n \
		\r10 �������� �������� �������� ������ �� ����������\n \
		\r11 ������� ������� ������ �� ���������\n \
		\r12 ������� ������� ������ �� ����������\n \
		\r13 ����� ������� ������ �� ���������\n \
		\r14 ����� ������� ������ �� ����������\n \
		\r15 �������� �������� �������� ������ �� ���������\n \
		\r16 �������� �������� �������� ������ �� ����������\n \
		\r17 �������� ������� �� ���������\n \
		\r18 �������� ������� �� ����������\n \
		\r19 ��������� ������ �� �������\n");
}
void List::Open() //������ ������ � �������
{
	bool flag = true;
	system("cls");
	while (flag) //���� ������ � ������� �� ���������
	{
		system("cls"); //������� �����
		print();	   //������� ������
		Menu();		   //������� ����
		printf("???????=");
		int option;
		Stack *value;
		scanf_s("%i", &option); //������ �����
		switch (option)			//��� ������ ����� �������� ��������� � ��� �������
		{
		case 1:
			clear();
			break;
		case 2:
			isEmpty();
			break;
		case 3:
			movePointerToHead();
			break;
		case 4:
			movePointerToEnd();
			break;
		case 5:
			isPointerAtHead();
			break;
		case 6:
			isPointerAtEnd();
			break;
		case 7:
			movePointerToNext();
			break;
		case 8:
			movePointerToPrev();
			break;
		case 9:
			showValueBeforePointer();
			break;
		case 10:
			showValueAfterPointer();
			break;
		case 11:
			deleteValueBeforePointer();
			break;
		case 12:
			deleteValueAfterPointer();
			break;
		case 13:
			takeValueBeforePointer();
			break;
		case 14:
			takeValueAfterPointer();
			break;
		case 15:
			changeValueBeforePointer();
			break;
		case 16:
			changeValueAfterPointer();
			break;
		case 17:
			value = new Stack();
			value->Open();
			addValueBeforePointer(value);
			break;
		case 18:
			value = new Stack();
			value->Open();
			addValueAfterPointer(value);
			break;
		case 19:
			flag = false;
			break;
		default:
			printf("����� �� �������������");
			break;
		}
		Sleep(500); //������ �������� 0.5�
	}
}