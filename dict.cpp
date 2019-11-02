/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/

#include <sstream>
#include <string>
#include <typeinfo>


using namespace std;

// Pair struct
// template <class KeyType1, class KeyType2>
// struct Pair
// {
// 	KeyType1 key;
// 	KeyType2 value;
//
//
// };

// ================================= Constructor ===============================
template <class KeyType1, class KeyType2>
Dictionary<KeyType1, KeyType2>::Dictionary() : hashtable<Pair>(DEFAULT_SIZE)
//Preconditions:  N/A
//Postcondition:  Inherits hashtable constructor
{

}


// =============================== Copy Constructor ============================
template <class KeyType1, class KeyType2>
Dictionary<KeyType1, KeyType2>::Dictionary(const Dictionary<KeyType1, KeyType2>& dict) : hashtable<Pair>(dict)
//Preconditions:    N/A
//Postcondition:    Inherits hashtable copy constructor
{

}


// ================================= Empty Method ==============================
template <class KeyType1, class KeyType2>
bool Dictionary<KeyType1, KeyType2>::empty() const
//Preconditions:  Tree must exist
//Postcondition:  Returns whether or not dict is empty
{
  return count == 0;
}


// ================================= Get Method ================================
template <class KeyType1, class KeyType2>
Pair* Dictionary<KeyType1, KeyType2>::get(const KeyType1& k) const
//Preconditions:    Tree must exist
//Postcondition:    Returns key of dict or throws KeyError if not found
{
  Pair* p = new Pair;
  p->key = k;
  int hSlots = p->hash(slots);
  Pair pSet(*p);
  Pair* pPtr = &pSet;
  int result = table[hSlots].index(*p);
  if (result == -1)
  {
    throw KeyError();
  }

  else
  {
    Node<Pair>* current = table[hSlots].head;
    for(int i = 0; i < table->size; i++)
    {
      if (pPtr == current->data)
      {
        return pPtr;
      }
      else current = current->next;
    }
  }
}


// ================================ Insert Method ==============================
template <class KeyType1, class KeyType2>
void Dictionary<KeyType1, KeyType2>::insert(KeyType1 k, KeyType2 v)
// PreConditions:   N/A
// PostConditions:  Inserts pair into dict if its key isn't already in the dict
{
 try   // if a KeyError is received, that means k is not yet in the dict so we can add it
 {
    Pair* exists = new Pair;
    exists = get(k);
 }

  catch(KeyError e)   // add it
  {
    Pair* p = new Pair;
    p->key = k;
    p->value = v;
    int hSlots = p->hash(slots);
    //Pair* pPtr = &p;
    table[hSlots].headAppend(p);
    count++;
    return;

  }
  throw InsertError();             //KeyError caught
}


// ================================ Remove Method ==============================
template <class KeyType1, class KeyType2>
void Dictionary<KeyType1, KeyType2>::remove(const KeyType1& k)
//Preconditions:  Tree must exist
//Postcondition:  Removes pair with key k from dictionary (if it's in there)
{
  Pair* p = new Pair;
  p->key = k;
  p->value = "";

  int hSlots = p->hash(slots);

  table[hSlots].remove(*p);
  count--;
}
