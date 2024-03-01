 /*Real-Life Scenario 1: Employee Hierarchy and family tree representation

In many organizations, a hierarchical structure is commonly employed to delineate organizational stages, with a binary tree emerging as an optimal choice. A binary tree adeptly elucidates complex concepts with utmost simplicity. In this representation:

Like the root      -> founder / CEO / Head of the family / Grandparents
left & rigth nodes -> subordinates / HR / Parents
child nodes        -> employees / Kids

Such a representation aids in the effective management of relationships, work assignments, and responsibilities.


Justification for Using Binary Tree in Employee Hierarchy:

Hierarchical Representation:
In the organizational structure, a hierarchy is formed where each employee works under a manager at a higher level, resembling a tree structure.

Efficient Searching and Traversal:
A binary tree provides flexible searching and traversal features. It facilitates the identification of organizational levels and their relationships. Traversal operations, such as in-order traversal, allow listing employees in a sorted manner based on their positions.

Easy Identification of Reporting Relationships:
With two child nodes, the left focuses on the immediate subordinate on the left, and the right focuses on the immediate subordinate on the right.

Simple Insertion and Deletion:
Adding nodes, child nodes, or employees involves direct operations in the tree, exemplified by insertion. Deletion operations, such as removing employees who are fired or have left the organization, are easily executed.

Scalability and Flexibility:
Binary trees demonstrate efficient and flexible performance, accommodating organizational development. The time complexity of insertion, deletion, and search operations is optimized. The structure allows flexibility for changes in relationships, team reformation, promotions, etc.




*/
//
#include <iostream>
using namespace std;

// Real-Life Scenario 1: Employee Hierarchy
class Employee {
public:
    int emp_id;
    string name;
    Employee* left;
    Employee* right;

    Employee(int emp_id, string name) {
        this->emp_id = emp_id;
        this->name = name;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Employee* insert_employee(Employee* root, Employee* new_employee) {
    if (!root) {
        return new_employee;
    }

    if (new_employee->emp_id < root->emp_id) {
        root->left = insert_employee(root->left, new_employee);
    }
    else if (new_employee->emp_id > root->emp_id) {
        root->right = insert_employee(root->right, new_employee);
    }

    return root;
}

void print_hierarchy(Employee* root) {
    if (root) {
        print_hierarchy(root->left);
        cout << "Employee ID: " << root->emp_id << ", Name: " << root->name << endl;
        print_hierarchy(root->right);
    }
}

// Real-Life Scenario 2: File System Structure
/*Binary tree: Each node symbolizes a file, while child nodes denote files within the directory. 
This binary tree adheres to and enables flexible searching within the file system. 
It serves as a representation of the hierarchical structure of the file system.
Hierarchical Representation:
Binary tree depicts the hierarchical structure of the file system, where each node corresponds to a file. The left and right nodes, or child nodes, represent files within the directory.

Efficient Searching:
Binary tree facilitates efficient searching within files. Along with optimized time complexity, searching for a specific file becomes quicker.

Clear Directory Structure:
The binary tree structure creates a clear, flexible, and logical representation of the directory. The left and right nodes, or child nodes, signify the files within the directory.

Space Efficiency:
Effective space utilization is achieved by organizing files within the directory, reducing the need for linear searching and providing an efficient storage system.

Dynamic Adaptability:
Binary tree enables dynamic adaptability to changes in the file system. Adding, renaming, or restructuring becomes much easier with this system.

In both scenarios, the advantages of using a binary tree include efficient representation of hierarchical relationships, quick searching and traversal capabilities, adaptability to changes, simplicity, and scalability. The chosen data structure aligns well with the inherent characteristics of organizational hierarchies and file system structures, providing practical and effective solutions.









*/
class FileSystemNode {
public:
    string name;
    bool is_directory;
    FileSystemNode* left;
    FileSystemNode* right;

    FileSystemNode(string name, bool is_directory) {
        this->name = name;
        this->is_directory = is_directory;
        this->left = nullptr;
        this->right = nullptr;
    }
};

FileSystemNode* insert_file_system_node(FileSystemNode* root, FileSystemNode* new_node) {
    if (!root) {
        return new_node;
    }

    if (new_node->name < root->name) {
        root->left = insert_file_system_node(root->left, new_node);
    }
    else if (new_node->name > root->name) {
        root->right = insert_file_system_node(root->right, new_node);
    }

    return root;
}

void print_file_system_structure(FileSystemNode* root, string indent = "") {
    if (root) {
        cout << indent << (root->is_directory ? root->name + "/" : root->name) << endl;
        print_file_system_structure(root->left, indent + "  ");
        print_file_system_structure(root->right, indent);
    }
}

int main() {
    // Employee Hierarchy
    int size;
    cout << "Enter the number of employees: ";
    cin >> size;
    Employee* root_employee = nullptr;

    for (int i = 0; i < size; ++i) {
        int emp_id;
        string name;
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cout << "Enter Employee Name: ";
        cin >> name;
        Employee* new_employee = new Employee(emp_id, name);
        root_employee = insert_employee(root_employee, new_employee);
    }

    cout << "\nEmployee Hierarchy:\n";
    print_hierarchy(root_employee);

    // File System Structure
    int file_size;
    cout << "\nEnter the number of files/directories: ";
    cin >> file_size;
    FileSystemNode* root_directory = nullptr;

    for (int i = 0; i < file_size; ++i) {
        string name;
        bool is_directory;
        cout << "Enter File/Directory Name: ";
        cin >> name;
        cout << "Is it a directory? (1 for yes, 0 for no): ";
        cin >> is_directory;
        FileSystemNode* new_node = new FileSystemNode(name, is_directory);
        root_directory = insert_file_system_node(root_directory, new_node);
    }

    cout << "\nFile System Structure:\n";
    print_file_system_structure(root_directory);

    return 0;
}
/*In both scenarios, the binary tree structure helps to organize and represent hierarchical relationships efficiently. 
The code allows dynamic input for creating the binary tree based on user-provided data.*/
