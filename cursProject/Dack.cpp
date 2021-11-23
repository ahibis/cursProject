#include "Dack.h"
void Dack::addAfterNode(NodeDack *node, int value) //добавление элемента после node
{
	NodeDack *el = new NodeDack(); //создаем новый узел
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
		printf("элемент %i добавлен\n", value);
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
	printf("элемент %i добавлен\n", value);
}
void Dack::addBeforeNode(NodeDack *node, int value) //добавление элемента перед node
{
	NodeDack *el = new NodeDack(); //создаем новый узел
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
		printf("элемент %i добавлен\n", value);
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
	printf("элемент %i добавлен\n", value);
}
bool Dack::DeleteNode(NodeDack *node) //удаление узла node
{
	if (!node) //если node не существует
	{
		printf("не удалось удалить элемент\n\n\n");
		return false;
	}
	NodeDack *prev = node->prev; //ссылаемся на предыдущий элемент node
	NodeDack *next = node->next; //ссылаемся на последующий элемент node
	if (!prev && !next)			 //если удаляем последний элемент, то очищаем весь дек
	{
		firstEl = 0;
		lastEl = 0;
		printf("элемент %i удален\n", node->value);
		delete[] node;
		return true;
	}
	if (next) //если существует следующий элемент
	{
		next->prev = prev;	 // предыдущий next элемента делаем предыдущим
		if (node == firstEl) //если node первый элемент
			firstEl = next;	 //первый элемент делаем равным следующему
	}
	if (prev) //если существует предыдущий элемент
	{
		prev->next = next;	//следующий prev элемента делаем следующим
		if (node == lastEl) //если node последний элемент
			lastEl = prev;	//последний элемент делаем равным prev
	}
	printf("элемент %i удален\n", node->value);
	delete[] node; //удаляем node
	return true;
}
void Dack::changeValueOfEl(NodeDack *node, int value) //изменение узла node
{
	if (!node) //если node не существет
	{
		printf("элемента не существует \n");
		return;
	}
	if (node)
		node->value = value; //изменяем значение node
	printf("элемент изменен\n");
}
void Dack::print() //вывод всех элементов дека
{
	if (!firstEl) //если нет первого элемента
	{
		printf("дек пуст");
	}
	else
	{
		NodeDack *el = firstEl;
		while (el) //выводим все элемента дека через пробел
		{
			printf("%i ", el->value);
			el = el->next;
		}
	}
	printf("\n");
}
void Dack::clear() //очищение дека
{
	if (!firstEl) //если нет элементов выходим
		return;
	NodeDack *el = firstEl;
	NodeDack *next;
	while (el) //итерационно удаляем все элементы в деке
	{
		next = el->next;
		DeleteNode(el);
		el = next;
	}
	printf("Дек очищен\n");
}
void Dack::showValueOfEl(NodeDack *node) //показать значение узла node
{
	if (!node)
		printf("элемента не существует\n");
	if (node)
		printf("значение элемента %i\n", node->value);
}
void Dack::isEmpty() // проверка на пустоту дека
{
	if (!firstEl) //если не существует первого элемента
	{
		printf("дек пустой\n");
		return;
	}
	printf("дек не пустой\n");
}
Dack::~Dack() //деструктор дека
{
	clear(); //очищаем все элементы
}
void Dack::showValueOfHead() //показать значение в начале дека
{
	showValueOfEl(firstEl); //показываем значение firstEl
}
void Dack::showValueOfEnd() //показать значение в конце дека
{
	showValueOfEl(lastEl); //показываем значение lastEl
}
void Dack::deleteValueOfHead() //удалить значение в начале дека
{
	DeleteNode(firstEl); //удаляем узел firstEl
}
void Dack::deleteValueOfEnd() //удалить значение в конце дека
{
	DeleteNode(lastEl); //удаляем узел lastEl
}
void Dack::takeValueOfHead() //взять первый элемент
{
	showValueOfEl(firstEl); //показываем значение firstEl
	DeleteNode(firstEl);	//удаляем узел firstEl
}
void Dack::takeValueOfEnd() //взять последний элемент
{
	showValueOfEl(lastEl); //показываем значение lastEl
	DeleteNode(lastEl);	   //удаляем узел lastEl
}
void Dack::changeValueOfHead(int value) //изменить значение в начале дека
{
	changeValueOfEl(firstEl, value); //изменяем значение узла firstEl
}
void Dack::changeValueOfEnd(int value) //изменить значение в конце дека
{
	addBeforeNode(firstEl, value); //изменяем значение узла lastEl
}
void Dack::addValueOfHead(int value) //добавить значение в начале дека
{
	addBeforeNode(firstEl, value); //добавляем элемент после узла firstEl
}
void Dack::addValueOfEnd(int value) //добавить значение в концне дека
{
	addAfterNode(lastEl, value); //добавляем элемент после узла lastEl
}
void Dack::Menu() //меню дека
{
	puts("\n1 Сделать дек пустым\n \
		\r2 Проверка:дек пуст/не пуст\n \
		\r3 Показать значение в начале дека\n \
		\r4 Показать значение в конце дека\n \
		\r5 Удалить начало дека\n \
		\r6 Удалить конец дека\n \
		\r7 Взять элемент из начала дека\n \
		\r8 Взять элемент из конца дека  \n \
		\r9 Изменить значение элемента в начале дека\n \
		\r10 Изменить значение элемента в конце дека\n \
		\r11 Добавить элемент в начало дека\n \
		\r12 Добавить элемент в конец дека\n \
		\r13 Закончить работу с деком\n");
}
void Dack::Close() {
	isOpen = false;
}
void Dack::Open() //начать работу с деком
{
	isOpen = true;
	while (isOpen) //если работа с деком не завершена
	{
		system("cls"); //очищаем экран
		print();	   //выводим список
		Menu();		   //выводим меню
		printf("Введите=");
		int option, value;
		scanf_s("%i", &option);			 //вводим опцию
		if (option >= 9 && option <= 12) //если опция от 9 до 12
		{
			printf("Значение=");
			scanf_s("%i", &value); //вводим значение
		}
		switch (option) //для каждой опции вызываем связанную с ней функцию
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
			printf("Опция не действительна");
			break;
		}
		Sleep(500); //делаем задержку 0.5с
	}
}