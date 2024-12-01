#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class solution{
    public:
    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL) return true;

    }
    void addLeftBoumdary(Node*root,vector<int>&res){
        Node*curr=root->left;
        while(curr){
        if(isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
        }

    }
    void addRightBoundary(Node* root,vector<int>&res){
        vector<int>temp;
        Node* curr=root->right;
        while(curr){
        if(isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }

        for(int i=temp.size()-1;i>=0;--i){
            res.push_back(temp[i]);
        }
        }

    }
    void addLeafNodes(Node*root,vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->data);
        }
        if(root->left){
            addLeafNodes(root->left,res);
        }
        if(root->right){
            addLeafNodes(root->right,res);
        }


    }
    vector<int> PrintBoundaryTraversal(Node* root){
        vector<int>res;
        if(root=NULL){
            return res;
        }
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        addLeftBoumdary(root,res);
        addLeafNodes(root,res);
        addRightBoundary(root,res);
        return res;



    }
};