#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
int pre[] = {8 , 10, 1, 6, 4, 7, 3 , 14, 13 };
int k = 0;
node* buildTree(int *in, int s, int e) {
	// base case
	if (s > e) {
		return NULL;
	}
	// recursive case
	int d = pre[k++];
	node* root = new node(d);

	// find index i in inorder
	int i;
	for (int j = s; j <= e ; ++j)
	{
		if (in[j] == d) {
			i = j;
			break;
		}
	}

	root->left = buildTree(in, s, i - 1);
	root->right =  buildTree(in, i + 1, e);
	return root;
}
int main() {

	// node* root = createTree();
	int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14 };
	int n = sizeof(in) / sizeof(int);
	node* root = buildTree(in, 0, n - 1);
}