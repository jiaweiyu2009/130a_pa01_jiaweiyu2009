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
	acc = acc* word.size() / 33;
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

int Table::searchHelper(string word) const{
	bool found = false;

	for (size_t i = 0; i < CAPACITY; i++){
		for (pair<string,size_t> i : table[i])
			if (i.first == word){
			found = true;
			return i.second;
		}
	}
	

	if (found == false){
		return 0;
	}
}

void Table::search(string word) const{
	int i = searchHelper(word);
	if (i==0){
		cout << word << " not found" << endl;
	}
	else{
		cout << word << "found, count = "<< i << endl;
	}
}

void Table::remove(string word){
	int s = searchHelper(word);
	if(s == 1){
	for (size_t i = 0; i < CAPACITY; i++){
		for(pair<string,size_t> i : table[i]){
			if(i.first == word){
				int index;
				vector<pair<string,size_t>>::iterator it;
				pair<string,size_t> p1 (i.first,1);
				it = find(table[i].begin,table[i].end(),p1);
				index = distance(table[i].begin(),it);
				table[i].erase(table[i].begin() + index);
				cout << word << " deleted\n";
			}
		}
	}
	}
	else{
	for(size_t i = 0; i < CAPACITY; i++){
		for(pair<string,size_t>i : table[i]){
			if(i.first == word){
				i.second = i.second -1;
				cout << word << " deleted, new count = " << i.second <<endl;
			}

		}
	}
	}
}

/*
void Table::rangeSearch(string a, string b)const{
	size_t begin = hash(a);
	size_t end = hash(b);

	for(size_t i = begin; i <= end ; i++){
		for(pair<string,size_t> i : table[i]){
			cout << i.first << endl;
		}
	}
}

*/


