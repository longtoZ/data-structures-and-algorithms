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

    // return root;
}

int Height(Node* root) {
    int countLeft = 0;
    int countRight = 0;

    if (root == NULL) {
        return -1;
    }

    Node* current = root;
    while (current->left != NULL) {
        countLeft++;
        current = current->left;
    }

    current = root;
    while (current->right != NULL) {
        countRight++;
        current = current->right;
    }

    if (countLeft < countRight) {
        return countRight;
    } else {
        return countLeft;
    }
}


int main() {

    Node* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 25);

    cout << Height(root);

    return 0;
}