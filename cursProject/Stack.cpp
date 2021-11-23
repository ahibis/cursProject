#include "Stack.h"
void Stack::clear() //очищение стека
{
	if (!lastEl) //если нет элементов выходим
		return;
	NodeStack *el = lastEl;
	NodeStack *next;
	while (el) //итерационно удаляем все элементы в стеке
	{
		deleteElement();
		el = lastEl;
	}
	printf("Стек опустошен\n");
}
void Stack::isEmpty() // проверка на пустоту стека
{
	if (!lastEl) //если не существует последнего элемента
	{
		printf("стек пустой\n");
		return;
	}
	printf("стек не пустой\n");
}
Stack::~Stack() //деструктор стека
{
	clear(); //очищаем все элементы
}
void Stack::addElement(Dack *value) //добавление элемента в конец
{
	NodeStack *node = lastEl;		 // делаем узел после которого добавляем элемент как lastEl
	NodeStack *el = new NodeStack(); //создаем новый узел
	if (!el)
	{
		printf("не удалось выделить память под дек\n");
		return;
	}
	el->value = value; //изменяем значение нового узла
	if (!node)		   //если node не определен делаем el первым в стеке
	{
		lastEl = el;
		printf("дек был добавлен\n");
		return;
	}
	if (node == lastEl) // если node последний, то делаем el последним
		lastEl = el;
	el->prev = node; //делаем предыдущим элементом el как node
	printf("дек был добавлен\n");
}
bool Stack::deleteElement() //удаление вершины дека
{
	NodeStack *node = lastEl; //делаем узел удаления как последний узел
	if (!node)				  //если node не существует
	{
		printf("дек не может быть удален\n\n\n");
		return false;
	}
	NodeStack *prev = node->prev; //ссылаемся на предыдущий элемент node
	if (!prev)					  //если удаляем последний элемент, то очищаем весь стек
	{
		lastEl = 0;
		printf("дек был удален\n");
		delete[] node;
		return true;
	}
	if (prev) //если существует предыдущий элемент
	{
		if (node == lastEl) //если node последний элемент
			lastEl = prev;	//последний элемент делаем равным prev
	}
	printf("дек был удален\n");
	delete[] node; //удаляем node
	return true;
}
void Stack::changeElement() //изменение значения вершины
{
	NodeStack *node = lastEl;
	if (!node) //если node не существет
	{
		printf("элемента не существует\n");
		return;
	}
	node->value->Open(); //изменяем значение node
	printf("дек изменен\n");
}
void Stack::print() //вывод всех элементов дека
{
	if (!lastEl) //если нет первого элемента
	{
		printf("стек пуст\n");
	}
	else
	{
		NodeStack *el = lastEl;
		while (el) //выводим все элемента стека через перенос строки
		{
			el->value->print();
			el = el->prev;
		}
	}
}

void Stack::showElement() //показать значение вершины
{
	NodeStack *node = lastEl; //указываем node как на последний элемент
	if (node)
	{
		printf("значение элемента\n");
		node->value->print(); //выводим значение
		return;
	}
	printf("элемента не существует\n");
}
void Stack::takeElement() //взять элемент из стека
{
	showElement();	 //показываем значение вершины
	deleteElement(); //удаляем вершину стека
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
void Stack::Open() //начать работу с стеком
{
	bool flag = true;
	while (flag) //если работа с деком не завершена
	{
		system("cls"); //очищаем экран
		print();	   //выводим стек
		Menu();		   //выводим меню
		printf("Введите=");
		int option;
		Dack *value;
		scanf_s("%i", &option); //вводим опцию
		switch (option)			//для каждой опции вызываем связанную с ней функцию
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
		Sleep(500); //делаем задержку 0.5с
	}
}
