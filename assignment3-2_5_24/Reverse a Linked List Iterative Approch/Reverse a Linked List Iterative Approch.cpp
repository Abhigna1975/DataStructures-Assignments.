By iteratively traversing the linked list and altering each node's next pointer to point to the previous node rather than the next node, we can reverse the linked list using this method.
Set Up Pointers:
Three pointers are kept up to date: previous, current, and next.
Set prev's initial value to nullptr (because it will be the final node in the reversed list).
Set the current value to the first entry in the initial list.
Repeated Reversal:
Go over the list iteratively until current turns into nullptr.
Within the circle:
Put the subsequent current node in the following pointer.
In essence, the link is reversed when the next pointer of current is updated to point to predecessor.
To get ready for the next iteration, move from previous to current and from current to next.
Revise the Head Pointer:
Following the loop, before will be pointing to the new head of the reversed list.
Update the head pointer of the list to prev.

*/


// Iterative function to reverse a linked list

#include <iostream>

using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Iterative function to reverse a linked list
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original linked list: ";
    printList(head);

    // Reverse the linked list iteratively
    head = reverseIterative(head);

    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}

/* Justification:
To carry out the reversal, we initialize the prev, current, and next pointers.
By changing the current node's next pointer to point to the previous node, we reverse the link inside the loop.
To get ready for the following iteration, we shift the pointers previous, current, and next.
We update the head pointer in accordance with the fact that, following the loop, prev will point to the new head of the inverted list.