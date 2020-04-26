#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>

#include "bst.h"

using namespace std;
int main(int argc, char** argv){

ifstream txtfile(argv[1]);
string line;


if (txtfile.fail()){
	cerr << "Cound not open file" << argv[1];
	exit(1);
}

BST data;

while(getline(txtfile,line)){
	data.insert(line);
}
data.print();
//data.rangeSearch("dev", "camphol");
}
