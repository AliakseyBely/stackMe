#pragma once

#include <iostream>
#include "Stack.h"
#include "Searcher.h"
#include "BinFile.h"


template <class T>
class Interface2
{
public:
	void Page2(char*);
};

template <class T>
void Interface2<T>::Page2(char* Fname)
{
	Stack <T> stack;
	BinFile<T> file(Fname);
	T value;
	int m;
	do
	{
		system("cls");
		cout << setw(29) << "Меню №2" << setw(22) << "|" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Выберите действие со стеком:                      |" << endl;
		cout << "1 - Добавить элемент в стек                       |" << endl;
		cout << "2 - Найти элемент                                 |" << endl;
		cout << "3 - Распечатать содержимое стека                  |" << endl;
		cout << "4 - Удалить последний элемент                     |" << endl;
		cout << "5 - Очистить стек                                 |" << endl;
		cout << "6 - Записать содержимое стека в файл              |" << endl;
		cout << "7 - Заполнить стек из файла                       |" << endl;
		cout << "8 - Записать в бинарный файл                      |" << endl;
		cout << "9 - Заполнить из бинарного файла                  |" << endl;
		cout << "10 - Вернуться к Меню №1                          |" << endl;
		cout << "---------------------------------------------------" << endl;
		m = try_int("Ваш выбор:  ");
		cout << "---------------------------------------------------\n" << endl;

		switch (m)
		{
		case 1:	{
			cout << "Добавление элемента:" << endl;
			value.setInf();
			stack.push(value);
			break;
		}
		//ToDo: Добавить элемент в стек
		case 2:	{
			cout << "Поиск элемента:\n" << endl;
			cout << "---------------------------------------------------\n" << endl;
			cout << "Введите эталон: " << endl;
			value.setInf();
			cout << "---------------------------------------------------\n" << endl;

			value.getHeder();
			Stack<T> SearchValue = stack.Search(Searcher<T>(value));

			if (!SearchValue.empty())
				cout << endl << SearchValue << endl;
			else
				cout << "Поиск не дал результатов" << endl;

			system("pause");
			break;
		}
		//ToDo: Найти элемент
		case 3:	{
			value.getHeder();
			cout << stack;
			system("pause");
			break;
		}
		//ToDo: Распечатать содержимое
		case 4:	{
			stack.pop();
			break;
		}
		//ToDo: Удалить пследний элемент
		case 5:	{
			stack.pop1();
			break;
		}
		//Todo: Очистить стек
		case 6: {
			stack.outFile(Fname);
			cout << "Данные записаны в файл: " << Fname << endl;
			system("pause");
			break;
		}
		//ToDo: Закинуть в файл
		case 7: {
			stack.inFile(Fname);
			cout << "Данные взяты из: " << Fname << endl;
			system("pause");
			break;
		}
		//ToDo: Взять из файла
		case 8: {
			file.relive();
			while (stack.empty()) {
				value = stack.pop2();
				file.outFile(value);
			}
			cout << "Данные записаны в файл: " << Fname << endl;
			system("pause");
			break;
		}
		//ToDo: Запись в бинарный файл	
		case 9: {
			file.relive();
			while (1) {				
				file.inFile(value);
				if (!file.endFile())
					break;
				stack.push(value);
			}
			file.relive();

			cout << "Данные взяты из: " << Fname << endl;
			system("pause");
			break;
		}		
		//ToDo: Взять из бинарного файла
		}
	} while (m != 10);
}
