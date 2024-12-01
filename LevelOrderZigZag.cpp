#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructTree(istringstream& iss) {
    string token;
    iss >> token;

    if (token == "false") {
        return nullptr;
    }

    int value = stoi(token);
    TreeNode* root = new TreeNode(value);
    root->left = constructTree(iss);
    root->right = constructTree(iss);

    return root;
}

void zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    vector<vector<int>> result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            currentLevel.push_back(current->val);

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        if (!leftToRight) {
            reverse(currentLevel.begin(), currentLevel.end());
        }

        result.push_back(currentLevel);
        leftToRight = !leftToRight;
    }

    // Print the zigzag order
    for (const vector<int>& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    getline(cin, input);

    istringstream iss(input);
    TreeNode* root = constructTree(iss);

    cout << "Zigzag Order Traversal: ";
    zigzagLevelOrder(root);

    return 0;
}

