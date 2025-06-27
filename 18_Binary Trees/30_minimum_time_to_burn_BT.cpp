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

TreeNode* markParents(TreeNode* root, int target, unordered_map<TreeNode*, TreeNode*>& trackParents) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* toFind;
    while(!q.empty()) {
        TreeNode* node = q.front();
        if (node->val == target) toFind = node;
        q.pop();
        if (node->left) {
            trackParents[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            trackParents[node->right] = node;
            q.push(node->right);
        }
    }
    return toFind;
}

int minTime(TreeNode* root, int target) {
    if (!root) return 0;
    unordered_map<TreeNode*, TreeNode*> trackParents;
    TreeNode* targetNode = markParents(root, target, trackParents);
    queue<TreeNode*> q;
    q.push(targetNode);
    unordered_map<TreeNode*, bool> visited;
    visited[targetNode] = true;
    int maxTime = 0;
    while(!q.empty()) {
        int s = q.size();
        int flag = 0;
        for (int i=0 ; i<s ; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left && !visited[node->left]) {
                flag = 1;
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right]) {
                flag = 1;
                q.push(node->right);
                visited[node->right] = true;
            }
            if (trackParents[node] && !visited[trackParents[node]]) {
                flag = 1;
                q.push(trackParents[node]);
                visited[trackParents[node]] = true;
            }
        }
        if (flag) maxTime++;
    }
    return maxTime;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int ans = minTime(root, root->left->val);

    cout << ans << endl;

    return 0;
}