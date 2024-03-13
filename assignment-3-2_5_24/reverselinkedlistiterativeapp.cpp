/*Recursive Reversal:

Base Case: Define a base case for the recursion. If the current node is null (indicating the end of the list or an empty list), return null.
Recursive Step: Recursively call the function on the next node of the list.
Reversal: When returning from the recursive calls, reverse the links between nodes by setting the next pointer of the next node to point to the current node.
Adjust Head Pointer: In the base case or after the reversal is complete, return the previous node (which becomes the new head of the reversed list).
Here's a step-by-step explanation of the recursive reversal approach:

Base Case: If the current node is null, return null.
Recursive Step: Recursively call the function on the next node of the list.
Reversal: When returning from the recursive calls, reverse the links between nodes by setting the next pointer of the next node to point to the current node.
Adjust Head Pointer: In the base case or after the reversal is complete, return the previous node (which becomes the new head of the reversed list).*/
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