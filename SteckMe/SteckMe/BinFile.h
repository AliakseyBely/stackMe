#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::cout;
using std::endl;

template <class T>
class BinFile
{
public:
	BinFile(string);
	~BinFile();
	void inFile(T& date);
	void outFile(T& date);
	bool endFile();
	void relive();

private:
	fstream fs;
	string fn;
};

//------------------------------------------------------------------------

template <class T>
BinFile<T>::BinFile(string fileName) 
	: fn(fileName)
{
	fs.open(fn, ios::out | ios::in | ios::binary);
	if (!fs)
		cout << "File bin can't open" << endl;
}

template <class T>
BinFile<T>::~BinFile()
{
	fs.close();
}

template <class T>
void BinFile<T>::inFile(T& obj)
{
	fs >> obj;
}

template <class T>
void BinFile<T>::outFile(T& obj)
{
	fs << obj;
}

template <class T>
void BinFile<T>::relive()
{
	fs.seekg(0, ios::beg);
	fs.clear();
}

template <class T>
bool BinFile<T>::endFile()
{
	if (fs.eof())
		return false;
	return true;
}