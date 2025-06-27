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

// Make these pointers local to avoid global pollution
TreeNode* first;
TreeNode* middle;
TreeNode* last;
TreeNode* previous;

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    if (previous && previous->val > root->val) {
        if (!first) {
            first = previous;
            middle = root;
        } 
        else {
            last = root;
        }
    }

    previous = root;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    // Reset pointers
    first = middle = last = previous = nullptr;

    inorder(root);

    if (last) swap(first->val, last->val);
    else swap(first->val, middle->val);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before recovery: ";
    printInorder(root);  // Should show 1 2 3 if sorted, but will show wrong due to swapped nodes

    recoverTree(root);

    cout << "\nAfter recovery: ";
    printInorder(root);  // Should show 1 2 3 in order

    return 0;
}