#pragma once
#include <iostream>
#include "NodeList.h"
#include "Stack.h"
#include "windows.h"

class List
{
	bool isOpen = false;							  //открыт ли список
	NodeList *firstEl = 0;							  //ссылка на начальный элемент
	NodeList *lastEl = 0;							  //ссылка на конечный элемент
	NodeList *pointer = 0;							  //ссылка на указатель
	bool DeleteNode(NodeList *node);				  //удаление узла node
	void changeValueOfEl(NodeList *node);			  //изменение узла node
	void movePointerToEl(NodeList *node);			  //сдвиг узла на node
	bool isPointerAt(NodeList *node);				  //проверка указатель на узле node
	void showValueOfEl(NodeList *node);				  //показать элемент узла node
	void addAfterNode(NodeList *node, Stack *value);  //добавить элемент до node
	void addBeforeNode(NodeList *node, Stack *value); //добавить элемент после node
	void Menu();									  //вывод меню
public:
	~List();
	void print();							  //вывод всех элементов списка
	void Open();							  //Начать работу со списком
	void clear();							  //Сделать список пустым
	void isEmpty();							  //Проверка:список пуст/не пуст ?
	void movePointerToHead();				  //Установить рабочий указатель в начало списка
	void movePointerToEnd();				  //Установить рабочий указатель в конец списка
	void isPointerAtHead();					  //Проверка:рабочий указатель в начале списка ?
	void isPointerAtEnd();					  //Проверка:рабочий указатель в конце списка ?
	void movePointerToPrev();				  //Передвинуть рабочий указатель списка назад
	void movePointerToNext();				  //Передвинуть рабочий указатель списка вперед
	void showValueAfterPointer();			  //Показать значение элемента списка за указателем
	void showValueBeforePointer();			  //Показать значение элемента списка до указателя
	void deleteValueAfterPointer();			  //Удалить элемент списка за указателем
	void deleteValueBeforePointer();		  //Удалить элемент списка до указателя
	void takeValueAfterPointer();			  //Взять элемент списка за указателем
	void takeValueBeforePointer();			  //Взять элемент списка до указателя
	void changeValueAfterPointer();			  //Изменить значение элемента списка за указателем
	void changeValueBeforePointer();		  //Изменить значение элемента списка до указателя
	void addValueAfterPointer(Stack *value);  //Добавить элемент до указателя
	void addValueBeforePointer(Stack *value); //Добавить элемент за указателем
	void Close();							  //Закончить работу со списком
};
