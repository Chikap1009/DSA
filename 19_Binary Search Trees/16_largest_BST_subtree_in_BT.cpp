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

struct NodeValue {
    int largest, smallest, size;

    NodeValue(int largest, int smallest, int size) : largest(largest), smallest(smallest), size(size) {}
};

NodeValue largestBSTSubstreeHelper(TreeNode* root) {
    if (!root) return NodeValue(INT_MIN, INT_MAX, 0);

    NodeValue left = largestBSTSubstreeHelper(root->left);
    NodeValue right = largestBSTSubstreeHelper(root->right);

    if (left.largest < root->val && root->val < right.smallest) {
        return NodeValue(max(root->val, right.largest), 
                         min(root->val, left.smallest), 
                         left.size + right.size + 1);
    }

    return NodeValue(INT_MAX, INT_MIN, max(left.size, right.size));
}

int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubstreeHelper(root).size;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    cout << "Size of the largest BST subtree: " << largestBSTSubtree(root) << endl;
    
    return 0;
}