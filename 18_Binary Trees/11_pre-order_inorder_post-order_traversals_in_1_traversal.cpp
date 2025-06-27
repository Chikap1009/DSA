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

vector<vector<int>> allTraversal(TreeNode* root) {
    vector<int> preorder, inorder, postorder;
    stack<pair<TreeNode*,int>> st;
    if (!root) return {};
    st.push({root,1});
    while(!st.empty()) {
        TreeNode* node = st.top().first;
        int num = st.top().second;
        st.pop();

        if (num == 1) {
            preorder.push_back(node->val);
            st.push({node,2});
            if (node->left) st.push({node->left,1});
        }
        else if (num == 2) {
            inorder.push_back(node->val);
            st.push({node,3});
            if (node->right) st.push({node->right,1});
        }
        else {
            postorder.push_back(node->val);
        }
    }
    vector<vector<int>> ans = {preorder,inorder,postorder};
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

    vector<vector<int>> ans = allTraversal(root); // {pre-order, inorder, post-order}

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}