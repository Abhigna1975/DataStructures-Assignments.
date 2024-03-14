/*Stack-Based Approach:

Initialize Stack: Create an empty stack data structure.
Traverse the List: Iterate through the list, pushing each node onto the stack.
Count Nodes: After traversing the entire list, the size of the stack represents the length of the linked list.
Return Length: Return the size of the stack as the length of the linked list.
Here's a step-by-step explanation of the stack-based approach:

Initialize Stack: Create an empty stack data structure.
Traverse the List: Iterate through the list, pushing each node onto the stack.
Count Nodes: After traversing the entire list, the size of the stack represents the length of the linked list.
Return Length: Return the size of the stack as the length of the linked list.
*/
#include <iostream>

using namespace std;

// Define a Node structure
//Small change
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Define a LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the end of the list
    void insert(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    // Find the length of the linked list (Iterative Approach)
    int lengthIterative() {
        int length = 0; // Initialize length variable
        Node* current = head;
        while (current) {
            length++; // Increment length for each node
            current = current->next;
        }
        return length;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedList llist;
    llist.insert(1);
    llist.insert(2);
    llist.insert(3);
    llist.insert(4);
    llist.insert(5);

    // Find the length of the linked list using iterative approach
    cout << "Length of the linked list (Iterative): " << llist.lengthIterative() << endl;  // Output: 5

    return 0;
}