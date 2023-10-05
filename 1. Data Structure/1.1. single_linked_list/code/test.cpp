#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int number) {
        data = number;
        next = NULL;
    }
};

int main() {
    Node* head = NULL;

    for (int i=0; i<5; i++) {
        Node* node = new Node(i);

        if (i==0) {
            head=node;
        } else {
            Node* temp = head;
            // Traverse until reaching the last node
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // Assign link from last node to newly created node
            temp->next = node;

        }
    }

    Node* current = head;

    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}

'''
Step 1: Create head pointer

+ ---- +
+ HEAD +
+ ---- +

-----------------------------
Step 2: Create first node and assign head to that node

+ --- +
+  1  +
+ --- +
   ^
   |
+ ---- +
+ HEAD +
+ ---- +

-------------------------------
Step 3: Create `temp` node to loop through every node

+ ---- +
+ TEMP +
+ ---- +
   |
   v
+ --- +     + --- +     + --- +
+  1  + --> +  2  + --> +  3  +
+ --- +     + --- +     + --- +

-------------------------------

            + ---- +
            + TEMP +
            + ---- +
               |
               v
+ --- +     + --- +     + --- +
+  1  + --> +  2  + --> +  3  +
+ --- +     + --- +     + --- +

-------------------------------

                        + ---- +
                        + TEMP +
                        + ---- +
                           |
                           v
+ --- +     + --- +     + --- +
+  1  + --> +  2  + --> +  3  +
+ --- +     + --- +     + --- +

----------------------------------------------
Step 4: Each time `temp` reach the end, where the link of last node is NULL
--> Create a link from `last node` to `newly created node`.

                        + ---- +
                        + TEMP +
                        + ---- +
                           |
                           v
+ --- +     + --- +     + --- +     + --- +
+  1  + --> +  2  + --> +  3  + --> + NEW +
+ --- +     + --- +     + --- +     + --- +

'''