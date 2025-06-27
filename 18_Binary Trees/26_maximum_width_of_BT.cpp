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

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int maxWidth = 0;
    queue<pair<TreeNode*,long long>> q;
    q.push({root,0});
    while(!q.empty()) {
        int s = q.size();
        long long mini = q.front().second;
        int first, last;
        for (int i=0 ; i<s ; i++) {
            TreeNode* node = q.front().first;
            long long currIndex = q.front().second - mini;
            q.pop();
            if (i==0) first = currIndex;
            if (i==s-1) last = currIndex;
            if (node->left) q.push({node->left, currIndex*2 + 1});
            if (node->right) q.push({node->right, currIndex*2 + 2});
        }
        maxWidth = max(maxWidth, last-first+1);
    }
    return maxWidth;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int ans = widthOfBinaryTree(root);

    cout << ans << endl;

    return 0;
}