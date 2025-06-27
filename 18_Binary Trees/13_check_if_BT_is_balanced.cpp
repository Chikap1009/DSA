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

int dfsHeight(TreeNode* root) {
    if (!root) return 0;

    int leftH = dfsHeight(root->left);
    if (leftH == -1) return -1;
    int rightH = dfsHeight(root->right);
    if (rightH == -1) return -1;

    if (abs(leftH-rightH) > 1) return -1;

    return 1+max(leftH,rightH);
}

bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    bool ans = isBalanced(root);

    cout << ans << endl;

    return 0;
}