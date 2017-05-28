#pragma once

template <class T>
struct Searcher
{
	const T _item;

	Searcher(T item) : _item(item)
	{	}

	bool operator() (const T& p) const
	{
		if (p == _item)
			return true;
		else return false;
	}
};