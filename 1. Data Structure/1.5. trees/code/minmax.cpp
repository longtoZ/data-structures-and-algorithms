#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int num) {
        data = num;
        left = right = NULL;
    }
};

Node* Insert(Node* root, int num) {
    if (root == NULL) {
        return new Node(num);
    } else if (num < root->data) {
        root->left = Insert(root->left, num);
    } else if (num > root->data) {
        root->right = Insert(root->right, num);
    }

    return root;
}

Node* Max(Node* root) {
    // Empty tree
    if (root == NULL) {
        return NULL;
    }

    // The last node in right is max
    if (root->right == NULL) {
        return root;
    }

    // Continue traversing to right
    return Max(root->right);
}

Node* Min(Node* root) {
    // Empty tree
    if (root == NULL) {
        return NULL;
    }

    // The last node in left is min
    if (root->left == NULL) {
        return root;
    }

    // Continue traversing to left
    return Min(root->left);
}

int main() {

    Node* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 25);

    Node* min = Min(root);
    Node* max = Max(root);

    cout << min->data << endl;
    cout << max->data << endl;
    return 0;
}