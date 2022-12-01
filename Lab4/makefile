all: List

List: LinkedList.o Node.o Lab4.o
	g++ -o List LinkedList.o Node.o Lab4.o
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
Node.o: Node.cpp
	g++ -c Node.cpp
Lab4.o: Lab4.cpp
	g++ -c Lab4.cpp
clean: 
	rm -rf *o List
