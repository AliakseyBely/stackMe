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
		cout << setw(29) << "���� �2" << setw(22) << "|" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "�������� �������� �� ������:                      |" << endl;
		cout << "1 - �������� ������� � ����                       |" << endl;
		cout << "2 - ����� �������                                 |" << endl;
		cout << "3 - ����������� ���������� �����                  |" << endl;
		cout << "4 - ������� ��������� �������                     |" << endl;
		cout << "5 - �������� ����                                 |" << endl;
		cout << "6 - �������� ���������� ����� � ����              |" << endl;
		cout << "7 - ��������� ���� �� �����                       |" << endl;
		cout << "8 - �������� � �������� ����                      |" << endl;
		cout << "9 - ��������� �� ��������� �����                  |" << endl;
		cout << "10 - ��������� � ���� �1                          |" << endl;
		cout << "---------------------------------------------------" << endl;
		m = try_int("��� �����:  ");
		cout << "---------------------------------------------------\n" << endl;

		switch (m)
		{
		case 1:	{
			cout << "���������� ��������:" << endl;
			value.setInf();
			stack.push(value);
			break;
		}
		//ToDo: �������� ������� � ����
		case 2:	{
			cout << "����� ��������:\n" << endl;
			cout << "---------------------------------------------------\n" << endl;
			cout << "������� ������: " << endl;
			value.setInf();
			cout << "---------------------------------------------------\n" << endl;

			value.getHeder();
			Stack<T> SearchValue = stack.Search(Searcher<T>(value));

			if (!SearchValue.empty())
				cout << endl << SearchValue << endl;
			else
				cout << "����� �� ��� �����������" << endl;

			system("pause");
			break;
		}
		//ToDo: ����� �������
		case 3:	{
			value.getHeder();
			cout << stack;
			system("pause");
			break;
		}
		//ToDo: ����������� ����������
		case 4:	{
			stack.pop();
			break;
		}
		//ToDo: ������� �������� �������
		case 5:	{
			stack.pop1();
			break;
		}
		//Todo: �������� ����
		case 6: {
			stack.outFile(Fname);
			cout << "������ �������� � ����: " << Fname << endl;
			system("pause");
			break;
		}
		//ToDo: �������� � ����
		case 7: {
			stack.inFile(Fname);
			cout << "������ ����� ��: " << Fname << endl;
			system("pause");
			break;
		}
		//ToDo: ����� �� �����
		case 8: {
			file.relive();
			while (stack.empty()) {
				value = stack.pop2();
				file.outFile(value);
			}
			cout << "������ �������� � ����: " << Fname << endl;
			system("pause");
			break;
		}
		//ToDo: ������ � �������� ����	
		case 9: {
			file.relive();
			while (1) {				
				file.inFile(value);
				if (!file.endFile())
					break;
				stack.push(value);
			}
			file.relive();

			cout << "������ ����� ��: " << Fname << endl;
			system("pause");
			break;
		}		
		//ToDo: ����� �� ��������� �����
		}
	} while (m != 10);
}
