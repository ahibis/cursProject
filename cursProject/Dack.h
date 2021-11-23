#pragma once
#include <iostream>
#include "NodeDack.h"
#include "windows.h"

class Dack
{
	NodeDack *firstEl = 0;							 //ссылка на начальный элемент
	NodeDack *lastEl = 0;							 //ссылка на конечный элемент
	void addAfterNode(NodeDack *node, int value);	 //добавить элемент до node
	void addBeforeNode(NodeDack *node, int value);	 //добавить элемент после node
	bool DeleteNode(NodeDack *node);				 //удаление узла node
	void changeValueOfEl(NodeDack *node, int value); //изменение узла node
	void showValueOfEl(NodeDack *node);				 //показать элемент узла node
	void Menu();									 //вывод меню
public:
	~Dack();
	void print();					   //вывод всех элементов дека
	void Open();					   //Начать работу с деком
	void clear();					   //Сделать дек пустым
	void isEmpty();					   //Проверка:дек пуст/не пуст
	void showValueOfHead();			   //Показать значение в начале дека
	void showValueOfEnd();			   //Показать значение в конце дека
	void deleteValueOfHead();		   //Удалить начало дека
	void deleteValueOfEnd();		   //Удалить конец дека
	void takeValueOfHead();			   //Взять элемент из начала дека
	void takeValueOfEnd();			   //Взять элемент из конца дека
	void changeValueOfHead(int value); //Изменить значение элемента в начале дека
	void changeValueOfEnd(int value);  //Изменить значение элемента в конце дека
	void addValueOfHead(int value);	   //Добавить элемент в начало дека
	void addValueOfEnd(int value);	   //Добавить элемент в конец дека
};