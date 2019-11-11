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



// ================================= Constructor ===============================
template <class KeyType>
Dictionary<KeyType>::Dictionary() : rbtree<KeyType>()
//Preconditions:  N/A
//Postcondition:  Inherits rbtree constructor
{

}


// =============================== Copy Constructor ============================
template <class KeyType>
Dictionary<KeyType>::Dictionary(const Dictionary<KeyType>& dict) : rbtree<KeyType>(dict)
//Preconditions:    N/A
//Postcondition:    Inherits rbtree copy constructor
{

}


// ================================= Empty Method ==============================
template <class KeyType>
bool Dictionary<KeyType>::empty() const
//Preconditions:  Tree must exist
//Postcondition:  Inherits rbtree empty method to return whether the dict is empty
{
  return rbtree<KeyType>::empty();     //rbtree inheritance
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* Dictionary<KeyType>::get(const KeyType& k) const
//Preconditions:    Tree must exist
//Postcondition:    Inherits rbtree helpGet method to return key of dict or null if not found
{
  Node<KeyType>* output = rbtree<KeyType>::helpGet(k);     //rbtree inheritance
  if (output != NULL)
  {
    return &(output->key);
  }

  else
  {
    return NULL;
  }
}


// ================================ Insert Method ==============================
template <class KeyType>
void Dictionary<KeyType>::insert(KeyType k)
// PreConditions:   N/A
// PostConditions:  Inherits rbtree insert method to insert into dict value k
{
  Node<KeyType>* exists = rbtree<KeyType>::helpGet(k);

  if (exists == NULL)
  {
    rbtree<KeyType>::insert(k);      //rbtree inheritance
  }

  else
  {
    throw KeyError();             //KeyError caught
  }

}


// ================================ Remove Method ==============================
// template <class KeyType>
// void Dictionary<KeyType>::remove(const KeyType& k)
// //Preconditions:  Tree must exist
// //Postcondition:  Inherits remove method from rbtree to remove value k from dict
// {
//   rbtree<KeyType>::remove(k);      //rbtree inheritance
// }
