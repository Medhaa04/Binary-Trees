#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& indexMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }

    int rootValue = preorder[preStart];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndexInorder = indexMap[rootValue];
    int numLeft = rootIndexInorder - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numLeft, inorder, inStart, rootIndexInorder - 1, indexMap);
    root->right = buildTreeHelper(preorder, preStart + numLeft + 1, preEnd, inorder, rootIndexInorder + 1, inEnd, indexMap);

    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> indexMap;

    // Create a map to store the indices of elements in the inorder array
    for (int i = 0; i < inorder.size(); ++i) {
        indexMap[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, indexMap);
}

void modifiedPreorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << (root->left ? to_string(root->left->val) : "END") << " ";
    cout << root->val << " ";
    cout << (root->right ? to_string(root->right->val) : "END") << endl;

    modifiedPreorder(root->left);
    modifiedPreorder(root->right);
}

void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    cout << endl;
}

int main() {
    int n, m;

    
    cin >> n;

    vector<int> preorder(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    
    cin >> m;

    vector<int> inorder(m);
    
    for (int i = 0; i < m; ++i) {
        cin >> inorder[i];
    }

    TreeNode* root = buildTree(preorder, inorder);
    modifiedPreorder(root);

    return 0;
}
