#include "List.h"
void List::addAfterNode(NodeList *node, Stack *value) //добавление элемента после node
{
	NodeList *el = new NodeList(); //создаем новый узел
	if (!el)
	{
		printf("не удалось выделить память под элемен\n");
		return;
	}
	el->value = value; //изменяем значение нового узла
	if (!node)		   //если node не определен делаем el первым в деке
	{
		firstEl = el;
		lastEl = el;
		pointer = el;
		printf("элемент %i добавлен\n");
		return;
	}
	if (node == lastEl) // если node последний, то делаем el последним
		lastEl = el;
	if (node->next) //если существует следующий элемент за node
	{
		el->next = node->next; //то делаем следующий элемент el равному следующему node
		node->next->prev = el; // и наоборот
	}
	el->prev = node; //делаем предыдущим элементом el как node
	node->next = el; //делаем следующий элемент node как el
	printf("элемент добавлен\n\n");
}
void List::addBeforeNode(NodeList *node, Stack *value) //добавление элемента перед node
{
	NodeList *el = new NodeList();
	if (!el)
	{
		printf("не удалось выделить память под элемент\n");
		return;
	}
	el->value = value; //изменяем значение нового узла
	if (!node)		   //если node не определен делаем el первым в деке
	{
		firstEl = el;
		lastEl = el;
		pointer = el;
		printf("элемент добавлен\n");
		return;
	}
	if (node == firstEl) // если node первый, то делаем el первым
		firstEl = el;
	if (node->prev) //если существует предыдущий элемент за node
	{
		el->prev = node->prev; //то делаем предыдущий элемент el равному предыдущему node
		node->prev->next = el;
	}
	el->next = node; //делаем следующим элементом el как node
	node->prev = el; //делаем предыдущим элемент node как el
	printf("элемент добавлен\n");
}
bool List::DeleteNode(NodeList *node) //удаление узла node
{
	if (!node) //если node не существует
	{
		printf("не удалось удалить элемент\n\n\n");
		return false;
	}
	NodeList *prev = node->prev; //ссылаемся на предыдущий элемент node
	NodeList *next = node->next; //ссылаемся на последующий элемент node
	if (!prev && !next)			 //если удаляем последний элемент, то очищаем весь дек
	{
		firstEl = 0;
		lastEl = 0;
		pointer = 0;
		printf("элемент удален\n");
		delete[] node;
		return true;
	}
	if (next) //если существует следующий элемент
	{
		next->prev = prev;	 // предыдущий next элемента делаем предыдущим
		if (node == firstEl) //если node первый элемент
			firstEl = next;	 //первый элемент делаем равным следующему
		if (node == pointer) //если node указатель
			pointer = next;	 //указатель делаем равным следующему
	}
	if (prev) //если существует предыдущий элемент
	{
		prev->next = next;	 //следующий prev элемента делаем следующим
		if (node == lastEl)	 //если node последний элемент
			lastEl = prev;	 //последний элемент делаем равным prev
		if (node == pointer) //если node указатель
			pointer = prev;	 //указатель делаем равным предыдущему
	}
	printf("элемент удален\n");
	delete[] node; //удаляем node
	return true;
}
void List::movePointerToEl(NodeList *node) //сдвиг указателя на узел node
{
	if (node) //если node существует
	{
		pointer = node;
		printf("указатель сдвинут\n");
	}
	else
		printf("не удалось сдвинуть указатель\n");
}
bool List::isPointerAt(NodeList *node) //проверка указателя на позиции
{
	return pointer == node;
}
void List::changeValueOfEl(NodeList *node)
{
	if (!node) //если node не существет
	{
		printf("элемента не существует \n");
		return;
	}
	if (node)
		node->value->Open(); //открываем меню элемента
	printf("элемент изменен\n");
}
void List::print() //вывод всех элементов списка
{
	if (!firstEl) //если нет первого элемента
	{
		printf("список пуст");
	}
	else
	{
		NodeList *el = firstEl;
		while (el) //итерируемся по всем элементам списка
		{
			if (el == pointer) //если элемент равен указателю
			{
				el->value->print(); //выводим значение элемента
				printf("^^^^^^^^^^^^^^^^^^\n");
				el = el->next;
				continue;
			}
			el->value->print(); //выводим значение элемента
			printf("################\n");
			el = el->next;
		}
	}
	printf("\n");
}
void List::clear() //очищение списка
{
	if (!firstEl) //если нет элементов выходим
		return;
	NodeList *el = firstEl;
	NodeList *next;
	while (el) //итерационно удаляем все элементы в списке
	{
		next = el->next;
		DeleteNode(el);
		el = next;
	}
	printf("список очищен\n");
}
void List::showValueOfEl(NodeList *node) //показать значение элемента node
{
	if (node) //если node существует
	{
		printf("значение элемента\n");
		node->value->print();
		return;
	}
	printf("элемента не существует\n");
}
void List::isEmpty() // проверка на пустоту списка
{
	if (!firstEl) //если не существует первого элемента
	{
		printf("список пуст\n");
		return;
	}
	printf("список не пуст\n");
}
List::~List() //деструктор списка
{
	clear(); //очищаем все элементы
}
void List::movePointerToHead() //сдвинуть указатель в начало
{
	movePointerToEl(firstEl); //сдвигаем указатель на firstEl
}
void List::movePointerToEnd() //сдвинуть указатель в конец
{
	movePointerToEl(lastEl); //сдвигаем указатель на lastEl
}
void List::isPointerAtHead() //проверка: указатель в начале
{
	if (isPointerAt(firstEl)) //если указатель на firstEl
		printf("указатель в начале\n");
	else
		printf("указатель не в начале");
}
void List::isPointerAtEnd() //проверка: указатель в конце
{
	if (isPointerAt(lastEl)) //если указатель на lastEl
		printf("указатель в конце\n");
	else
		printf("указатель не в конце\n");
}
void List::movePointerToPrev() //сдвинуть указатель назад
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден\n");
		return;
	}
	movePointerToEl(pointer->prev); //сдвигаем указатель на элемент следующий за указателем
}
void List::movePointerToNext() //сдвинуть указатель вперед
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден\n");
		return;
	}
	movePointerToEl(pointer->next); //сдвигаем указатель на элемент следующий за указателем
}
void List::showValueAfterPointer() //показать значение после указателя
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	showValueOfEl(pointer->next); //показываем значение после указателя
}
void List::showValueBeforePointer() //показать значение перед указателем
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	showValueOfEl(pointer->prev); //показываем значение перед указателем
}
void List::deleteValueAfterPointer() //удалить значение после указателя
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	DeleteNode(pointer->next); //удаляем значение после указателя
}
void List::deleteValueBeforePointer() //удалить значение перед указателем
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	DeleteNode(pointer->prev); //удаляем значение перед указателем
}
void List::takeValueAfterPointer() //взять значение после указателя
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	showValueOfEl(pointer->next); //показываем значение после указателя
	DeleteNode(pointer->next);	  //удаляем значение после указателя
}
void List::takeValueBeforePointer() //взять значение перед указателем
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	showValueOfEl(pointer->prev); //показываем значение перед указателем
	DeleteNode(pointer->prev);	  //удаляем значение после указателя
}
void List::changeValueAfterPointer() //изменить значение после указателя
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	changeValueOfEl(pointer->next); //изменяем значение узла после указателя
}
void List::changeValueBeforePointer() //изменить значение перед указателем
{
	if (!pointer) //если указателя нет
	{
		printf("указатель не найден");
		return;
	}
	changeValueOfEl(pointer->prev); //изменить значение после указателя
}
void List::addValueAfterPointer(Stack *value) //добавить значение после указателя
{
	addAfterNode(pointer, value); //добавляем значение после указателя
}
void List::addValueBeforePointer(Stack *value) //добавить значение перед указателем
{
	addBeforeNode(pointer, value); //добавляем значение перед указателем
}
void List::Menu()
{
	puts("\n1 Сделать список пустым\n \
		\r2 Проверка:список пуст/не пуст \n \
		\r3 Установить рабочий указатель в начало списка\n \
		\r4 Установить рабочий указатель в конец списка\n \
		\r5 Проверка:рабочий указатель в начале списка\n \
		\r6 Проверка:рабочий указатель в конце списка\n \
		\r7 Передвинуть рабочий указатель списка вперед\n \
		\r8 Передвинуть рабочий указатель списка назад\n \
		\r9 Показать значение элемента списка до указателя\n \
		\r10 Показать значение элемента списка за указателем\n \
		\r11 Удалить элемент списка до указателя\n \
		\r12 Удалить элемент списка за указателем\n \
		\r13 Взять элемент списка до указателя\n \
		\r14 Взять элемент списка за указателем\n \
		\r15 Изменить значение элемента списка до указателя\n \
		\r16 Изменить значение элемента списка за указателем\n \
		\r17 Добавить элемент до указателя\n \
		\r18 Добавить элемент за указателем\n \
		\r19 Закончить работу со списком\n");
}
void List::Open() //начать работу с списком
{
	bool flag = true;
	system("cls");
	while (flag) //если работа с списком не завершена
	{
		system("cls"); //очищаем экран
		print();	   //выводим список
		Menu();		   //выводим меню
		printf("???????=");
		int option;
		Stack *value;
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
			printf("Опция не действительна");
			break;
		}
		Sleep(500); //делаем задержку 0.5с
	}
}