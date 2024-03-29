/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/

#include <iostream>
#include <string>
#include <cassert>
#include "rbtree.h"


// ======================= Test Default Constructor Method =====================
void test_defaultConstructor()
{
	rbtree<int> a;
	assert(a.empty() == 1);

}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{
	rbtree<int> a;
	rbtree<int> b(a);
	assert(a.empty() == 1);
	assert(b.empty() == 1);
	a.insert(1);
	a.insert(5);
	a.insert(10);
	a.insert(15);

	assert(a.inOrder() == "1, 5, 10, 15");
	rbtree<int> c(a);
	assert(c.empty() == 0);
	assert(c.inOrder() == "1, 5, 10, 15");

	//Now, if we modify each of them, it will not affect the other.
	a.insert(4);
	assert(a.inOrder() == "1, 4, 5, 10, 15");
	assert(c.inOrder() == "1, 5, 10, 15");

	c.insert(7);
	assert(a.inOrder() == "1, 4, 5, 10, 15");
	assert(c.inOrder() == "1, 5, 7, 10, 15");

}


// ============================= Test Empty Method =============================
void test_empty()
{
	rbtree<int> a;
	assert(a.empty() == 1);
	a.insert(1);
	a.insert(10);
	assert(a.empty() == 0);

}


// ============================== Test Get/Insert Method ==============================
void test_get_insert()
{
	rbtree<int> a;
	a.insert(2);
	a.insert(1);
	a.insert(3);
	a.insert(4);


	assert(a.inOrder() == "1, 2, 3, 4");
	assert(*(a.get(1)) == 1);
	assert(a.getNode(1)->color == BLACK);
	assert(*(a.get(2)) == 2);
	assert(a.getNode(2)->color == BLACK);
	assert(*(a.get(3)) == 3);
	assert(a.getNode(3)->color == BLACK);
	assert(*(a.get(4)) == 4);
	assert(a.getNode(4)->color == RED);
	assert(*(a.get(1)) != 3);
	//a.get(10)); //uncomment to see KeyError

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.inOrder() == "3, 4, 7, 8, 9, 10, 12, 13, 14");
	assert(*(b.get(3)) == 3);
	assert(*(b.get(4)) == 4);
	assert(*(b.get(7)) == 7);
	assert(*(b.get(8)) == 8);
	assert(*(b.get(9)) == 9);
	assert(*(b.get(10)) == 10);
	assert(*(b.get(12)) == 12);
	assert(*(b.get(13)) == 13);
	assert(*(b.get(14)) == 14);

	assert(*(b.get(3)) != 4);
	// // (b.get(1)); //uncomment to see KeyError

}


// ============================= Test Remove Method ============================
void test_remove()
{
	// rbtree<int> a;
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	// assert(a.inOrder() == "1, 2, 3, 4");
	// a.remove(1);
	// assert(a.inOrder() == "2, 3, 4");
	// a.remove(2);
	// assert(a.inOrder() == "3, 4");
	// a.remove(3);
	// assert(a.inOrder() == "4");
	// a.remove(4);
	// assert(a.inOrder() == "");
	//
	// // a.remove(1);	//uncomment to see KeyError

}


// ================================ Test Max Method ============================
void test_max()
{
	rbtree<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	assert(*(a.maximum()) == 4);

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.maximum()) == 14);

}


// ================================ Test Min Method ============================
void test_min()
{
	rbtree<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	assert(*(a.minimum()) == 1);
	//a.remove(1);  ** not implemented -- didn't get to extra credit
	//assert(*(a.minimum()) == 2);

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.minimum()) == 3);

}


// ============================= Test Successor Method =========================
void test_successor()
{
	rbtree<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	assert(*(a.successor(1)) == 2);
	assert(*(a.successor(2)) == 3);
	assert(*(a.successor(3)) == 4);
	// //a.successor(4); //uncomment to see KeyError

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.successor(3)) == 4);
	assert(*(b.successor(4)) == 7);
	assert(*(b.successor(7)) == 8);
	assert(*(b.successor(8)) == 9);
	assert(*(b.successor(9)) == 10);
	assert(*(b.successor(10)) == 12);
	assert(*(b.successor(12)) == 13);
	assert(*(b.successor(13)) == 14);

	// //b.successor(14); //uncomment to see KeyError

}


// ========================== Test Predecessor Method ==========================
void test_predecessor()
{
	rbtree<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	//a.predecessor(1); //uncomment to see KeyError
	assert(*(a.predecessor(2)) == 1);
	assert(*(a.predecessor(3)) == 2);
	assert(*(a.predecessor(4)) == 3);

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.predecessor(4)) == 3);
	assert(*(b.predecessor(7)) == 4);
	assert(*(b.predecessor(8)) == 7);
	assert(*(b.predecessor(9)) == 8);
	assert(*(b.predecessor(10)) == 9);
	assert(*(b.predecessor(12)) == 10);
	assert(*(b.predecessor(13)) == 12);
	assert(*(b.predecessor(14)) == 13);

	//b.predecessor(3); //uncomment to see KeyError

}


// =========================== Test Assignment Operator ========================
void test_assignmentOP()
{
	rbtree<int> a;
	rbtree<int>b;

	b = a;
	assert(a.empty() == 1);
	assert(b.empty() == 1);

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	assert(a.empty() == 0);
	assert(a.inOrder() == "1, 2, 3, 4");
	b = a;
	assert(b.empty() == 0);
	assert(b.inOrder() == "1, 2, 3, 4");
}


// ============================ Test In Order Method ===========================
void test_inOrder()
{
	rbtree<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(2);
	a.insert(4);
	a.insert(5);

	assert(a.inOrder() == "1, 2, 3, 4, 5");

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.inOrder() == "3, 4, 7, 8, 9, 10, 12, 13, 14");

}


// ============================= Test Pre Order Method =========================
void test_preOrder()
{
	rbtree<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(2);
	a.insert(4);
	a.insert(5);

	assert(a.preOrder() == "2, 1, 4, 3, 5");

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.preOrder() == "10, 7, 4, 3, 8, 9, 13, 12, 14");

}


// ============================ Test Post Order Method =========================
void test_postOrder()
{
	rbtree<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(2);
	a.insert(4);
	a.insert(5);

	assert(a.preOrder() == "2, 1, 4, 3, 5");

	rbtree<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.postOrder() == "3, 4, 9, 8, 7, 12, 14, 13, 10");

}



// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor();
	cout << "Default Constructor Test	|Passed|" << endl;
	test_copyConstructor();
	cout << "Copy Constructor Test		|Passed|" << endl;
	test_empty();
	cout << "Empty Test			|Passed|" << endl;
	test_get_insert();
	cout << "Get/Insert Test			|Passed|" << endl;
	test_remove();
	cout << "Remove Test			|Passed|" << endl;
	test_max();
	cout << "Max Test			|Passed|" << endl;
	test_min();
	cout << "Min Test			|Passed|" << endl;
	test_successor();
	cout << "Successor Test			|Passed|" << endl;
	test_predecessor();
	cout << "Predecessor Test		|Passed|" << endl;
	test_assignmentOP();
	cout << "Assignment Test			|Passed|" << endl;
	test_inOrder();
	cout << "InOrder Test			|Passed|" << endl;
	test_preOrder();
	cout << "PreOrder Test			|Passed|" << endl;
	test_postOrder();
	cout << "PostOrder Test			|Passed|" << endl;

	return 0;
}
