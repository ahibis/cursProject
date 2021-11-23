#include <iostream>
#include <locale>
#include "List.h"

int main()
{
	setlocale(0, ""); //устанавливаем русский язык
	List list;		  //создаем объект списка
	list.Open();	  //открываем список
}