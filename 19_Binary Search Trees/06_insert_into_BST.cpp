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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    TreeNode* curr = root;

    while(curr) {
        if (curr->val > val) {
            if(!curr->left) {
                curr->left = new TreeNode(val);
                break;
            }
            else curr = curr->left;
        }
        else {
            if (!curr->right) {
                curr->right = new TreeNode(val);
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

    TreeNode* ansRoot = insertIntoBST(root, 8);

    inorder(ansRoot);
    cout << endl;

    return 0;
}