/*Recursive Approach:

Base Case: Define a base case for the recursion. If the current node is null (indicating the end of the list), return 0.
Recursive Step: Recursively call the function on the next node of the list.
Increment Counter: In each recursive call, increment a counter variable by 1.
Return Counter: When the recursion reaches the end of the list, return the final value of the counter, which represents the length of the linked list.
Here's a step-by-step explanation of the recursive approach:

Base Case: If the current node is null, return 0.
Recursive Step: Otherwise, recursively call the function on the next node of the list.
Increment Counter: In each recursive call, increment a counter variable by 1.
Return Counter: When the recursion reaches the end of the list, return the final value of the counter.*/
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
