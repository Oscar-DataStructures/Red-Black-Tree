/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/

#ifndef _rbtree_h
#define _rbtree_h

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "rbtree.h"


template <class KeyType>
class rbtree  : public bst<KeyType>
{
	public:
		rbtree(); //constructor
		~rbtree(); //deconstructor
		rbtree(const rbtree<KeyType>& tree); //copy constructor
		bool empty() const; // return true if empty; false o/w

		KeyType* get(KeyType k) const; // return first item with key equal to k

		void insert(KeyType k); // insert k into the tree
		void remove(KeyType k); // delete first item with key equal to k
		rbtree<KeyType>& deepCopy(Node<KeyType>* subtreeRoot); // copy method for = operator and copy constructor

		KeyType* maximum() const; // return the maximum item
		KeyType* minimum()const ; // return the minimum item

		KeyType* successor(const KeyType& k) const; // return the successor of k
		KeyType* predecessor(const KeyType& k) const; // return the predecessor of k

		rbtree<KeyType>& operator=(const rbtree<KeyType>& tree); // assignment operator

		std::string inOrder() const; // return string of items from an inorder traversal
		std::string preOrder() const; // return string of items from a preorder traversal
		std::string postOrder() const; // return string of items from a postorder traversal

	protected:

		Node<KeyType>* root;
};

class KeyError{};

#include "rbtree.cpp"

#endif
