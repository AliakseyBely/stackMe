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
	_name = trystr_rusengl("������� ��� ������: ");
	_age = try_int("������� �������: ");
	_passport = trystr_rusengl("������� ������: ");
	_skill = try_int("������� ���� ����: ");
	_profit = try_int("������� �������: ");
}

void Poker::getHeder()
{
	cout << "\n������� 4 - ����� Poker" << endl;
	cout << "+------------+---------+--------+-----------+---------+" << endl;
	cout << "| ��� ������ | ������� | ������ | ���� ���� | ������� |" << endl;
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