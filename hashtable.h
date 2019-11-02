/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/


#ifndef _hashtable_h
#define _hashtable_h

#include "List.h"
#include <string>

int DEFAULT_SIZE = 100000;

template <class KeyType>
class hashtable : public List<KeyType>
{
  public:
    hashtable(int numSlots = DEFAULT_SIZE);    //default Constructor with a slot number to make table size of numSlots
    hashtable(const hashtable<KeyType>& h);   //copy Constructor
    ~hashtable();   //DeConstructor

    KeyType* get(const KeyType& k) const;   //returns a pointer to object holding k
    void insert(KeyType* k);    //inserts k into the apriopiate slot in the table
    void remove(const KeyType& k);    //removes k from the apriopiate slot in the table
    int slotSize();

    hashtable<KeyType>& operator=(const hashtable<KeyType>& h);   //sets this table equal to the assigned h's table
    std::string toString(int slot) const;   //provides a string representation of a slot in the table

    int slots;    //how many slots are in the table
    List<KeyType>* table; // an array of linked lists. ie slots
    int count;
};



#include "hashtable.cpp"

#endif
