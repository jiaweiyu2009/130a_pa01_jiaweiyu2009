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
#include "hash.h"

using namespace std;
int FirstSpace(string b, string x){
for(size_t i = 0; i < b.length(); i++) {
    if (b.substr(i, x.length()) == x){
         return i;
}
}
}

int main(int argc, char** argv){
fstream file;
string word, filename;
BST treedata;
Table tabledata;
//filename = "PA1_dataset.txt";
filename = "/autograder/submission/PA1_dataset.txt";
file.open(filename.c_str());
while (file >>word){

treedata.insert2(word,false);
tabledata.insert2(word,false);
}
  
///////////////////////////////////////////////
string str = argv[1];
queue<string>q;

stringstream ss(str);
while (ss.good()){
    string substr;
    getline(ss, substr, ',');
    q.push(substr);
}

while (!q.empty()){
string s = q.front();

//////////////////////////////////////////////////////////
if (s.find("insert") != std::string::npos){
string w = " ";
int indexOfSpace = 0;
for (size_t i = 0; i < s.length(); i++) {
        if (s.substr(i, w.length()) == w) {
            indexOfSpace = i;
        }
}

string key = s.substr(indexOfSpace+1, s.length()-1);
treedata.insert(key);
tabledata.insert(key);
}

////////////////////////////////////////////////////////////
else if (s.find("range") != std::string::npos){
string extracted;
if(s[0] == 32){
    extracted = s.erase(0,14);
    cout << extracted << endl;
}
else if(s[0] == 114){
     extracted = s.erase(0,13);
}


string w = " ";
int indexOfFirstSpace = 0;
int indexOfLastSpace = 0;
for (size_t i = 0; i < extracted.length(); i++) {
        if (extracted.substr(i, w.length()) == w) {
            indexOfLastSpace = i;
        }
}

indexOfFirstSpace = FirstSpace(extracted, w);

string a = extracted.substr(0, indexOfFirstSpace);
string b = extracted.substr(indexOfLastSpace+1, extracted.length());


treedata.rangeSearch(a,b);
tabledata.rangeSearch(a,b);

}

/////////////////////////////////////////////////////////////////////
else if(s.find("delete") != std::string::npos){
string w = " ";
int indexOfSpace = 0;
for (size_t i = 0; i < s.length(); i++) {
        if (s.substr(i, w.length()) == w) {
            indexOfSpace = i;
        }
}
string key = s.substr(indexOfSpace+1, s.length()-1);

tabledata.remove(key);
treedata.remove(key);
}

//////////////////////////////////////////////////////////////////////
else if(s.find("search") != std::string::npos){
string w = " ";
int indexOfSpace = 0;
for (size_t i = 0; i < s.length(); i++) {
        if (s.substr(i, w.length()) == w) {
            indexOfSpace = i;
        }
}
string key = s.substr(indexOfSpace+1, s.length()-1);

treedata.search(key);
tabledata.search(key);
}

////////////////////////////////////////////////////////////////////////

q.pop();



}


return 0;
}


