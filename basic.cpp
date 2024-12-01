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

void PreOrder(node* root){
    //base case
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Inorder(node*root){
    if(!root){
    return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void postOrder(node*root){
    if(!root){
    return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

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
    PreOrder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    postOrder(root);

    // node*ans=FindNode(root,6);
    // if(ans!=NULL){
    //     cout<<ans->data;
    // }
    // else{
    //     cout<<"Not present";
    // }
}