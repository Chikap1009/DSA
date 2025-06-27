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

bool isLeaf(TreeNode* root) {
    return (!root->left && !root->right);
}

void allPaths(TreeNode* root,vector<int>& path, vector<vector<int>>& ans) {
    if (!root) return;
    
    if (isLeaf(root)) {
        path.push_back(root->val);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    
    path.push_back(root->val);
    allPaths(root->left, path, ans);
    allPaths(root->right, path, ans);
    path.pop_back();
}

vector<vector<int>> Paths(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> path;
    allPaths(root,path,ans);
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

    vector<vector<int>> ans = Paths(root);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}