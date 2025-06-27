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

int calcDiameter(TreeNode* root, int& maxi) {
    if (!root) return 0;

    int lh = calcDiameter(root->left,maxi);
    int rh = calcDiameter(root->right,maxi);

    maxi = max(maxi, lh+rh);

    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxi = 0;
    calcDiameter(root, maxi);
    return maxi;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int ans = diameterOfBinaryTree(root);

    cout << ans << endl;

    return 0;
}