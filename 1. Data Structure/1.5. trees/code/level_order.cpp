#include <iostream>
#include <queue>
using namespace std;

struct bstNode {
    int data;
    bstNode* left;
    bstNode* right;

    bstNode(int num) {
        data = num;
        left = right = NULL;
    }
};

bstNode* Insert(bstNode* root, int num) {
    if (root == NULL) {
        return new bstNode(num);
    } else if (num < root->data) {
        root->left = Insert(root->left, num);
    } else if (num > root->data) {
        root->right = Insert(root->right, num);
    }

    return root;
}


void levelOrderTraversal(bstNode* root) {

    if (root == NULL) {
        return;
    } else {
        queue<bstNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            bstNode* current = Q.front();
            cout << current->data << " ";

            if (current->left != NULL) {
                Q.push(current->left);
            }

            if (current->right != NULL) {
                Q.push(current->right);
            }

            Q.pop();
        }

    }
}

int main() {

    bstNode* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 5);

    levelOrderTraversal(root);

    return 0;
}