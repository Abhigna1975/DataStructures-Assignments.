/*Sentinel Node Approach:

Initialize Sentinel Node: Create a sentinel node and set its next pointer to the head of the linked list.
Initialize Length: Initialize a variable to keep track of the length of the linked list. Set it to 0 initially.
Traverse the List: Start traversing the list from the sentinel node.
Count Nodes: Increment the length variable for each node encountered during the traversal.
End of List: Stop the traversal when you reach the end of the list (i.e., you encounter the sentinel node).
Return Length: Once the traversal is complete, return the final length of the linked list.
Here's a step-by-step explanation of the sentinel node approach:

Initialize Sentinel Node: Create a sentinel node and set its next pointer to the head of the linked list.
Initialize Length: Initialize a variable to keep track of the length of the linked list. Set it to 0 initially.
Traverse the List: Start traversing the list from the sentinel node.
Count Nodes: Increment the length variable for each node encountered during the traversal.
End of List: Stop the traversal when you reach the end of the list (i.e., you encounter the sentinel node).
Return Length: Once the traversal is complete, return the final length of the linked list.*/
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
