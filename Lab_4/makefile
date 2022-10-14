all: Grocery

Grocery: groceryOrder.o groceryStore.o
	g++ groceryOrder.o groceryStore.o -o Grocery

groceryOrder.o: groceryOrder.cpp
	g++ -c groceryOrder.cpp

groceryStore.o: groceryStore.cpp
	g++ -c groceryStore.cpp

clean:
	rm -rf *o Grocery
