#pragma once
#include <iostream>
#include "NodeStack.h"
#include "Dack.h"
#include "windows.h"

class Stack
{
	NodeStack *lastEl = 0; //������ �� ������� �����
	void Menu();		   //����� ����

public:
	~Stack();
	void print();				  //����� ���� ��������� �����
	void Open();				  //������ ������ �� ������
	void clear();				  //������� ���� ������
	void isEmpty();				  //��������:���� ����/�� ����
	void showElement();			  //�������� �������� ������� �����
	bool deleteElement();		  //������� ������� �����
	void takeElement();			  //����� ������� �� �����
	void changeElement();		  //�������� �������� ������� �����
	void addElement(Dack *value); //�������� ������� � ����
};
