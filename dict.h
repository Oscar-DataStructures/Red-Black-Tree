/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/

#ifndef _dict_h
#define _dict_h

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "hashtable.h"

struct Pair
{
	string key;
	string value;

	int hash(int slots) const
	{
		int sum = 0;
		for (int i = 0; i < key.length(); i++)
		{
			sum += int(key[i]);
		}
		int m = 3079;
		float A = (sqrt(5) - 1) / 2;

		return int(m * (sum * A)) % slots;
	}

	bool operator==(const Pair p)
	{
		return key == p.key;
	}

	bool operator!=(const Pair p)
	{
		return key != p.key;
	}

	bool operator<(const Pair p)
	{
		return key < p.key;
	}

	bool operator>(const Pair p)
	{
		return key > p.key;
	}

	bool operator>=(const Pair p)
	{
		return key >= p.key;
	}

	bool operator<=(const Pair p)
	{
		return key <= p.key;
	}
};

std::ostream& operator<<(ostream& os, Pair p)
{
	return os << "{" + p.key + ", " + p.value + "}";
}

template <class KeyType1, class KeyType2>
class Dictionary : public hashtable<Pair>
{
  public:
    Dictionary(); //constructor
    Dictionary(const Dictionary<KeyType1, KeyType2>& dict); //copy constructor

    bool empty() const; // return true if empty; false o/w

    Pair* get(const KeyType1& k) const; // return first item with key equal to k

    void insert(KeyType1 k, KeyType2 v); // insert k into the tree, add unique key error
    void remove(const KeyType1& k); // delete first item with key equal to k

    //List<Pair<KeyType1, KeyType2>>* table;
    using hashtable<Pair>::table;
    using hashtable<Pair>::slots;
    using hashtable<Pair>::toString;
    using hashtable<Pair>::count;
};

#include "dict.cpp"

#endif
