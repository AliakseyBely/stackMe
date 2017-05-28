#pragma once
#include "Venturer.h"
#include "Tourist.h"

class Poker :
	public Venturer, public Tourist
{
public:
	void setInf();
	virtual void getHeder();
	bool operator== (const Poker& obj) const;
	

	friend ostream &operator << (ostream& stream, Poker& obj);
	friend istream &operator >> (istream& stream, Poker& obj);

protected:
	int _skill;
};


void Poker::setInf()
{
	_name = trystr_rusengl("Укажите имя игрока: ");
	_age = try_int("Укажите возраст: ");
	_passport = trystr_rusengl("Укажите страну: ");
	_skill = try_int("Укажите опыт игры: ");
	_profit = try_int("Укажите выигрыш: ");
}

void Poker::getHeder()
{
	cout << "\nТаблица 4 - Класс Poker" << endl;
	cout << "+------------+---------+--------+-----------+---------+" << endl;
	cout << "| Имя игрока | Возраст | Страна | Стаж игры | Выигрыш |" << endl;
	cout << "+------------+---------+--------+-----------+---------+" << endl;
}

bool Poker::operator== (const Poker& obj) const
{
	if (_age == obj._age && _name == obj._name)
		return true;
	else
		return false;
}

ostream &operator << (ostream& stream, Poker& obj)
{
	stream << obj._name << setw(10) << obj._age << setw(10) << obj._passport 
		<< setw(10) << obj._skill << setw(10) << obj._profit << endl;

	return stream;
}

istream &operator >> (istream& stream, Poker& obj)
{
	stream >> obj._name;
	stream >> obj._age;
	stream >> obj._passport;
	stream >> obj._skill;
	stream >> obj._profit;

	return stream;
}