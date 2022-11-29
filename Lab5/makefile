all: run

run: Lab5.o Student.o Stack.o 
	g++ Lab5.o Student.o Stack.o  -o run

Lab5.o: Lab5.cpp
	g++ -c Lab5.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

Stack.o: Stack.cpp
	g++ -c Stack.cpp

clean:
	rm -rf *o run

