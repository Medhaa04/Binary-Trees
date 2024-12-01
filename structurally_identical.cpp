#include <iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool areStructurallyIdentical(TreeNode* root1, TreeNode* root2) {
    // If both trees are empty, they are structurally identical
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // If one tree is empty and the other is not, they are not structurally identical
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Recursively check the left and right subtrees
    bool leftIdentical = areStructurallyIdentical(root1->left, root2->left);
    bool rightIdentical = areStructurallyIdentical(root1->right, root2->right);

    // The trees are structurally identical only if both left and right subtrees are identical
    return leftIdentical && rightIdentical;
}

void serialize(TreeNode* root, vector<string>& result) {
    if (root == NULL) {
        result.push_back("false");
        return;
    }

    result.push_back("true");
    result.push_back(to_string(root->val));
    serialize(root->left, result);
    serialize(root->right, result);
}

int main() {
     TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);


    vector<string> serializedTree;
    serialize(root1, serializedTree);
    vector<string> serializedTree;
    serialize(root2, serializedTree);

    // Check if the trees are structurally identical
    if (areStructurallyIdentical(root1, root2)) {
        std::cout << "The trees are structurally identical." << std::endl;
    } else {
        std::cout << "The trees are not structurally identical." << std::endl;
    }

    return 0;
}
