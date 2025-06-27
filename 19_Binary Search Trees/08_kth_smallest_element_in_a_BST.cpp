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

int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    int count = 0;
    TreeNode* curr = root;
    while(curr) {
        if (!curr->left) {
            count++;
            if (count == k) {
                ans = curr->val;
            }
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if (!prev->right) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                count++;
                if (count == k) {
                    ans = curr->val;
                }
                prev->right = nullptr;
                curr = curr->right;
            }
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

    cout << kthSmallest(root, 5) << endl;

    return 0;
}