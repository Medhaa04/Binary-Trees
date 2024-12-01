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

class Pair{                             //when we have to return multiple things in function make pair class
    public:
    int height;
    int diameter;
};

Pair FastDiameter(node* root){
    //base
    if(!root){
        Pair p;
        p.height=p.diameter=0;
        return p;
    }

    //recursive
    Pair left=FastDiameter(root->left);
    Pair right =FastDiameter(root->right);
    Pair p;
    p.height=1+ max(left.height,right.height);
    int op1=left.height+right.height;
    int op2=left.diameter;
    int op3=right.diameter;
    p.diameter=max(op1,max(op2,op3));
    return p;

}

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

int Diamter(node* root){
    if(!root){
        return 0;
    }

    int op1=HeightOfTree(root->left)+HeightOfTree(root->right);
    int op2=Diamter(root->left);
    int op3=Diamter(root->right);
    return max(op1,max(op2,op3));

}
pair<int,int> diameterFast(node* root){
    //base

    //recur
    pair<int,int>left =diameterFast(root->left);
    pair<int,int>right =diameterFast(root->right);

    int op1=left.second+right.second+1;
    int op2=left.first;
    int op3=right.first;
    pair<int,int>ans;
    ans.first=(max(op1,max(op2,op3)));
    ans.second=max(left.second,right.second)+1;
    return ans;
}




int main(){
    node* root=createTree();
    cout<<"Diamter of tree is: "<<Diamter(root);
    Pair ans=FastDiameter(root);
    cout<<"Fast height: "<<ans.height<<endl;
    cout<<"Fast diameter: "<<ans.diameter<<endl;
return 0;
}
/*class Solution {
    private:
    int height(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);   //max diameter forund

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
        
    }
};
*/