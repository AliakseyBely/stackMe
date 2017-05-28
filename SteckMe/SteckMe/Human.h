#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "VvodExc.h"
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::fstream;

class Human
{
public:
	void setInf();
	virtual void getHeder();

	bool operator == (const Human& obj) const;
	friend ostream &operator << (ostream& stream, Human& obj);
	friend istream &operator >> (istream& stream, Human& obj);
	friend ofstream &operator << (ofstream& stream, Human& obj);
	friend ifstream &operator >> (ifstream& stream, Human& obj);
	friend fstream &operator << (fstream& stream, Human& obj);
	friend fstream &operator >> (fstream& stream, Human& obj);

protected:
	string _name;
	int _age;
};

void Human::setInf()
{
	_name = trystr_rusengl("Укажите ФИО: ");
	_age = try_int("Укажите возраст: ");
}

void Human::getHeder()
{
	cout << "+-------------+-------+" << endl;
	cout << "|     ФИО     |  Лет  |" << endl;
	cout << "+-------------+-------+" << endl;
}

bool Human::operator== (const Human& obj) const
{
	if (_age == obj._age && _name == obj._name)
		return true;
	else
		return false;
}

ostream &operator << (ostream& stream, Human& obj) 
{
	stream << obj._name << setw(15) << obj._age << endl;
	return stream;
}

istream &operator >> (istream& stream, Human& obj) 
{
	obj._name = trystr_rusengl("Укажите ФИО: ");
	obj._age = try_int("Укажите возраст: ");
	return stream;
}

ofstream &operator << (ofstream& stream, Human& obj)
{

	stream << obj._name << setw(15) << obj._age << endl;
	return stream;
}

ifstream &operator >> (ifstream& stream, Human& obj)
{
	stream >> obj._name >> obj._age;
	return stream;
}

fstream &operator << (fstream& stream, Human& obj)
{
	int aa = obj._name.size();
	stream.write(reinterpret_cast<char*>(&aa), sizeof(int));
	stream.write(obj._name.c_str(), aa);
	stream.write(reinterpret_cast<char*>(&obj._age), sizeof(int));
	stream << setw(6);
	return stream;
}

fstream &operator >> (fstream& stream, Human& obj)
{
	int bb;
	stream.read(reinterpret_cast<char *>(&bb), sizeof(int));
	obj._name.resize(bb);
	stream.read(&obj._name[0], bb);
	stream.read(reinterpret_cast<char *>(&obj._age), sizeof(int));
	return stream;
}

//сделать чтобы записывалось и считывалось "Белый Алексей"