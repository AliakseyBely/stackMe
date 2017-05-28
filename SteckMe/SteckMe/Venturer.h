#pragma once
#include "Human.h"

class Venturer :
	public virtual Human
{
public:
	void setInf();
	virtual void getHeder();
	bool operator == (const Venturer& obj) const;

	friend ostream &operator << (ostream& stream, Venturer& obj);
	friend istream &operator >> (istream& stream, Venturer& obj);

protected:
	int _profit;
};


void Venturer::setInf()
{
	_name = trystr_rusengl("Укажите ФИО: ");
	_age = try_int("Укажите возраст: ");
	_profit = try_int("Укажите выигранную сумму: ");
}

void Venturer::getHeder()
{
	cout << "\nТаблица 3 - Класс Venturer" << endl;
	cout << "+-------------+---------+----------+" << endl;
	cout << "|     ФИО     | Возраст |  Выигрыш |" << endl;
	cout << "+-------------+---------+----------+" << endl;
}

bool Venturer::operator== (const Venturer& obj) const
{
	if (_age == obj._age && _name == obj._name)
		return true;
	else
		return false;
}

ostream &operator << (ostream& stream, Venturer& obj)
{
	stream << "|     " << obj._name << "    |   " << obj._age << "  |   " << obj._profit << "   |" << endl;
	stream << "+-------------+-------+----------+" << endl;
	return stream;
}

istream &operator >> (istream& stream, Venturer& obj)
{
	stream >> obj._name;
	stream >> obj._age;
	stream >> obj._profit;
	return stream;
}