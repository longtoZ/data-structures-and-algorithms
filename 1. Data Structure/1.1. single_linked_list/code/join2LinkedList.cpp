#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE* next;
};

struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* Create(int x) {
    NODE* node = new NODE;
    node->data = x;
    node->next = nullptr;
    return node;
}

NODE* Insert(LIST &l, int x) {
    NODE* node = Create(x);

    if (l.pHead == nullptr && l.pTail == nullptr) {
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

void CreateList_AddTail(LIST &l) {
    while (true) {
        int x;
        cin >> x;

        if (x == -1) {
            break;
        } else {
            Insert(l, x);
        }
    }
}

void CreateList_Inner(LIST &l_new, LIST &l_old) {
    NODE* current = l_old.pHead;

    while (current != nullptr) {
        Insert(l_new, current->data);
        current = current->next;
    }
}

LIST Join(LIST l1, LIST l2) {

    LIST L, L1, L2;
    CreateEmptyList(L);

    if (l1.pHead != nullptr && l2.pHead != nullptr) {

        CreateEmptyList(L1);
        CreateEmptyList(L2);

        CreateList_Inner(L1, l1);
        CreateList_Inner(L2, l2);
        L1.pTail->next = L2.pHead;

        L.pHead = L1.pHead;
        L.pTail = L2.pTail;
    }

    return L;
}

void Edit(LIST &l, int X, int Y) {
    NODE* current = l.pHead;

    while (current != nullptr) {
        if (current->data == X) {
            current->data = Y;
        }
        current = current->next;
    }
}


void PrintList(NODE* pHead) {
    NODE* current = pHead;

    if (current == nullptr) {
        cout << "Empty List.";
    } else {
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    cout << endl;
}

int main() {
    LIST L, L1, L2;
	int X, Y;
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList_AddTail(L1);
	CreateList_AddTail(L2);

	L=Join(L1, L2);
	cin >> X >> Y;
	Edit(L, X, Y);

	PrintList(L1.pHead);
    PrintList(L2.pHead);
    PrintList(L.pHead);

    return 0;
}