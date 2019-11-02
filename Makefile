
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_dict test_rbtree imdb3

//==============================================================================

test_dict.o: test_dict.cpp dict.h dict.cpp
	g++ $(CPPOPTIONSS) -c test_dict.cpp

test_dict: test_dict.o
	g++ -o test_dict test_dict.o

test_rbtree.o: test_rbtree.cpp rbtree.h rbtree.cpp
	g++ $(CPPOPTIONSS) -c test_rbtree.cpp

test_rbtree: test_rbtree.o
	g++ -o test_rbtree test_rbtree.o

imdb3.o: imdb3.cpp rbtree.h rbtree.cpp
	g++ $(CPPOPTIONSS) -c imdb3.cpp

imdb3: imdb3.o
	g++ -o imdb3 imdb3.o

//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
