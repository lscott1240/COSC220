all: Lab3

Lab3: linkedList.o linkFun.o
	g++ linkedList.o linkFun.o -o Lab3

linkedList.o: linkedList.cpp
	g++ -c linkedList.cpp

linkFun.o: linkFun.cpp
	g++ -c linkFun.cpp

clean:
	rm -rf *o Lab3
