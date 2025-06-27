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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* temp = root;
    TreeNode* successor = nullptr;
    while(temp) {
        if (temp->val > p->val) {
            successor = temp;
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return successor;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    TreeNode* node = inorderSuccessor(root, root->right->left);

    cout << node->val << endl;

    return 0;
}