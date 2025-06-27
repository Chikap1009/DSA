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

int floor(TreeNode* root, int x) {
    TreeNode* curr = root;
    int ans = -1;
    
    while(curr) {
        if (curr->val == x) return x;
        
        if (curr->val > x) {
            curr = curr->left;
        }
        else {
            ans = curr->val;
            curr = curr->right;
        }
    }
    
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << floor(root,8) << endl;

    return 0;
}