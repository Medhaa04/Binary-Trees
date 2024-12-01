// Given a Binary Tree, The task is to connect all the adjacent nodes at the same level starting from the left-most node of that level, and ending at the right-most node using nextRight pointer by setting these pointers to point the next right for each node. 
#include<bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;
    node* nextRight;
 
    /* Constructor that allocates a new node with the
    given data and NULL left and right pointers. */
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->nextRight = NULL;
    }
};
void connect(node*root){
    if(root==nullptr){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        node* prev=NULL;
        while(size--){
            node* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(prev!=NULL){
                prev->nextRight=temp;
                prev=temp;
            }

        }
        prev->nextRight=NULL;
    }
}