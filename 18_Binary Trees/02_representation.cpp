#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

struct Node* newNode(int data) {
    struct Node* node = new Node(data);
    return node;
}

void create_tree(struct Node* root0, vector<int> &vec){
    root0->left = newNode(vec[1]);
    root0->right = newNode(vec[2]);
    root0->left->left = newNode(vec[3]);
    root0->left->right = newNode(vec[4]);
    root0->right->left = newNode(vec[5]);
    root0->right->right = newNode(vec[6]);
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    struct Node* root = new Node(v[0]);
    create_tree(root, v);

    return 0;
}