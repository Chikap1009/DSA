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

int findLeftHeight(TreeNode* root) {
    TreeNode* temp = root;
    int height = 0;
    while(temp) {
        height++;
        temp = temp->left;
    }
    return height;
}

int findRightHeight(TreeNode* root) {
    TreeNode* temp = root;
    int height = 0;
    while(temp) {
        height++;
        temp = temp->right;
    }
    return height;
}

bool isPossible(int a,int b)
{
    if ((a==2 && b!=2) || (a!=2 && b==2)) return true; // 1 - Preorder, 2 - Inorder, 3 - Postorder
    return false;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int ans = isPossible(1, 2);

    cout << ans << endl;

    return 0;
}