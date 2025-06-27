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

bool check(TreeNode* root) {
    if (!root) return true;
    if (root->left && root->right) {
        if (root->val == root->left->val + root->right->val) return true;
        else return false;
    }
    else if (root->left) {
        if (root->val == root->left->val) return true;
        else return false;
    }
    else if (root->right) {
        if (root->val == root->right->val) return true;
        else return false;
    }
    return true;
}

int isSumProperty(TreeNode *root)
{
    if (!root) return 1;
    
    if (check(root) && isSumProperty(root->left) && isSumProperty(root->right)) return 1;
    return 0;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int ans = isSumProperty(root);

    cout << ans << endl;

    return 0;
}