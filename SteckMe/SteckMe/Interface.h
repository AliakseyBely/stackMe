#pragma once
#include <iomanip>
#include <iostream>
#include "Poker.h"
#include "IntefaceInSteck.h"

using std::cin;
using std::cout;
using std::setw;
using std::endl;

class Interface
{
public:
	void Page1();
};

void Interface::Page1()
{
	int n;
	do {
		system("cls");
		cout << setw(29) << "Меню №1" << setw(22)<< "|" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Выберите класс с которым будете работать:         |" << endl;
		cout << "1 - Класс Human                                   |" << endl;
		cout << "2 - Класс Tourist                                 |" << endl;
		cout << "3 - Класс Venturer                                |" << endl;
		cout << "4 - Класс Poker                                   |" << endl;
		cout << "5 - Выйти из программы                            |" << endl;
		cout << "---------------------------------------------------" << endl;
		n = try_int("Ваш выбор:  ");

		switch (n)
		{
		case 1:
		{
			Interface2<Human> obj;
			obj.Page2("Human.txt");
			break;
		}
		/*case 2:
		{
			Interface2<Tourist> obj;
			obj.Page2("Tourist.txt");
			break;
		}
		case 3:
		{
			Interface2<Venturer> obj;
			obj.Page2("Venturer.txt");
			break;
		}
		case 4:
		{
			Interface2<Poker> obj;
			obj.Page2("Poker.txt");
			break;
		}*/
		default:
			break;
		}
	} while (n != 5);
}
