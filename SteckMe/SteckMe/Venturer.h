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
	_name = trystr_rusengl("������� ���: ");
	_age = try_int("������� �������: ");
	_profit = try_int("������� ���������� �����: ");
}

void Venturer::getHeder()
{
	cout << "\n������� 3 - ����� Venturer" << endl;
	cout << "+-------------+---------+----------+" << endl;
	cout << "|     ���     | ������� |  ������� |" << endl;
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