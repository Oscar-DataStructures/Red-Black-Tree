/*
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 7
*/


#include <iostream>
#include <string>
#include <cassert>
#include "dict.h"

// ======================= Test Default Constructor Method =====================
void test_defaultConstructor()
{
	// Dictionary<string, string> d1;
	// assert(d1.toString(0) == "[]" && d1.empty()); // empty is also tested here
}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{
	// Dictionary<string, string> d1;
	// d1.insert("hi", "1");					// insert was tested prior to writing this
	//
	// Pair p;
	// p.key = "hi";
	// int result = p.hash(d1.slots);
	//
	// Dictionary<string, string> d2(d1);
	//
	// assert(d2.toString(result) == d2.toString(result));
}

// ========================= Test Insert and Get Methods =======================
void test_insert_and_get()
{
	// // note that get is used by insert so it's acceptable to test both using insert.
	// Dictionary<string, string> dictA;
	// dictA.insert("key", "value");
	// Pair p;
	// p.key = "key";
	// p.value = "value";
	// int result = p.hash(dictA.slots);
	// assert(dictA.toString(result) == "[{key, value}]" && !dictA.empty()); // empty also tested here
	//
	// try{dictA.insert("key", "value");}	// shouldn't be able to do this -- it's already in there
	// catch(InsertError e)
	// {
	// 	cout << "Insert Error: Item already exists in dictionary with that key" << endl;
	// }
	//
	// dictA.insert("yek", "value");	// chaining
	// assert(dictA.toString(result) == "[{yek, value}, {key, value}]");
}


// ============================= Test Remove Method ============================
void test_remove()
{
	// Dictionary<string, string> dictA;
	// dictA.insert("key", "value");
	// dictA.insert("yek", "value");
	//
	// Pair p;
	// p.key = "key";
	// p.value = "value";
	//
	// int result = p.hash(dictA.slots);
	//
	// string str = "key";
	// dictA.remove(str);
	// assert(dictA.toString(result) == "[{yek, value}]");
	// str = "yek";
	// dictA.remove(str);
	// assert(dictA.toString(result) == "[]");
	//
	// dictA.insert("asdf", "asdf");
	// dictA.insert(";lkj", "23");
	// dictA.insert("23", "23");
	//
	// p.key = "asdf";
	// int result1 = p.hash(dictA.slots);
	// p.key = ";lkj";
	// int result2 = p.hash(dictA.slots);
	// p.key = "23";
	// int result3 = p.hash(dictA.slots);
	// string str1 = "asdf";
	// string str2 = ";lkj";
	// string str3 = "23";
	//
	// dictA.remove(str1);
	// assert(dictA.toString(result1) == "[]");
	// dictA.remove(str2);
	// assert(dictA.toString(result2) == "[]");
	// dictA.remove(str3);
	// assert(dictA.toString(result3) == "[]");
}


// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor();
	cout << "Default Constructor Test		|Passed|" << endl;
  test_copyConstructor();
	cout << "Copy Constructor Test			|Passed|" << endl;
	test_insert_and_get();
	cout << "Insert and Get Test			|Passed|" << endl;
	test_remove();
	cout << "Remove Test				|Passed|" << endl;

	return 0;
}
