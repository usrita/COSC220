all: grocery

grocery: grocery_linkfun.o linked_grocery.o
	g++ grocery_linkfun.o linked_grocery.o -o grocery
grocery_linkfun.o: grocery_linkfun.cpp
	g++ -c grocery_linkfun.cpp
linked_grocery.o: linked_grocery.cpp
	g++ -c linked_grocery.cpp
clean:
	rm -rf *o grocery

