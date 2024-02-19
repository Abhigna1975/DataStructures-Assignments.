/*Real - Life Scenario 5: Inventory Management and Market Managenment

Context :
In the realm of inventory management for a retail store, a linked list is employed to represent the list of available materials in the storage or stock.Each node in the list corresponds to a specific product, and nodes are linked to establish the order in which products are organized.

Utilization :
	A linked list offers dynamic and efficient organization for managing inventory.New materials or products can be seamlessly added, and sold - out items can be removed.The order of the products can be adjusted without the need for resizing the array.This allows changes in stock levels and product availability to align dynamically.

	Dynamic Inventory Updates :
As new products are introduced or existing ones are sold out of stock, the list performs updates effortlessly.Nodes can be added or removed dynamically, providing a real - time reflection of inventory status without the need for data reorganization.

Efficient Product Reordering :
When existing stock is depleted, products need to be reordered based on factors such as best - sellers, season, popularity, and demand.This facilitates efficient reordering, allowing products to be moved up or down the list to reflect changes in demand without the need for complex data manipulation.

Memory Efficiency :
A linked list can be more memory - efficient than an array when handling a variable number of products with rapid changes in stock levels.Memory is allocated dynamically.

In this scenario, a linked list serves as a practical data structure for inventory management, providing flexibility, dynamic adaptability to changes in product availability, efficient reordering, and memory efficiency in handling various inventory - related operations.*/

/*Suitability of Linked List for Inventory Management:

Dynamic Updates:

Linked lists allow for dynamic updates to the inventory, such as adding or removing items. The dynamic feature of linked lists makes it convenient to adapt to changes in stock levels without the need for resizing, restructuring, or reorganizing the data structure.

Efficient Insertion and Deletion:

Adding a new product or removing sold-out products from the inventory is efficient with linked lists. New products can be inserted or existing products can be removed without the overhead of shifting elements, as is required in an array-based data structure.

Memory Efficiency:

Linked lists can be more memory-efficient than arrays when handling a multitude of products. Memory is allocated dynamically, ensuring that only the required space is used to store the current products in the inventory.

Easy Reordering:

Products in the inventory may need to be reordered based on demand, popularity, or other factors. Linked lists provide an efficient way to reorder products by moving nodes, reflecting changes in product priorities without the need for extensive data manipulation.

Sequential Access:

Linked lists provide sequential access to products or materials, allowing for easy traversal. This sequential feature aligns well with the physical organization of products in a store, making it straightforward to navigate through the inventory.

Advantages of Using a Binary Tree in Inventory Management:

Efficient Searching:

Binary trees excel in searching operations, which can be beneficial for finding specific products quickly. If the inventory requires searching based on product IDs or names, a binary tree's logarithmic search time (O(log N)) is advantageous.

Sorted Representation:

A binary tree can maintain a sorted order of products based on certain criteria (e.g., product names or IDs). This sorted representation can simplify inventory management tasks that involve maintaining an ordered list of products.

Balancing for Uniform Access:

A balanced binary tree ensures that access to products is distributed uniformly, preventing skewed access patterns. This can be beneficial in scenarios where products are accessed randomly, ensuring efficient retrieval regardless of the search key.

Range Queries:

Binary trees support efficient range queries. For example, finding all products within a certain price range or quantity range becomes more straightforward with a binary tree compared to a linked list.

Complex Queries and Analytics:

If the inventory management system requires more complex queries or analytics, such as finding the most expensive products or products with specific attributes, a binary tree's structured nature can facilitate such operations efficiently.

In summary, while linked lists are suitable for dynamic updates and memory efficiency in inventory management, binary trees offer advantages in efficient searching, sorted representation, balanced access, range queries, and support for more complex analytical queries.
The choice between linked lists and binary trees depends on the specific requirements and use cases of the inventory management system.*/

//Here's the complete C++ code for the linked list implementation with dynamic user input:

#include <iostream>
#include <string>

// Node representing a product in the inventory
struct ProductNode {
    int product_id;
    std::string product_name;
    int quantity;
    ProductNode* next;

    ProductNode(int id, const std::string& name, int qty) : product_id(id), product_name(name), quantity(qty), next(nullptr) {}
};

// Linked list representing the inventory
class InventoryLinkedList {
public:
    InventoryLinkedList() : head(nullptr) {}

    // Add a new product to the inventory
    void addProduct(int product_id, const std::string& product_name, int quantity) {
        ProductNode* new_product = new ProductNode(product_id, product_name, quantity);
        new_product->next = head;
        head = new_product;
    }

    // Display the current state of the inventory
    void displayInventory() {
        ProductNode* current = head;
        while (current != nullptr) {
            std::cout << "Product ID: " << current->product_id << ", Product Name: " << current->product_name
                << ", Quantity: " << current->quantity << std::endl;
            current = current->next;
        }
    }

    // Destructor to free memory
    ~InventoryLinkedList() {
        ProductNode* current = head;
        while (current != nullptr) {
            ProductNode* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

private:
    ProductNode* head;
};

// Function to get dynamic input from the user
void getUserInput(int& size, int& id, std::string& name, int& quantity) {
    std::cout << "Enter the number of products: ";
    std::cin >> size;

    for (int i = 0; i < size; ++i) {
        std::cout << "\nEnter details for Product " << i + 1 << ":\n";
        std::cout << "Product ID: ";
        std::cin >> id;

        std::cout << "Product Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
        std::getline(std::cin, name);

        std::cout << "Quantity: ";
        std::cin >> quantity;
    }
}

// Example Usage
int main() {
    InventoryLinkedList inventoryLinkedList;

    int size, id, quantity;
    std::string name;

    // Get dynamic input from the user
    getUserInput(size, id, name, quantity);

    // Adding products to the linked list
    for (int i = 0; i < size; ++i) {
        inventoryLinkedList.addProduct(id, name, quantity);
    }

    // Displaying the final state of the inventory
    std::cout << "\nFinal Inventory Linked List:\n";
    inventoryLinkedList.displayInventory();

    return 0;
}
//This code allows the user to input the number of products and their details dynamically and then displays the final state of the linked list.

