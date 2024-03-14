/*Binary Search in Linked List:

Check if List is Sorted: Verify whether the linked list is sorted. If not, sorting it would be the initial step.
Initialize Pointers: Set two pointers, one pointing to the beginning of the list and the other to the end.
Binary Search: Perform binary search on the linked list by comparing the target value with the value at the midpoint of the list.
If the target value matches the midpoint value, return true.
If the target value is less than the midpoint value, move the end pointer to the midpoint.
If the target value is greater than the midpoint value, move the start pointer to the midpoint.
Repeat: Repeat the binary search process until either the target value is found or the start pointer surpasses the end pointer.
Return Result: If the target value is found, return true; otherwise, return false.
This approach leverages the efficiency of binary search in finding elements in a sorted list, potentially reducing the time complexity compared to linear search methods.

Here's a step-by-step explanation of the binary search in linked list approach:

Check if List is Sorted: Ensure that the linked list is sorted.
Initialize Pointers: Set two pointers, one pointing to the beginning of the list and the other to the end.
Binary Search: Perform binary search on the linked list by comparing the target value with the value at the midpoint of the list.
Repeat: Repeat the binary search process until either the target value is found or the start pointer surpasses the end pointer.
Return Result: If the target value is found, return true; otherwise, return false.*/
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
    // Private member function for recursive search
    bool searchRecursive(Node* node, int key) {
        if (!node)
            return false;
        if (node->data == key)
            return true;
        return searchRecursive(node->next, key);
    }
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
    // Iterative search for an element
    bool searchIterative(int key) {
        Node* current = head;
        while (current) {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }
    // Wrapper function to start the recursive search from the head
    bool search(int key) {
        return searchRecursive(head, key);
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
    // Search for an element (e.g., 3) using iterative approach
    cout << "Iterative Search:" << endl;
    cout << boolalpha << llist.searchIterative(3) << endl;  // Output: true
    // Search for an element (e.g., 6) using recursive approach
    cout << "Recursive Search:" << endl;
    cout << boolalpha << llist.search(6) << endl;  // Output: false
    return 0;
}