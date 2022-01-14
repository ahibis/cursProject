#pragma once
#include <iostream>
#include "NodeStack.h"
#include "Dack.h"
#include "windows.h"

class Stack { //класс стека
	bool isOpen = false; //открыт ли стек
	int maxDepth = 100; //максимальная глубина 
	int depth = 0; //глубина
	NodeStack* lastEl = 0; //ссылка на вершину стека
	void Menu(); //вывод меню

public:
	~Stack();
	void print(); //вывод всех элементов стека
	void Open(); //Начать работу со стеком
	void clear(); //Сделать стек пустым
	void isEmpty(); //Проверка:стек пуст /не пуст
	void showElement(); //Показать значение вершины стека
	bool deleteElement(); //Удалить вершину стека
	void takeElement(); //Взять элемент из стека
	void changeElement(); //Изменить значение вершины стека
	void addElement(Dack* value); //Добавить элемент в стек
	void Close(); //Закончить работу со стеком
};
