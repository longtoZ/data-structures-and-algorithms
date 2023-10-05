#include <iostream>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef TNODE* TREE;

TNODE* CreateNode(int num) {
    TNODE* node = new TNODE;
    node->key = num;
    node->pLeft = node->pRight = NULL;

    return node;
}

struct Node {
    TNODE* key;
    Node* next;

    Node(TNODE* value) {
        key = value;
        next = NULL;
    }
};

// Store BST Node as key in LinkedList Node
class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    bool empty() {
        return head == NULL;
    }

    void enqueue(TNODE* node) {
        Node* newNode = new Node(node);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (empty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    TNODE* front() {
        if (empty()) {
            return NULL;
        }
        return head->key;
    }
};

TNODE* Insert(TNODE* root, int num) {
    if (root == NULL) {
        return CreateNode(num);
    } else {
        if (num < root->key) {
            root->pLeft = Insert(root->pLeft, num);
        } else {
            root->pRight = Insert(root->pRight, num);
        }
    }
}

void CreateTree(TREE& root) {
    while (true) {
        int x;
        cin >> x;
        if (x != -1) {
            root = Insert(root, x);
        } else {
            break;
        }
    }
}

int CountLeaf(TNODE* root) {
    if (root == NULL) {
        return 0;
    } else {
        int count = 0;
        Queue Q;
        Q.enqueue(root);

        while (!Q.empty()) {
            TNODE* current = Q.front();

            if (current->pLeft != NULL) {
                Q.enqueue(current->pLeft);
            }

            if (current->pRight != NULL) {
                Q.enqueue(current->pRight);
            }

            if (current->pRight == NULL && current->pLeft == NULL) {
                count++;
            }

            Q.dequeue();
        }

        return count;
    }

}

int main() {

    TREE T;
    T = NULL;
    CreateTree(T);

    cout << CountLeaf(T);

    return 0;
}