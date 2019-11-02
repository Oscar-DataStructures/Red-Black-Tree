/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/

#include <sstream>
#include <string>
#include <typeinfo>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;


class KeyError{};




// ================================= Constructor ===============================
template <class KeyType>
rbtree<KeyType>::rbtree()
// PreConditions:		N/A
// PostConditions:	N/A
{

}


// ================================ DeConstructor ==============================
template <class KeyType>
rbtree<KeyType>::~rbtree()
// PreConditions:		A rbtree must exist for this to be called one
// PostConditions:	Calls clearNodes which deletes rbtree
{

}


// =============================== Copy Constructor ============================
template <class KeyType>
rbtree<KeyType>::rbtree(const rbtree<KeyType>& tree)
// PreConditions:		Can only be used for construction
// PostConditions:	Current tree will be a copy of tree
{

}


// ================================= Empty Method ==============================
template <class KeyType>
bool rbtree<KeyType>::empty() const
// PreConditions: 	Must be called on a rbtree
// PostConditions:  Return True if empty, False if not
{

}


// ================================= Get Method ================================
template <class KeyType>
KeyType* rbtree<KeyType>::get(KeyType k) const
// PreConditions: 	Tree must exist and not be empty
// PostConditions:  Return first item in rbtree that has key k
{

}


// ================================ Insert Method ==============================
template <class KeyType>
void rbtree<KeyType>::insert(KeyType k)
// PreConditions:		N/A
// PostConditions:	Inserts a node containing k into the rbtree while maintaining the rbtree property
{

}


// ================================ Remove Method ==============================
template <class KeyType>
void rbtree<KeyType>::remove(KeyType k)
// PreConditions:		Tree cannot be empty and key must be in rbtree
// PostConditions:	Node with value k will be removed and tree restructured
{

}


// ============================= Deep Copy Method ==============================
template <class KeyType>
rbtree<KeyType>& rbtree<KeyType>::deepCopy(Node<KeyType>* subtreeRoot)
// PreConditions:		N/A
// PostConditions:	Returns a pointer to current rbtree that is a copy of subtreeRoot
{

}


// ================================== Max Method ===============================
template <class KeyType>
KeyType* rbtree<KeyType>::maximum() const
// PreConditions: 	Root cannot be null
// PostConditions:  Return max item
{

}



// ================================= Min Method ================================
template <class KeyType>
KeyType* rbtree<KeyType>::minimum() const
// PreConditions: 	Root cannot be null
// PostConditions:  Return min item
{

}



// ============================= Successor Method ==============================
template <class KeyType>
KeyType* rbtree<KeyType>::successor(const KeyType& k) const
// PreConditions: 	Root cannot be null
// PostConditions:  Return successor of k
{

}



// ============================ Predecessor Method =============================
template <class KeyType>
KeyType* rbtree<KeyType>::predecessor(const KeyType& k) const
// PreConditions: 	Root cannot be null
// PostConditions:  Return predecessor of k
{

}


// ============================= Assignment Operator ===========================
template <class KeyType>
rbtree<KeyType>& rbtree<KeyType>::operator=(const rbtree<KeyType>& tree)
// PreConditions:		N/A
// PostConditions:  Make current tree equivalent to tree
{

}


// =============================== InOrder Method ==============================
template <class KeyType>
string rbtree<KeyType>::inOrder() const
// PreConditions:		rbtree must exist
// PostConditions:	Return a string representation of the inOrder walk of the rbtree
{

}


// ============================== PreOrder Method ==============================
template <class KeyType>
string rbtree<KeyType>::preOrder() const
// PreConditions:		rbtree must exist
// PostConditions:	Return a string representation of the preOrder walk of the rbtree
{

}



// ============================= PostOrder Method ==============================
template <class KeyType>
string rbtree<KeyType>::postOrder() const
// PreConditions:		rbtree must exist
// PostConditions:	Return a string representation of the postOrder walk of the rbtree
{

}
