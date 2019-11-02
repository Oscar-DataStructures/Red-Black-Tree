/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/


#include <sstream>
#include <string>
#include <iostream>
#include <typeinfo>


using namespace std;



// ================================= Constructor ===============================
template <class KeyType>
hashtable<KeyType>::hashtable(int numSlots)
//Preconditions:  N/A
//Postcondition:  dynamically allocated table with size numSlots where each list in array is null
{
  count = 0;
  slots = numSlots;
  table = new List<KeyType>[numSlots];    //dynamically allocated table
  for(int i = 0; i < table->size; i++)    //iterates throughout the table
  {
    table[i].head = NULL;   //sets each list's head to NULL
  }
}


// ============================== Copy Constructor ==============================
template <class KeyType>
hashtable<KeyType>::hashtable(const hashtable<KeyType>& h)
//Preconditions:  Can only be used for construction
//Postcondition:  Current hashtable will be a copy of h hashtable
{
  count = h.count;
  slots = h.slots;
  table = new List<KeyType>[slots];   //dynamically allocated table
  table->size = h.table->size;
  for(int i = 0; i < table->size; i++)    //iterates throughout the table
  {
    table[i] = List<KeyType>::deepCopy(h.table[i]);   //inherits Lists deep copy method and ultizes it
  }
}


// ================================= DeConstructor =============================
template <class KeyType>
hashtable<KeyType>::~hashtable()
//Preconditions:  Hashtable must exist to be deallocated
//Postcondition:  Deallocates memory and destroys existing bst
{
  count = 0;
  for(int i = 0; i < table->size; i++)
  {
    List<KeyType>::~List();   //inherits Lists DeConstructor and ultizes it
  }
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* hashtable<KeyType>::get(const KeyType& k) const
//Preconditions:  K must be a pair that exists in hashtable
//Postcondition:  Throws a key error if not found and returns pointer if found
{
  int hSlots = k.hash(slots);   //can only call const functions on k bc k is const
  KeyType kSet = k;
  KeyType* kptr = &kSet;
  int result = table[hSlots].index(k);    //index method returns -1 if not found and index if found
  if (result == -1)   //not found
  {
    throw KeyError();
  }

  else    //found so return pointer
  {
    Node<KeyType>* current = table[hSlots].head;
    for(int i = 0; i < table->size; i++)    //iterates throughout the table
    {
      if (kptr == current-> data)
        return kptr;
      // if ((table[hSlots]) == k)    //so the logic here is that we find the element in the list and return the pointer to it
      // {                                //that way we dont have to return k which is const
      //   return table[hSlots][i];
      // }
      else
        current = current->next;
    }
  }

  // int hSlots = k.hash(slots);
  // KeyType* result = table[hSlots].find(k);
  //
  // return result;
}



// ================================ Insert Method ==============================
template <class KeyType>
void hashtable<KeyType>::insert(KeyType* k)
//Preconditions:  N/A
//Postcondition:  k will be inserted into the hashtable at the apriopiate slot
{
  int hSlots = k->hash(slots);
  table[hSlots].headAppend(k);
  count++;
}



// ================================ Remove Method ==============================
template <class KeyType>
void hashtable<KeyType>::remove(const KeyType& k)   //TODO[ASK]: how const changes this
//Preconditions:  k must be in the hashtable
//Postcondition:  k will be removed from the hashtable if it exists, if it doesnt then KeyError
{
  int hSlots = k.hash(slots);
  table[hSlots].remove(k);    //calls the list remove which has key error catch
  count--;
}


// ============================== Slot Size Method =============================
template <class KeyType>
int hashtable<KeyType>::slotSize()
//Preconditions:  N/A
//Postcondition:  N/A
{
  return slots;
}


// ============================= Assignment Operator ===========================
template <class KeyType>
hashtable<KeyType>& hashtable<KeyType>::operator=(const hashtable<KeyType>& h)
//Preconditions:  N/A
//Postcondition:  Returns hashtable that is the same as the parameter hashtable h
{
  if (h.table != this->table)
  {
    delete [] table;
    for (int i = 0; i < h.slots; i++)   //iterates through the hashtable
    {
      table[i] = h.table[i];    //Assignment using the list assignment method
    }
  }

  slots = h.slots;

  return *this;
}


// =============================== toString Method =============================
template <class KeyType>
string hashtable<KeyType>::toString(int slot) const
//Preconditions:  N/A
//Postcondition:  Return string representation of linked list at slot
{
  string result = table[slot].toString();   //uses the list toString method

  return result;
}
