all: BST

BST: Lab7.o BST.o TNode.o
	g++ -o BST  Lab7.o TNode.o BST.o

Lab7.o: Lab7.cpp
	g++ -c Lab7.cpp

BST.o: BST.cpp
	g++ -c BST.cpp

TNode.o: TNode.cpp
	g++ -c TNode.cpp

clean: 
	rm -rf *o BST