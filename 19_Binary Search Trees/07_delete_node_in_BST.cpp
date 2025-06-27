#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* getLeftMax(TreeNode* root) {
    TreeNode* temp = root;
    while(temp->right) {
        temp = temp->right;
    }
    return temp;
}

TreeNode* helper(TreeNode* root) {
    if (!root->left) return root->right;
    else if (!root->right) return root->left;

    TreeNode* rightChild = root->right;
    TreeNode* leftMax = getLeftMax(root->left);
    leftMax->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (root->val == key) return helper(root);

    TreeNode* curr = root;
    while(curr) {
        if (curr->val > key) {
            if (curr->left && curr->left->val == key) {
                curr->left = helper(curr->left);
                break;
            }
            else curr = curr->left;
        }
        else {
            if (curr->right && curr->right->val == key) {
                curr->right = helper(curr->right);
                break;
            }
            else curr = curr->right;
        }
    }

    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    TreeNode* ansRoot = deleteNode(root, 5);

    inorder(ansRoot);
    cout << endl;

    return 0;
}