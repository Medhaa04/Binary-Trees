//recursion after root
//code in basic.cpp
#include<iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;
    node (int d){
        data=d;
        left=right=NULL;
    }
};

node* findNode(node* root, int key) {
	if (!root) {
		return NULL;
	}

	if (root->data == key) {
		return root;
	}
	node* ans = findNode(root->left, key);
	if (ans != NULL) {
		return ans;
	}

	ans = findNode(root->right, key);
	if (ans != NULL) {
		return ans;
	}

	return NULL;
}