#ifndef PROG1_H
#define PROG1_H

#include <iostream>
#include <vector>

using namespace std;

class BST {

public:

	BST();
	~BST();
	void search(string word) const;
	void insert2(string word, bool b);
	void insert(string word);
	void remove(string word);
	void print() const;
	void rangeSearch(string a, string b)const;


//	void  rangeSearch(Node* r, string a, string b) const;


private:

	struct Node{
		string word;
		int count;
		Node *left, *right, *parent;

		Node(string w="", int c=0): word(w),count(c),left(0),right(0),parent(0){}

		void printWord(){cout<<this->word;}
		void printCount(){cout<<this->count;}
	};

	Node* root;

	void clear(Node *n); //for destructor

	int insertHelper(string word, Node* n);
	int searchHelper(string word) const;
	Node* getNodeFor(string value, Node* n) const;
	Node* minHelper(Node* n) const;
	Node* maxHelper(Node* n) const;
	Node* getPredecessorNode(string value) const;
	Node* getSuccessorNode(string value) const;
	string getSuccessor(string value) const;
	string getPredecessor(string value) const;
	bool removeHelper(string value);
	void  rangeSearchHelper(Node* r, string a, string b, vector<string>& v) const;

	void printInOrder(Node* n) const;

};
#endif
