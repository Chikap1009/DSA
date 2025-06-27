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

TreeNode* build(vector<int>& preorder, int& i, int bound) {
    if (i==preorder.size() || preorder[i] > bound) return nullptr;

    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return build(preorder, i, INT_MAX);
}

// TreeNode* bstFromPreorder(vector<int>& preorder) {
//     if (preorder.empty()) return nullptr;
//     stack<TreeNode*> st;
//     TreeNode* root = new TreeNode(preorder[0]);
//     st.push(root);
//     for(int i=1 ; i<preorder.size() ; i++) {
//         TreeNode* node = st.top();
//         if (preorder[i] < node->val) {
//             node->left = new TreeNode(preorder[i]);
//             st.push(node->left);
//         }
//         else {
//             while(!st.empty() && st.top()->val < preorder[i]) {
//                 node = st.top();
//                 st.pop();
//             }
//             node->right = new TreeNode(preorder[i]);
//             st.push(node->right);
//         }
//     }
//     return root;
// }

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    vector<int> preorder = {4, 2, 1, 3, 6, 5, 7};
    TreeNode* bstRoot = bstFromPreorder(preorder);

    inorder(bstRoot);

    return 0;
}