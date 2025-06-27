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

void convertTree(TreeNode *root)
{
    if (!root) return;

    int child = 0;
    if (root->left) child += root->left->val;
    if (root->right) child += root->right->val;

    if (child >= root->val) {
        root->val = child;
    }
    else {
        if (root->left) root->left->val = root->val;
        else if (root->right) root->right->val = root->val;
    }

    convertTree(root->left);
    convertTree(root->right);

    int total = 0;
    if (root->left) total += root->left->val;
    if (root->right) total += root->right->val;
    if (root->left || root->right) {
        root->val = total;
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i=0 ; i<size ; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
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

    convertTree(root);

    vector<vector<int>> ans = levelOrder(root);
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}