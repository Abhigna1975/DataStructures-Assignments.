Recursively executing a function to reverse the sublist, starting at the second node, is how we reverse the linked list in the recursive technique. This is how it operates:
Standard Case:

Give the head pointer back exactly as it is if the list is empty or contains just one node.
Recursive Call: Beginning at the second node, recursively call the function to reverse the sublist.
Reverse Links: By pointing the second node's next pointer to the first node, you can reverse the link that connects the current node (the second) to the head node (the first).
Set Head Pointer: To designate the head node as the final node in the inverted list, set its next pointer to nullptr.
Bring Back the New Head:
Provide the inverted list's head pointer back.
*/
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
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Recursive function to reverse a linked list
Node* reverseRecursive(Node* head) {
    // Base case: if the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursively reverse the sublist starting from the second node
    Node* reversedHead = reverseRecursive(head->next);

    // Reverse the link between the second node (current) and the first node (head)
    head->next->next = head;

    // Set the next pointer of the head node to nullptr
    head->next = nullptr;

    // Return the head pointer of the reversed list
    return reversedHead;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Reverse the linked list recursively
    head = reverseRecursive(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}