#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    // Search for a particular node
    TreeNode* search(int key) {
        return searchRecursive(root, key);
    }

    // Insert a new node
    void insert(int key) {
        root = insertRecursive(root, key);
    }

    // Delete a particular node
    void deleteNode(int key) {
        root = deleteRecursive(root, key);
    }

    // Utility function to find the node with the minimum key
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Perform inorder traversal (used for testing)
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }

private:
    // Recursive function to search for a particular node
    TreeNode* searchRecursive(TreeNode* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return searchRecursive(node->left, key);
        }

        return searchRecursive(node->right, key);
    }

    // Recursive function to insert a new node
    TreeNode* insertRecursive(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->key) {
            node->left = insertRecursive(node->left, key);
        } else if (key > node->key) {
            node->right = insertRecursive(node->right, key);
        }

        return node;
    }

    // Recursive function to delete a particular node
    TreeNode* deleteRecursive(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        switch (compareKeys(root->key, key)) {
            case -1:  // key is smaller
                root->left = deleteRecursive(root->left, key);
                break;
            case 1:   // key is greater
                root->right = deleteRecursive(root->right, key);
                break;
            default:  // keys are equal (found the node to delete)
                switch (countChildren(root)) {
                    case 0:  // No children
                        delete root;
                        return nullptr;
                    case 1:  // One child
                        if (root->left != nullptr) {
                            TreeNode* temp = root->left;
                            delete root;
                            return temp;
                        } else {
                            TreeNode* temp = root->right;
                            delete root;
                            return temp;
                        }
                    case 2:  // Two children
                        TreeNode* temp = findMin(root->right);
                        root->key = temp->key;
                        root->right = deleteRecursive(root->right, temp->key);
                        break;
                }
        }

        return root;
    }

    // Compare two keys and return -1 if key1 < key2, 0 if key1 == key2, and 1 if key1 > key2
    int compareKeys(int key1, int key2) {
        if (key1 < key2) {
            return -1;
        } else if (key1 > key2) {
            return 1;
        } else {
            return 0;
        }
    }

    // Count the number of children of a node
    int countChildren(TreeNode* node) {
        int count = 0;
        if (node->left != nullptr) {
            count++;
        }
        if (node->right != nullptr) {
            count++;
        }
        return count;
    }
};

int main() {
    BinarySearchTree bst;

    while (true) {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "1. Search for a node" << endl;
        cout << "2. Insert a new node" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Display Inorder Traversal" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        int key;
        switch (choice) {
            case 1:
                cout << "Enter the key to search: ";
                cin >> key;
                if (bst.search(key) != nullptr) {
                    cout << "Node with key " << key << " found in the tree." << endl;
                } else {
                    cout << "Node with key " << key << " not found in the tree." << endl;
                }
                break;
            case 2:
                cout << "Enter the key to insert: ";
                cin >> key;
                bst.insert(key);
                cout << "Node with key " << key << " inserted into the tree." << endl;
                break;
            case 3:
                cout << "Enter the key to delete: ";
                cin >> key;
                bst.deleteNode(key);
                cout << "Node with key " << key << " deleted from the tree." << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                bst.inorderTraversal(bst.root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
