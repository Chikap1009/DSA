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

vector <int> bottomView(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;
    queue<pair<TreeNode*, int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()) {
        TreeNode* node = q.front().first;
        int col = q.front().second;
        q.pop();
        mp[col] = node->val;
        if (node->left) q.push({node->left,col-1});
        if (node->right) q.push({node->right,col+1});
    }
    for (auto x : mp) {
        ans.push_back(x.second);
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

    vector<int> ans = bottomView(root);

    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}