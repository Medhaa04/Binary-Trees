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

int HeightOfTree(node*root){
    //base
    if(!root){
        return 0;
    }

    //recursive
    return max(HeightOfTree(root->left),HeightOfTree(root->right))+1;
}

node* createTree(){              //node* because we return adress of root hence we need pointer 
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    node* root=new node(data);
    root->left=createTree();
    root->right=createTree();
    return root;
}

int main(){
    node* root=createTree();
    // root=NULL;
   cout<<"Height of tree is: "<<HeightOfTree(root);
   return 0;


}