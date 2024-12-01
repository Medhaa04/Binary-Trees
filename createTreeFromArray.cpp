#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
void createNode(Node* created[], Node**root,int parent[],int i){
    if(created[i]!=NULL){             //if node already created
        return;
    }
    created[i]=newNode(i);               //create new nnode

    if(parent[i]==-1){             //if parent -1 then root
        *root=created[i];
        return;
    }
    if(created[parent[i]]==NULL){
        createNode(created,root,parent,parent[i]);            //create parent recursive
    }
    Node* p=created[i];
    if(p->left==NULL){                               //inssert left or right child
        p->left=created[i];
    }
    else{
        p->right=created[i];
    }
}
Node* createTree(int parent[],int n){
     Node *created[n];
    for (int i=0; i<n; i++)
        created[i] = NULL;

    Node *root = NULL;
    for (int i=0; i<n; i++)
        createNode(created,&root,parent, i);
        return root;

}