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

void Mirror(node* root){
    //base
    if(!root){
        return;
    }

    //recursive
    swap(root->left,root->right);
    Mirror(root->left);
    Mirror(root->right);
}

//build tree using pre and inorder
int pre[]={8,10,1,6,4,7,3,14,13};
int k=0;
node* buildTree(int *in,int s,int e){
    //base

    //recurisve
    int d=pre[k++];
    node* root=new node(d);
    //
    int i=-1;
    for(int j=s;j<=e;++j){
        if(in[j]==d){
            i=j;
            break;

        }
    }
    root->left=buildTree(in,s,i-1);
    root->right=buildTree(in,i+1,e);
}

int main(){
    // node* root=createTree();
   int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14 };
	int n = sizeof(in) / sizeof(int);
	node* root = buildTree(in, 0, n - 1);
    Mirror(root);
}