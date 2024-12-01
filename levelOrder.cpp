#include<iostream>
#include<queue>
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

void levelOrder(node* root){
    if(!root){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);   //seperator
    while(!q.empty()){
        node* n=q.front();
        q.pop();

        if(n !=NULL){
            cout<<n->data<<" ";
            if(n->left){   //n->left!=NULL
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

}

void LevelOrder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);       //level0 complete

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){    //if null is encountered i.e.level is completely traversed
            cout<<endl;
            if(!q.empty()){     //if we encounter any nodes i.e child nodes therefore push null
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}

int main(){
    node* root=createTree();
    cout<<"Level Order :"<<endl;
    LevelOrder(root);

    
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1