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

void traversal(TreeNode* root, vector<int>& v, int level) {
    if (!root) return;

    if (level == v.size()) v.push_back(root->val);

    traversal(root->right, v, level+1);
    traversal(root->left, v, level+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans, 0);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans = rightSideView(root);

    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}