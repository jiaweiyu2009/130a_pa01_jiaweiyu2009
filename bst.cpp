#include "bst.h"

#include <iostream>
#include <vector>
#include <string>
using std::cout;

// constructor sets up empty tree
BST::BST() : root(0) { }

// destructor deletes all nodes
BST::~BST() {
    clear(root);
    this->root = nullptr;
}

// recursive helper for destructor
void BST::clear(Node *n) {
    if (n) {
	   clear(n->left);
	   clear(n->right);
	   delete n;
    }
}


void BST::print() const {
	printInOrder(root);
}

void BST::printInOrder(Node *n) const {
	if (n){
    printInOrder(n->left);
    cout << n->word << "\n";
    printInOrder(n->right);
}
}


void BST::insert(string word){
	int c;
	if(!root){
		root = new Node(word,1);
		cout << word << " inserted, new count = 1\n";
	}
	else{
		c = insertHelper(word,root);
		cout << word << " inserted, new count = " << c << "\n";
	}
}


int BST::insertHelper(string word, Node *n) {
    if (word == n->word){
	   n->count += 1;
	   return n-> count;
    }
    		
    if (word < n->word) {
	    if (n->left)
	       return insertHelper(word, n->left);
	    else {
	        n->left = new Node(word, 1);
	        n->left->parent = n;
	        return 1;
	    }
    }
    else {
	    if (n->right)
	       return insertHelper(word, n->right);
	    else {
	       n->right = new Node(word, 1);
	       n->right->parent = n;
	       return 1;
	    }
    }
}

void BST::search(string word) const{
int s = searchHelper(word, root);
if(s>0){
	cout << word << " found, count = " << s << "\n";
}
else{
	cout << word << " not found\n";
}
}

int BST::searchHelper(string word, Node* n) const{
	while(root!= NULL){
		if(word > n->word){
			n = n->right;
		}
		else if(word < n->word){
			n = n->left;
		}
		else{
			return n->count;
		}
	}
	return 0;
}



BST::Node* BST::getNodeFor(string value, Node* n) const{
	if (!n){
		return nullptr;
	}
	else{
	    if(value == n->word){
		return n;
	    }
	    if(value < n->word){
		return getNodeFor(value,n->left);
	    }
	    else{
		return getNodeFor(value,n->right);
	    }
}
}



BST::Node* BST::getPredecessorNode(string value) const{

   Node* n = getNodeFor(value,root);

   if (n->left){
	   return maxHelper(n->left);
   }
   else{
	   if (n->parent == nullptr){
		   return nullptr;
	   }
	   if (n->parent->right == n){
		   return n->parent;
	   }
	   else{
	   Node* p = n->parent;
	 while(p && p->parent){
		 if(p->parent->word < value){
			 return p -> parent;
		 }
		 p = p -> parent;
   }
	 return nullptr;
}
}
}

string BST::getPredecessor(string value) const{
	Node* p = getPredecessorNode(value);
    if (p){
	    return p->word;
    }
    else{
	    return 0;
    }
}

BST::Node* BST::maxHelper(Node* n) const{
	Node* temp = n;
	while(temp && temp->right){
		temp = temp->right;
	}
	return temp;
}


BST::Node* BST::getSuccessorNode(string value) const{

    Node* n = getNodeFor(value,root);
    if (n->right){
	    return minHelper(n->right);
    }
    else{
	    if(n->parent == nullptr){
		    return nullptr;
	    }
	    if(n->parent->left == n){
		    return n->parent;
	    }
	    else{
		    Node* p = n->parent;
		    while(p && p->parent){
			    if (p->parent->word > value){
				    return p->parent;
			    }
			p = p->parent;
		   }
	return nullptr;

    }

}
}




string BST::getSuccessor(string value) const{
    Node* temp = getSuccessorNode(value);
    if (!temp){
	    return 0;
    }
    return temp->word;
}

BST::Node* BST::minHelper(Node *n) const{
	while(n && n->left){
		n = n->left;
	}
	return n;
}


bool BST::removeHelper(string value){

Node* t = getNodeFor(value,root);

if(t){
	if(!t->right && !t->left){
		if(t->parent == nullptr){
			delete t;
			root = NULL;

		}
		else if(t->parent->left == t){
			t->parent->left = NULL;
			delete t;
		}
		else{
			t->parent->right = NULL;
			delete t;
		}
		return t;
	}

	else if((!t->right && t->left) || (!t->left && t->right)){
		if(!t->right && t->left){
			if(t->parent->left == t){
				t->parent->left = t->left;
				delete t;
			}
			else{
				t->parent->right = t->left;
				delete t;
			}
			return t;
		}
		else{
			if(t->parent->left == t){
				t->parent->left = t->right;
				delete t;
			}
			else{
				t->parent->right = t->right;
				delete t;
			}
		}

	}

	else{
		Node* suc = getSuccessorNode(value);
		if(!suc){
			delete t;
			root = NULL;
		}
		if(suc->parent->word == value){
			suc->right = t->right->right;
		}
		else{
			Node *tmp = suc->right;
			if(suc->right){
				suc->right->parent = suc->parent;
			}
			suc->right = t->right;
			suc->parent->left = tmp;
		}
		suc->left = t->left;
		suc->parent = t->parent;
		if(suc->parent && suc->word < suc->parent->word){
			suc->parent->left = suc;
		}
		if(suc->right){
			suc->right->parent = suc;
		}
		if(suc->left){
			suc->left->parent = suc;
		}
		if(!suc->parent){
			root = suc;
		}
		delete t;
	}

	return true;
}
else{
	return false;
}



}

void BST::remove(string word){
   int h = searchHelper(word,root);

   if(h==1){
	   bool r = removeHelper(word);
	   if(r){
		   cout << word << " deleted\n";
	   }
	   else{
		   return;
	   }
   }
   else{
	   h = h-1;
	   cout << word << " deleted, new count = " << h << "\n";
   }
}






vector<string> BST::rangeSearchHelper(Node* n, string a, string b) const{
	vector<string> v1;
	Node* r = root;
	if(a < root->word){
		rangeSearchHelper(root->left,a,b);
	}
	if(a < root->word && b > root->word){
		v1.push_back(root->word);
	}
	if(b > root->word){
		rangeSearchHelper(root->right,a,b);
	}

return v1;
}


void BST::rangeSearch(string a, string b) const{
	vector<string> s = rangeSearchHelper(root,a,b);
	for (vector<string>::iterator it = s.begin(); it!=s.end(); it++){
		cout << *it << endl;
	}
}
	  


