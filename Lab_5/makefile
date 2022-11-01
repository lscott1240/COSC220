all: Lab5

Lab5: LinkedList.o Node.o Lab5.o
	g++ LinkedList.o Node.o Lab5.o -o Lab5

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

Lab5.o: Lab5.cpp
	g++ -c Lab5.cpp

clean:
	rm -rf *o Lab5
