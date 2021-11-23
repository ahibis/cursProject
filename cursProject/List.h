#pragma once
#include <iostream>
#include "NodeList.h"
#include "Stack.h"
#include "windows.h"

class List
{
	bool isOpen = false;							  //������ �� ������
	NodeList *firstEl = 0;							  //������ �� ��������� �������
	NodeList *lastEl = 0;							  //������ �� �������� �������
	NodeList *pointer = 0;							  //������ �� ���������
	bool DeleteNode(NodeList *node);				  //�������� ���� node
	void changeValueOfEl(NodeList *node);			  //��������� ���� node
	void movePointerToEl(NodeList *node);			  //����� ���� �� node
	bool isPointerAt(NodeList *node);				  //�������� ��������� �� ���� node
	void showValueOfEl(NodeList *node);				  //�������� ������� ���� node
	void addAfterNode(NodeList *node, Stack *value);  //�������� ������� �� node
	void addBeforeNode(NodeList *node, Stack *value); //�������� ������� ����� node
	void Menu();									  //����� ����
public:
	~List();
	void print();							  //����� ���� ��������� ������
	void Open();							  //������ ������ �� �������
	void clear();							  //������� ������ ������
	void isEmpty();							  //��������:������ ����/�� ���� ?
	void movePointerToHead();				  //���������� ������� ��������� � ������ ������
	void movePointerToEnd();				  //���������� ������� ��������� � ����� ������
	void isPointerAtHead();					  //��������:������� ��������� � ������ ������ ?
	void isPointerAtEnd();					  //��������:������� ��������� � ����� ������ ?
	void movePointerToPrev();				  //����������� ������� ��������� ������ �����
	void movePointerToNext();				  //����������� ������� ��������� ������ ������
	void showValueAfterPointer();			  //�������� �������� �������� ������ �� ����������
	void showValueBeforePointer();			  //�������� �������� �������� ������ �� ���������
	void deleteValueAfterPointer();			  //������� ������� ������ �� ����������
	void deleteValueBeforePointer();		  //������� ������� ������ �� ���������
	void takeValueAfterPointer();			  //����� ������� ������ �� ����������
	void takeValueBeforePointer();			  //����� ������� ������ �� ���������
	void changeValueAfterPointer();			  //�������� �������� �������� ������ �� ����������
	void changeValueBeforePointer();		  //�������� �������� �������� ������ �� ���������
	void addValueAfterPointer(Stack *value);  //�������� ������� �� ���������
	void addValueBeforePointer(Stack *value); //�������� ������� �� ����������
	void Close();							  //��������� ������ �� �������
};
