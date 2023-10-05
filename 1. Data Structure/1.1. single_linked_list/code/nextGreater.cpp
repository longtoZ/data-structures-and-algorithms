#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int num) {
        data = num;
        next = nullptr;
    }
};

struct LIST {
    Node* pHead;
    Node* pTail;
};

void Insert(LIST &l, int num) {
    Node* node = new Node(num);

    if (l.pHead == nullptr) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail->next = node;
        l.pTail = node;
    }
}

void CreateEmptyList(LIST &l) {
    l.pHead = l.pTail = nullptr;
}

void CreateList(LIST &l) {
    while (true) {
        int x;
        cin >> x;
        if (x != -1) {
            Insert(l, x);
        } else {
            break;
        }
    }
}

void Function(Node* head) {
    if (head == nullptr) {
        cout << "Empty List.";
    } else {
        Node* current = head;

        while (current != nullptr) {

            Node* greater = current;
            bool foundGreater = false;

            while (greater != nullptr) {
                if (greater->next == nullptr && foundGreater == false) {
                    cout << current->data << " " << -1 << endl;
                }

                if (greater->data > current->data) {
                    cout << current->data << " " << greater->data << endl;
                    foundGreater = true;
                    break;
                }

                greater = greater->next;
            }

            current = current->next;
        }
    }

}

int main() {
    LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);

	Function(L.pHead);

    return 0;
}
