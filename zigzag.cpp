#include<iostream>
#include<queue>
#include<vector>
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
vector<int> zigzag(node* root){
    vector<int>result;
    if(root==NULL){
        return result;
    }
    queue<node*>q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>ans(size);
        for(int i=0;i<size;++i){
            node* frontNode=q.front();
            q.pop();
            int index=lefttoright?i:size-i-1;
            ans[index]=frontNode->data;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }

        }
        lefttoright=!lefttoright;
        for(auto i:ans){
            result.push_back(i);
        }


    }
    return result;
}