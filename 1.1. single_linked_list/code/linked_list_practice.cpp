#include <iostream>
#include <cmath>
using namespace std;

// Store value of each Node
struct Node {
    int data;
    Node* next;

    Node(int num) {
        data = num;
        next = NULL;
    }
};

// Store head
struct LinkedList {
    Node* head = NULL;
};

void print(LinkedList &l) {
    Node* current = l.head;

    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

void reverseList(LinkedList &l) {

    // Reverse list
    Node* temp2 = NULL;
    Node* temp1 = NULL;

    while (l.head != NULL) {
        temp2 = l.head->next;
        l.head->next = temp1;
        temp1 = l.head;
        l.head = temp2;
    }

    l.head = temp1;
}

void insertionEnd(LinkedList &l, int num) {
    Node* node = new Node(num);
    Node* current = l.head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;

}

void insertAtMiddle(LinkedList &l, int num) {

    int count = 0;
    int mid = 0;
    Node* current = l.head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    if (count%2==0) {
        mid = count/2;
    } else {
        mid = count/2 + 1;
    }

    Node* node = new Node(num);
    current = l.head;
    count = 1;

    while (current != NULL) {
        if (count == mid) {
            node->next = current->next;
            current->next = node;
            break;
        }

        current = current->next;
        count++;
    }


}

void insertBefore(LinkedList &l, int pos, int num) {
    Node* current = l.head;
    Node* node = new Node(num);
    int count = 1;

    while (current != NULL) {
        if (pos == 1) {
            node->next = l.head;
            l.head = node;
            break;
        } else if (count == pos-1) {
            node->next = current->next;
            current->next = node;
            break;
        }

        count++;
        current = current->next;
    }

}

int getNthNode(LinkedList &l, int pos) {
    Node* current = l.head;
    int count = 0;

    while (current != NULL) {
        if (count == pos) {
            return current->data;
        }

        count++;
        current = current->next;
    }

    return -1;
}

void deleteFirstNode(LinkedList &l) {
    Node* temp = l.head;
    l.head = l.head->next;
    delete temp;

}

void deleteSpecificNode(LinkedList &l, int pos) {
    int count = 1;
    Node* current = l.head;

    while (current != NULL) {
        if (pos == 1) {
            Node* temp =l. head;
            l.head = l.head->next;
            delete temp;
            break;
        } else if (count == pos-1) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            break;
        }

        count++;
        current = current->next;
    }

}

int findNodeFromMid(LinkedList &l, int pos) {
    int count = 0, mid = 0;
    Node* current = l.head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    if (count%2 == 0) {
        mid = count/2;
    } else {
        mid = count/2 + 1;
    }

    count = 1;
    current = l.head;

    while (current != NULL) {
        if (count == (mid-pos)) {
            return current->data;
        }

        count++;
        current = current->next;
    }

    return -1;
}

int main() {

    // Generate list
    LinkedList list;

    for (int i=1; i<=13; i+=2) {
        Node* node = new Node(i);

        if (list.head == NULL) {
            list.head = node;
        } else {
            Node* temp = list.head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = node;
        }
    }

    print(list);
    insertBefore(list, 1, 30);
    insertBefore(list, 1, 40);    
    print(list);


    return 0;
}