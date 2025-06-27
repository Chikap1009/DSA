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

unordered_map<int,int> mp;

TreeNode* building(vector<int> postorder, int postStart, int postEnd, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;

    TreeNode* root = new TreeNode(postorder[postEnd]);

    int inRoot = mp[root->val];
    int numsLeft = inRoot - inStart;

    root->left = building(postorder, postStart, postStart+numsLeft-1, inStart, inRoot-1);
    root->right = building(postorder, postStart+numsLeft, postEnd-1, inRoot+1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i=0 ; i<inorder.size() ; i++) {
        mp[inorder[i]] = i;
    }

    return building(postorder, 0, postorder.size()-1, 0, inorder.size()-1);
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

    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};

    TreeNode* ans = buildTree(inorder, postorder);

    vector<vector<int>> levelOrderAns = levelOrder(ans);
    for (auto x : levelOrderAns) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}