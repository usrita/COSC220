all: heap

heap: Lab9.o Heap.o
	g++ -o heap Lab9.o Heap.o

Lab9.o: Lab9.cpp
	g++ -c Lab9.cpp 

Heap.o: Heap.cpp
	g++ -c Heap.cpp

clean: 
	rm -rf *o heap