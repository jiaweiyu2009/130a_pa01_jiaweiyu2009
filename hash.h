#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
class Table {
public:
	Table();
	//~Table();
	void insert(string word);
	void search(string word) const;
	void remove(string word);
	//void rangeSearch(string a, string b) const;

private:
	const static size_t CAPACITY = 10000;
	std::vector<std::pair<std::string,size_t>> table[CAPACITY];
	size_t hash(std::string word) const;

	int insertHelper(string word);
	int searchHelper(string word) const;
};

#endif
