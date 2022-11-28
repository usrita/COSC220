all: List

List : Linkedlist.o LinkFun.o
	g++ Linkedlist.o LinkFun.o -o List

Linkedlist.o: Linkedlist.cpp
	g++ -c Linkedlist.cpp

LinkFun.o: LinkFun.cpp
	g++ -c LinkFun.cpp

clean:
	rm -rf *o List


