#pragma once
#include "Human.h"

class Tourist :
	public virtual Human
{
public:
	virtual void getHeder();
	void setInf();
	bool operator== (const Tourist& obj) const;

	friend ostream &operator << (ostream& stream, Tourist& obj);
	friend istream &operator >> (istream& stream, Tourist& obj);

protected:
	string _passport;
};


void Tourist::setInf()
{
	_name = trystr_rusengl("������� ���: ");
	_age = try_int("������� �������: ");
	_passport = trystr_rusnumengl("������� ����� ��������: ");
}

void Tourist::getHeder()
{
	cout << "\n������� 2 - ����� Tourist" << endl;
	cout << "+-------------+-----------+------------------+" << endl;
	cout << "|     ���     |  �������  |  ����� ��������  |" << endl;
	cout << "+-------------+-----------+------------------+" << endl;
}

bool Tourist::operator== (const Tourist& obj) const
{
	if (_age == obj._age && _name == obj._name)
		return true;
	else
		return false;
}

ostream &operator << (ostream& stream, Tourist& obj)
{
	stream << obj._name << setw(25) << obj._age << setw(15) << obj._passport << setw(7) << endl;
	return stream;
}

istream &operator >> (istream& stream, Tourist& obj)
{
	stream >> obj._name;
	stream >> obj._age;
	stream >> obj._passport;

	return stream;
}
