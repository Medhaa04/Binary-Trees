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
class Solution{
    public:
    bool isLeaf(Node*root){
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node*root,vector<int>&res){
        Node* curr=root->left;
        while(curr){
        //adding data to result
        if(!isLeaf(curr)){
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
    void addRightBoumdary(Node*root, vector<int>&res){
        vector<int>temp;
        Node*curr=root->right;
        while(curr){
        if(!isLeaf(root)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
        }
        for(int i=temp.size();i>=0;--i){
            res.push_back(temp[i]);
        }

    }

    void addLeaves(Node*root,vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;

        }
        if(root->left){
            addLeaves(root->left,res);
        }
        if(root->right){
            addLeaves(root->right,res);
        }
    }

    vector<int> printBoumdary(Node* root){
        vector<int>res;
        if(root==NULL){
            return res;
        }
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoumdary(root,res);
        return res;


    }
};