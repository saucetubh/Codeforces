#include <bits/stdc++.h>
using namespace std;

class Node {
    public:  //we keep this public to allow simpler access to the fields from outside the Node class, helps avoid the boilerplate for getters and setters. In a real production code, we would want to make these private and provide getters and setters for better encapsulation.
        int data;
        Node* next;
    public:
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
        Node(int data, Node* next) {   //overloaded constructors
            this->data = data;
            this->next = next;
        }
};

int main() {
    Node* z = new Node(10); //new keyword returns a pointer to the newly allocated memory for the Node object, which is stored in variable y. This allows us to create a linked list by linking nodes together using their next pointers.
    //this object is stored on the heap, which means it will persist until we explicitly delete it, allowing us to create dynamic data structures like linked lists.

    //Node y = Node(10);
    //this creates a Node object on the stack, which will be automatically destroyed when it goes out of scope (at the end of the main function). This is not suitable for creating linked lists, as we need the nodes to persist beyond the scope of a single function call.

    Node* y = new Node(20, z); //this creates a new Node object with data 20 and next pointer pointing to the Node object created in the previous line (z). This effectively creates a linked list with two nodes: y -> z.
    Node* x = new Node(30, y); //this creates a new Node object with data 30 and next pointer pointing to the Node object created in the previous line (y). This effectively creates a linked list with three nodes: x -> y -> z.

    cout << x->data << " " << x->next->data << " " << x->next->next->data << endl; //this prints the data of the three nodes in the linked list, which should output "30 20 10".

    //A better way to print is to use a loop to traverse the linked list until we reach the end (when the next pointer is nullptr). This way, we can print any number of nodes in the linked list without having to hardcode the number of nodes.
    Node* current = x; //start from the head of the linked list (x)
    while(current != nullptr) {
        cout << current->data << " "; //print the data of the current node
        current = current->next; //move to the next node
    }
    cout << endl;

    //C++ does not have a garbage collector unlike languages like Java or Python, so we need to manually free the (heap) memory allocated for the nodes using the delete keyword. 
    //This is important to prevent memory leaks, which can occur when we allocate memory but never free it, leading to a gradual increase in memory usage over time during program execution. 
    //Once execution is over, heap will anyways automatically be emptied.

    delete x;
    delete y;
    delete z;

    //converting array to linked list

    int arr[] = {1,2,3,4,5};
    Node* head = new Node(arr[0]);
    Node* previous = head; //this isnt creating a new node, it just copies the address of the node in heap, stored in head, to the variable previous. So both head and previous point to the same node in heap.
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<len;i++) {
        Node* current = new Node(arr[i]);
        previous->next = current;
        previous = current;
    }

    Node* printer = head;
    while(printer != nullptr) {
        cout << printer->data << " ";
        printer = printer->next;
    }
    cout << endl;

    //clean up memory 
    printer = head;
    while(printer) {
        Node* temp = printer; //store the current node in a temporary variable before deleting it, so we can move to the next node after deletion.
        printer = printer->next; //move to the next node before deleting the current node, to avoid losing access to the rest of the linked list.
        delete temp; //delete the current node to free up memory.
    }
    
    return 0;
} 