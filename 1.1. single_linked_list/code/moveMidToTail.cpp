#include <iostream>
#include <cmath>
using namespace std;


struct NODE {
	int info;
	NODE* pNext;
};

struct LIST {
	NODE* pHead;
	NODE* pTail;
};


NODE* Create(int x) {
    NODE* node = new NODE;
    node->info = x;
    node->pNext = nullptr;
    return node;
}

void Insert(LIST &l, int x) {
    NODE* node = Create(x);

    if (l.pHead == nullptr) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail->pNext = node;
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

void PrintList(NODE* head) {
    if (head == nullptr) {
        cout << "Empty List.";
    } else {
        NODE* current = head;
        while (current != nullptr) {
            cout << current->info << " ";
            current = current->pNext;
        }
    }

}

int Count(NODE* head) {
    NODE* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->pNext;
    }

    return count;
}

void Function(LIST &l) {
    int mid = round((float)Count(l.pHead)/2);
    int count = 1;
    NODE* current = l.pHead;

    for (int i=1; i<=Count(l.pHead); i++) {
        if (i == mid-1) {
            NODE* temp = nullptr;
            temp = current->pNext;
            current->pNext = current->pNext->pNext;
            temp->pNext = nullptr;
            l.pTail->pNext = temp;
            l.pTail = temp;
            break;
        }
        current = current->pNext;
    }
}


int main() {
    LIST L;

	CreateEmptyList(L);
	CreateList(L);

	Function(L);

	PrintList(L.pHead);

    return 0;
}
