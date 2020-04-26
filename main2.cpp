#include <iostream>
#include "hash.h"

using namespace std;

int main(int argc, char** argv){

ifstream txtfile(argv[1]);
string line;


if (txtfile.fail()){
	cerr << "Cound not open file" << argv[1];
	exit(1);
}

Table hashtable;

while(getline(txtfile,line)){
	hashtable.insert(line);
}
}

