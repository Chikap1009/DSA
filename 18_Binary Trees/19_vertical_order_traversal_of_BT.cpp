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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    queue<pair<TreeNode*,pair<int,int>>> q; // {node, {column, row}}
    map<int,map<int,multiset<int>>> mp;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        mp[x][y].insert(node->val);
        if (node->left) {
            q.push({node->left,{x-1,y+1}});
        }
        if (node->right) {
            q.push({node->right,{x+1,y+1}});
        }
    }

    vector<vector<int>> ans;
    for (auto p : mp) {
        vector<int> col;
        for (auto r : p.second) {
            col.insert(col.end(),r.second.begin(),r.second.end());
        }
        ans.push_back(col);
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

    vector<vector<int>> ans = verticalTraversal(root);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}