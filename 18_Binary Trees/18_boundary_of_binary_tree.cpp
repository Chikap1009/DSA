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
    if (!root->left && !root->right) return true;
    return false;
}

void addLeftBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* temp = root->left;
    while(temp) {
        if (isLeaf(temp)) break;

        ans.push_back(temp->val);
        if (temp->left) temp = temp->left;
        else temp = temp->right;
    }
}

void addRightBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* temp = root->right;
    vector<int> v;
    while(temp) {
        if (isLeaf(temp)) break;

        v.push_back(temp->val);
        if (temp->right) temp = temp->right;
        else temp = temp->left;
    }
    for (int i=v.size()-1 ; i>=0 ; i--) {
        ans.push_back(v[i]);
    }
}

void addLeaves(TreeNode* root, vector<int>& ans) {
    if (isLeaf(root)) ans.push_back(root->val);

    if (root->left) addLeaves(root->left,ans);
    if (root->right) addLeaves(root->right,ans);
}

vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    if (!isLeaf(root)) ans.push_back(root->val);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
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

    vector<int> ans = boundaryOfBinaryTree(root);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}