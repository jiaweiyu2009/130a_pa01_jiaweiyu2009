
all: runEverything

runEverything: main.cpp bst.cpp hash.cpp
	g++ -std=c++11 -o prog1 main.cpp bst.cpp hash.cpp

