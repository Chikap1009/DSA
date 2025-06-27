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

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            if (reverse) node = node->right;
            else node = node->left;
        }
    }

    public:
        BSTIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }

        int next() {
            TreeNode* temp = st.top();
            st.pop();
            if (reverse) pushAll(temp->left);
            else pushAll(temp->right);
            return temp->val;
        }
};

bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i<j) {
        if (i+j == k) return true;
        else if (i+j > k) j = r.next();
        else i = l.next();
    }

    return false;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;
    if (findTarget(root, k)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}