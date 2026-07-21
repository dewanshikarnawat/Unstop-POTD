//Problem: Build a Binary Search Tree from the given insertion order and print its postorder traversal (Left → Right → Root).
//Topic: Binary Search Tree (BST), Tree Traversal (Postorder)
//Pattern: Medium

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    postorder(root);
    return 0;
}
