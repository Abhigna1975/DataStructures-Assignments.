Recursive Call: The function calls itself with the subsequent node in the list during the recursive step.
The next node (node->next) is used in the recursive call to the same function.

Termination Condition: The recursion ends and the function resumes returning values up the call stack when the base case is satisfied, or when we reach the end of the list.
Counting Nodes: To count the current node, the function adds 1 to the outcome of the recursive call at each stage of the recursion.
Until the conclusion of the list, we keep going through this process.
Return Value: The function's return value indicates how long the linked list is.*/


#include <iostream>

using namespace std;

// Define a Node structure
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

    // Find the length of the linked list (Recursive Approach)
    int lengthRecursive(Node* node) {
        if (!node) // Base case: If current node is null
            return 0;
        // Recursive call to count nodes in the remaining list
        return 1 + lengthRecursive(node->next);
    }

    // Wrapper function to start the recursive length calculation from the head
    int lengthRecursiveWrapper() {
        return lengthRecursive(head);
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

    // Find the length of the linked list using recursive approach
    cout << "Length of the linked list (Recursive): " << llist.lengthRecursiveWrapper() << endl;  // Output: 5

    return 0;
}


/*Explanation:
A pointer to the current node is passed as an argument to the lengthRecursive method.
It returns 0 (basic case) if the current node is null.
If not, it adds 1 to the outcome of the function's recursive call with the following node in the list.
*/