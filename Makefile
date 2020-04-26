
all: runBST

runBST: main.cpp bst.cpp
	g++ -std=c++11 -o prog1 main.cpp bst.cpp
