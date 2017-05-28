#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <iomanip>

using namespace std;
//using std::istream;
//using std::ostream;
//using std::function;

template <class T>
struct item
{
	T i;
	item *next;
};

template <class T>
class Stack
{
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	void push(T);
	Stack Search(function<bool(const T&)> criterii) const;
	void show(T);
	void pop();
	void pop1();
	T pop2();
	bool empty();
	void outFile(char*);
	void inFile(char*);
	//void outBinaryFile(char*);
	//void inBinaryFile(char*);

	template <class U>
	friend ostream& operator<< (ostream& stream, const Stack<U>& obj);

private: 
	item <T> *head;
};


template <class T>
Stack<T>::Stack()
{
	head = NULL;
}

template <class T>
Stack<T>::Stack(const Stack& obj)
{
	item<T> *head = obj.head;
	while (head != NULL)
	{
		push(head->i);
		head = head->next;
	}		
}

template <class T>
Stack<T>::~Stack()
{
	delete head;
}

template <class T>
void Stack<T>::push(T value)
{
	if (head == NULL)
	{
		head = new item <T>;
		head->i = value;
		head->next = NULL;
	}
	else
	{
		item <T> *newitem = new item <T>;
		newitem->i = value;
		newitem->next = head;
		head = newitem;
	}
}

template <class T>
Stack<T> Stack<T>::Search(function<bool(const T&)> criterii) const
{
	Stack <T> rez;
	for (item <T> *p = head; p != NULL; p = p->next)
	{
		const T i = p->i;
		if (criterii(i))
			rez.push(i);
	}
	return rez;
}

template <class T>
void Stack<T>::show(T)
{
	if (head == NULL)
		cout << "Стек не содержит элементов" << endl;

	item<T> p = head;
	while (p != NULL)
	{
		cout << p->i << endl;
		p = p->next;
	}
}

template <class T>
void Stack<T>::pop()
{
	if (head == NULL)
	{
		return;
	}
	
	item <T> *p = head;
	head = head->next;
	delete p;
}

template <class T>
void Stack<T>::pop1()
{
	if (head == NULL)
	{
		return;
	}

	while (head != NULL)
	{
		item <T> *p = head;
		head = head->next;		
		delete p;
	}
}

template <class T>
T Stack <T>::pop2()
{
	item <T> *p = head;
	head = head->next;
	T it = p->i;
	delete p;

	return it;
}

template <class T>
bool Stack<T>::empty()
{
	if (head == NULL) return false;
	else return true;
//	return head == NULL;
}

template <class U>
ostream& operator<< (ostream& stream, const Stack<U>& obj)
{
	if (obj.head == NULL)
	{
		stream << "Стек не содержит элементов" << endl;
		return stream;
	}

	item<U> *p = obj.head;
	while (p != NULL)
	{
		stream << p->i << endl;
		p = p->next;
	}
	return stream;
}

template <class T>
void Stack<T>::outFile(char* fname)				//запись в файл, не путать, твоя логика тут не работает
{
	if (head == NULL)
		cout << "Стек пуст, записывать нечего" << endl;

	ofstream file;
	item<T> *p = head;
	T obj;
	file.open(fname, ios::out);
	while(empty())
	{
		obj = pop2();
		file << obj;
	}
	file.close();
}

template <class T>
void Stack<T>::inFile(char* fname)
{
	ifstream file;
	T obj;
	file.open(fname, ios::in);
	while (1)
	{
		file >> obj;
		if (file.eof())
			break;
		push(obj);
	}
	file.close();
}
