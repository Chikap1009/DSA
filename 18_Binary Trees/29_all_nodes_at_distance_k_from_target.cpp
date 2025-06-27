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

void getParentPointers(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) {
            q.push(node->left);
            parentTrack[node->left] = node;
        }
        if (node->right) {
            q.push(node->right);
            parentTrack[node->right] = node;
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    if (!root) return ans;
    unordered_map<TreeNode*, TreeNode*> parentTrack;
    getParentPointers(root, parentTrack);
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int currDist = 0;
    while(!q.empty()) {
        if (currDist == k) break;
        currDist++;

        int s = q.size();
        for (int i=0 ; i<s ; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parentTrack[node] && !visited[parentTrack[node]]) {
                q.push(parentTrack[node]);
                visited[parentTrack[node]] = true;
            }
        }
    }

    while(!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
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

    vector<int> ans = distanceK(root, root->left, 1);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}