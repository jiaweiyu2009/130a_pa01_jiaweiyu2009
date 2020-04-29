#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <queue>
#include "bst.h"

using namespace std;
int main(int argc, char** argv){
fstream file;
string word, filename;
Table data;
filename = "small.txt";
file.open(filename.c_str());
while (file >>word){

data.insert2(word,false);
}
/*
    string str = "delete yi, search er, insert san";
    queue<string> q;
   
  
    stringstream ss(str); 
  
    while (ss.good()) { 
        string substr; 
        getline(ss, substr, ',');
        q.push(substr); 
    } 

*/

data.insert("sb");


return 0;}
