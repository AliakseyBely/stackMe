#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

char* vvod_stroki(char*);
double try_double(char*);
int try_int(char*);
double try_null(char*);
char* trystr_rus(char*);
char* trystr_rusnum(char*);
char* trystr_engl(char*);
char* trystr_englnum(char*);
char* trystr_rusengl(char*);
char* trystr_rusnumengl(char*);
void ITerminate();

class Excpt
{
public:
	Excpt(int a)
	{
		code = a;
	}

protected:
	int code;
};

//-----------------------------------

class VvodExc : public Excpt
{
	char message[80];

public:
	VvodExc(int k, char *ss) : Excpt(k)
	{
		strcpy(message, ss);

	}
	void show()
	{
		cout << "Exception: " << code << ". " << message << endl;
	}
	~VvodExc() {}
};




char* vvod_stroki(char* message = "")
{
	char* str = new char[200];
	int cp = GetConsoleCP();
	cout << message;
	SetConsoleCP(1251);
	cin >> str;
	SetConsoleCP(cp);

	return str;
}

void ITerminate()
{
	cout << "В программе возникла необрабатываемая ошибка" << endl;
	exit(-1);
}


//-Проверки-------------------------------------------------

double try_null(char* message = "")
{
	double a;
	bool tmp = true;	
	do {
		a = try_double(message);
		try {			
			if (a == 0)
				throw VvodExc(100, "The denominator is zero");
			tmp = false;
		}
		catch (VvodExc e) {
			e.show();			
		}
	} while (tmp);
	return a;
}					

char* trystr_rus(char* message = "")
{
	bool tmp = true;
	char* str = new char[80];
	do {
		try {
			str = vvod_stroki(message);
			int n = strlen(str);
			for (int i = 0; i < n; i++)
				if ((str[i] < 'А' || str[i] > 'п') && (str[i] < 'р' || str[i] > 'я'))
					throw VvodExc(101, "Input text contains incorrect character\n");
			tmp = false;
		}
		catch (VvodExc e) {
			e.show();
		}
	} while (tmp);
	return str;	
}

char* trystr_rusnum(char* message = "")
{
	bool tmp = true;
	char* str = new char[80];
	do {
		try {
			str = vvod_stroki(message);
			int n = strlen(str);
			for (int i = 0; i < n; i++)
				if ((str[i] < 'А' || str[i] > 'п') && (str[i] < 'р' || str[i] > 'я') && (str[i] < '0' || str[i] > '9'))
					throw VvodExc(102, "Input text contains incorrect character\n");
			tmp = false;
		}
		catch (VvodExc e) {
			e.show();
		}
	} while (tmp);
	return str;
}

char* trystr_engl(char* message = "")
{
	bool tmp = true;
	char* str = new char[80];
	do {
		try {
			str = vvod_stroki(message);
			int n = strlen(str);
			for (int i = 0; i < n; i++)
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
					throw VvodExc(103, "Input text contains incorrect character\n");
			tmp = false;
		}
		catch (VvodExc e) {
			e.show();
		}
	} while (tmp);
	return str;	
}

char* trystr_englnum(char* message ="")
{
	bool tmp = true;
	char* str = new char[80];
	do {
		try {
			str = vvod_stroki(message);
			int n = strlen(str);
			for (int i = 0; i < n; i++)
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && (str[i] < '0' || str[i] > '9'))
					throw VvodExc(104, "Input text contains incorrect character\n");
			tmp = false;
		}
		catch (VvodExc e) {
			e.show();
		}
	} while (tmp);
	return str;
}

char* trystr_rusengl(char* message = "")
{
	bool tmp = true;
	char* str = new char[80];
	do {
		try {
			str = vvod_stroki(message);
			int n = strlen(str);
			for (int i = 0; i < n; i++)
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'А' || str[i] > 'п') && (str[i] < 'р' || str[i] > 'я'))
					throw VvodExc(105, "Input text contains incorrect character\n");
			tmp = false;
		}
		catch (VvodExc e) {
			e.show();
		}
	} while (tmp);
	return str;
}

int try_int(char* message = "")
{
	int a;
	char ss[80];
	bool k = true;
	do
	{
		try {
			cout << message;
			cin >> a;
			if (cin.fail() || cin.peek() != '\n')
				throw VvodExc(106, "Input don't int");
			k = false;
		}
		catch (VvodExc exp) {
			k = true;
			exp.show();
			cin.clear(0);
			cin >> ss;
			//cin.sync();

		}
	} while (k);
	return a;
}

double try_double(char* message = "")
{
	double a;
	char ss[80];
	bool k = true;
	do {
		try 
		{
			cout << message;
			cin >> a;
			if (cin.fail() || cin.peek() != '\n')
				throw VvodExc(107, "Input don't double");
			k = false;
		}
		catch (VvodExc exp)
		{
			k = true;
			exp.show();
			cin.clear(0);
			cin >> ss;
		}
	} while (k);
	return a;
}

char* trystr_rusnumengl(char* message = "")
{
	bool tmp = true;
	char* str = new char[80];
	do {
		try {
			str = vvod_stroki(message);
			int n = strlen(str);
			for (int i = 0; i < n; i++)
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && 
					(str[i] < 'А' || str[i] > 'п') && (str[i] < 'р' || str[i] > 'я') && 
					(str[i] < '0' || str[i] > '9'))
					throw VvodExc(108, "Input text contains incorrect character\n");
			tmp = false;
		}
		catch (VvodExc e)
		{
			e.show();
		}
	} while (tmp);
	return str;
}



//ЛР2 (стек/шаблон наследование)
//функция записи объектов из шаблона
//чтение объектов из текстового файла и запись их в шаблон
//1 функция чтения и записи в файл (класс) = создать файл для работы с шаблонами 

//на следующую пару
//Работающий класс шаблон + наследование + стек 
//Ввод с клавиатуры в стек и записали в файл
//потом опять запустили прогу и загрузили из файла в стек данные 