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

TreeNode* prevNode = nullptr;
void flatten1(TreeNode* root) {
    if (!root) return;

    flatten1(root->right);
    flatten1(root->left);

    root->right = prevNode;
    root->left = nullptr;
    prevNode = root;
}

void flatten2(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);

        if (!st.empty()) curr->right = st.top();
        curr->left = nullptr;

        curr = curr->right;
    }
}

void flatten3(TreeNode* root) {
    if (!root) return;

    TreeNode* curr = root;
    while(curr) {
        if (curr->left) {
            TreeNode* prev = curr->left;
            while(prev->right) {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
}

void printFlattenedTree(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    flatten1(root);
    printFlattenedTree(root);

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    flatten2(root);
    printFlattenedTree(root);

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    flatten3(root);
    printFlattenedTree(root);

    return 0;
}