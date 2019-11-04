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
#include <vector>
#include "rbtree.h"

using namespace std;

enum Color {RED, BLACK};		//makes red = 1, 0 = black

template <class KeyType>
class Node
{
	public:

		KeyType key;		//value held in node
		bool color;		//color of node. 1 is red, 0 is black

		Node<KeyType>* parent;		//parent node
		Node<KeyType>* left;		//left child
		Node<KeyType>* right;		//right child
};

template <class KeyType>
Node<KeyType>* newNode(KeyType key);

template <class KeyType>
class rbtree
{
	public:
		rbtree();		//constructor
		~rbtree();		//deconstructor
		rbtree(const rbtree<KeyType>& tree);		//copy constructor
		bool empty() const;		// return true if empty; false o/w

		KeyType* get(KeyType k) const;		// return first item with key equal to k

		bool getColor(KeyType k);		//gets the color of the first node with key equal to k

		void insert(KeyType k);		// insert k into the tree
		void remove(KeyType k);		// delete first item with key equal to k
		rbtree<KeyType>& deepCopy(Node<KeyType>* subtreeRoot);		// copy method for = operator and copy constructor

		KeyType* maximum() const;		// return the maximum item
		KeyType* minimum()const ;		// return the minimum item

		KeyType* successor(const KeyType& k) const;		// return the successor of k
		KeyType* predecessor(const KeyType& k) const;		// return the predecessor of k

		rbtree<KeyType>& operator=(const rbtree<KeyType>& tree);		// assignment operator

		string inOrder() const;		// return string of items from an inorder traversal
		string preOrder() const;		// return string of items from a preorder traversal
		string postOrder() const;		// return string of items from a postorder traversal

	protected:
		void clearNodes();
		Node<KeyType>* helpGet(KeyType k) const;
		Node<KeyType>* recursiveRemove(Node<KeyType>* root, KeyType k);

		void leftRotate(Node<KeyType>* root, Node<KeyType>* pivot);
		void rightRotate(Node<KeyType>* root, Node<KeyType>* pivot);
		void fixColor(Node<KeyType>* root, Node<KeyType>* inNode);

		Node<KeyType>* helpMin(Node<KeyType>* subtreeRoot) const;
		KeyType* helpMax(Node<KeyType>* subtreeRoot) const;

		Node<KeyType>* successorNode(const KeyType& k) const;

		vector<KeyType> recInOrder(Node<KeyType>* subtreeRoot, vector<KeyType>& s) const;
		vector<KeyType> recPreOrder(Node<KeyType>* subtreeRoot, vector<KeyType>& s) const;
		vector< Node<KeyType>* > recPostOrder(Node<KeyType>* subtreeRoot, vector< Node<KeyType>* > &s) const;



	private:
		Node<KeyType>* root;
};

class KeyError{};

#include "rbtree.cpp"

#endif
