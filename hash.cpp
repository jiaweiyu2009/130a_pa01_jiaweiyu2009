#include "hash.h"
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

// Default constructor
Table::Table() {}

// Simple hash function. Do not modify.
size_t Table::hash(std::string word) const {
	size_t acc;
	for (size_t i = 0; i < word.size(); i++) {
		acc += int(word[i]);
	}
	acc = acc* word.size() * word.size() * acc;
	return acc % CAPACITY;
}

int Table::insertHelper(string word){
	int index = this->hash(word);
	int j = 0;
	for(auto i : table[index]){
		if (i.first == word){
			pair<string, size_t> pair1(i.first,i.second + 1);
			table[index].erase(table[index].begin() + j);
			table[index].push_back(pair1);
			return pair1.second;
		}
		j++;
	}
	pair<std::string, size_t> pair2(word,1);
	table[index].push_back(pair2);
	return 1;
}

	
	
void Table::insert(string word){
	int i = insertHelper(word);
	cout<< word << " inserted, new count = " << i <<endl;
}

void Table::insert2(string word, bool b){
	if( b == false){

	int i = insertHelper(word);
	}
}

int Table::searchHelper(string word) const{	
       int index = this->hash(word);
       for(auto i : table[index]){
		if(i.first == word){
		return i.second;
		}	
       }		
      return 0;

}

void Table::search(string word) const{
	int i = searchHelper(word);
	if (i==0){
		cout << word << " not found" << endl;
	}
	else{
		cout << word << " found, count = "<< i << endl;
	}
}

void Table::remove(string word){
	int s = searchHelper(word);
	pair<string,size_t>pair8;


	if(s == 1){
	int index = this->hash(word);
	for(auto i : table[index]){
		if(i.first == word){
			pair8.first = i.first;
			pair8.second = i.second;
		}
	}

	for (int sh = 0; sh < table[index].size(); sh++){
		if((table[index])[sh] == pair8){
			table[index].erase((table[index]).begin()+ sh);
			cout << word << " deleted\n";
	}
	}
	}

	else{
	int index = this->hash(word);
	for(auto i : table[index]){
		if(i.first == word){
			pair8.first = i.first;
			pair8.second = i.second;
		}
	}
	for(int sh = 0; sh < table[index].size(); sh++){
		if (((table[index])[sh]) == pair8){
			((table[index])[sh]).second -= 1;
			cout << word << " deleted, new count = " << ((table[index])[0].second) << endl;
}
}
}
}


void Table::rangeSearch(string a, string b)const{
	vector<string> v;
	
       int j = 0;
      for(int index = 0 ; index < CAPACITY; index++){
       for(auto i : table[index]){
		if((i.first >= a) && (i.first<= b) && searchHelper(i.first) > 0) {
		v.push_back(i.first);
		}	
       }		
      }

      std::sort(v.begin(),v.end(),myobject);

      for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
	      cout << *it << endl;
      }
}

