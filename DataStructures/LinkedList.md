# Complete Guide to Linked Lists in C++

---

## Table of Contents
1. [What is a Linked List?](#what-is-a-linked-list)
2. [The Node Class](#the-node-class)
3. [Stack vs Heap — Where Objects Live](#stack-vs-heap)
4. [Building a Linked List Manually](#building-a-linked-list-manually)
5. [Traversing a Linked List](#traversing-a-linked-list)
6. [Converting an Array to a Linked List](#converting-an-array-to-a-linked-list)
7. [Memory Management](#memory-management)
8. [Common Linked List Operations](#common-linked-list-operations)
9. [Types of Linked Lists](#types-of-linked-lists)
10. [Time & Space Complexity](#time--space-complexity)
11. [Full Reference Code](#full-reference-code)

---

## What is a Linked List?

A **linked list** is a linear data structure where elements (called **nodes**) are stored in memory non-contiguously. Each node holds some data and a pointer to the next node in the sequence.

```
[30 | *] --> [20 | *] --> [10 | nullptr]
  x              y              z
```

This is different from an array, where elements are stored in contiguous memory. Linked lists allow efficient insertions and deletions (especially at the front) without shifting elements, but don't support random access like arrays do.

---

## The Node Class

Every linked list is built from nodes. Here's a well-structured `Node` class:

```cpp
class Node {
    public:
        int data;
        Node* next;

        // Constructor 1: only data, next defaults to nullptr
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }

        // Constructor 2: data + manually set next pointer (overloaded constructor)
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
};
```

### Why `public` fields?
We keep `data` and `next` public to allow direct access from outside the class, avoiding the boilerplate of writing getters and setters. Since `Node` is an internal implementation detail (users interact with the list, not individual nodes), this is widely accepted practice.

In production code, you'd make fields `private` and provide getters/setters for better encapsulation:
```cpp
// Production-style (more boilerplate, better encapsulation)
class Node {
    private:
        int data;
        Node* next;
    public:
        Node(int data) : data(data), next(nullptr) {}
        int getData() const { return data; }
        Node* getNext() const { return next; }
        void setNext(Node* n) { next = n; }
};
```

### Why `Node*` and not `Node`?
`Node* next` stores a **pointer** to the next node — i.e., its memory address. You cannot use `Node next` because that would try to embed a full `Node` object inside itself, which is an infinite size and won't compile.

### Overloaded Constructors
Having two constructors lets you create nodes either with or without immediately specifying the next node:
```cpp
Node* a = new Node(10);           // next = nullptr
Node* b = new Node(20, a);        // next points to a
```

---

## Stack vs Heap

Understanding *where* an object lives in memory is critical for linked lists.

### Stack Allocation
```cpp
Node y = Node(10);
```
- Object is created on the **stack**
- Automatically destroyed when it goes out of scope (e.g., when the function returns)
- **Not suitable for linked lists** — nodes need to outlive the scope they were created in

### Heap Allocation
```cpp
Node* y = new Node(10);
```
- `new` allocates memory on the **heap** and returns a **pointer** to it
- Object persists until you explicitly call `delete`
- Required for linked lists so nodes can be linked and accessed across functions

### Why `new` returns a pointer
`new` returns a memory address — the location of the newly created object on the heap. That's why the variable type must be `Node*` (pointer to Node), not `Node`. Doing `Node y = new Node(10)` is a type mismatch and won't compile.

### Memory Lifecycle Summary

| Location | Created by | Destroyed when |
|----------|-----------|----------------|
| Stack | `Node y = Node(10)` | Goes out of scope |
| Heap | `Node* y = new Node(10)` | You call `delete y` |

> **Note:** When the program terminates, the OS reclaims all memory (stack and heap). Memory leaks are a problem *during* execution — not after the program exits. Languages like Java and Python handle heap cleanup automatically using a **garbage collector**. C++ does not have one, so you must manage memory manually.

---

## Building a Linked List Manually

```cpp
Node* z = new Node(10);         // [10 | nullptr]
Node* y = new Node(20, z);      // [20 | *] --> [10 | nullptr]
Node* x = new Node(30, y);      // [30 | *] --> [20 | *] --> [10 | nullptr]
```

`x` is the **head** of the list — the entry point. To access nodes, you follow the chain of `next` pointers.

```cpp
cout << x->data;             // 30
cout << x->next->data;       // 20
cout << x->next->next->data; // 10
```

The `->` operator is used to access members of a class through a pointer. It's equivalent to `(*x).data`.

---

## Traversing a Linked List

Instead of hardcoding `x->next->next->...`, use a loop:

```cpp
Node* current = x;  // start at the head
while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;  // move to next node
}
cout << endl;
// Output: 30 20 10
```

Note: `Node* current = x` does **not** create a new node. It simply copies the memory address stored in `x` into `current`. Both variables point to the same node on the heap.

---

## Converting an Array to a Linked List

```cpp
int arr[] = {1, 2, 3, 4, 5};
int len = sizeof(arr) / sizeof(arr[0]);

Node* head = new Node(arr[0]);   // create head node
Node* previous = head;            // tracker for the last node added

for (int i = 1; i < len; i++) {
    Node* current = new Node(arr[i]);
    previous->next = current;     // link previous node to new node
    previous = current;           // advance previous
}
```

After this loop, `head` points to a linked list `1 -> 2 -> 3 -> 4 -> 5 -> nullptr`.

---

## Memory Management

C++ has no garbage collector, so every `new` must have a corresponding `delete`.

### Deleting a single node
```cpp
delete z;
```

### Deleting an entire linked list
You must delete nodes one by one. Be careful not to lose access to the rest of the list before saving a reference to the next node:

```cpp
Node* current = head;
while (current != nullptr) {
    Node* temp = current;         // save current before deleting
    current = current->next;      // advance BEFORE deleting
    delete temp;                  // now safe to delete
}
head = nullptr;  // good practice: avoid dangling pointer
```

> Never do `delete current; current = current->next;` — accessing `current->next` after deletion is **undefined behavior**.

---

## Common Linked List Operations

### Insert at the Front — O(1)
```cpp
Node* insertFront(Node* head, int val) {
    Node* newNode = new Node(val, head);
    return newNode;  // new node is the new head
}
```

### Insert at the Back — O(n)
```cpp
Node* insertBack(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
```

### Insert at a Position — O(n)
```cpp
// Inserts after position `pos` (0-indexed)
Node* insertAt(Node* head, int val, int pos) {
    if (pos == 0) return insertFront(head, val);
    Node* current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr) return head;  // pos out of range
    Node* newNode = new Node(val, current->next);
    current->next = newNode;
    return head;
}
```

### Delete the Head — O(1)
```cpp
Node* deleteFront(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
```

### Delete a Node by Value — O(n)
```cpp
Node* deleteByValue(Node* head, int val) {
    if (head == nullptr) return nullptr;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != val) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    return head;
}
```

### Search for a Value — O(n)
```cpp
bool search(Node* head, int val) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == val) return true;
        current = current->next;
    }
    return false;
}
```

### Get Length — O(n)
```cpp
int length(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
```

### Reverse a Linked List — O(n)
```cpp
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* nextTemp = current->next;  // save next
        current->next = prev;            // reverse the link
        prev = current;                  // advance prev
        current = nextTemp;              // advance current
    }
    return prev;  // prev is now the new head
}
```

---

## Types of Linked Lists

### Singly Linked List
Each node has one pointer (`next`). This is what we've built above.
```
[1] -> [2] -> [3] -> nullptr
```

### Doubly Linked List
Each node has two pointers: `next` and `prev`. Allows traversal in both directions.
```cpp
class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};
```
```
nullptr <- [1] <-> [2] <-> [3] -> nullptr
```

### Circular Linked List
The last node's `next` pointer points back to the head instead of `nullptr`.
```
[1] -> [2] -> [3] -> (back to [1])
```

---

## Time & Space Complexity

| Operation | Singly Linked List | Array |
|-----------|-------------------|-------|
| Access by index | O(n) | O(1) |
| Search | O(n) | O(n) |
| Insert at front | O(1) | O(n) |
| Insert at back | O(n) | O(1) amortized |
| Insert at position | O(n) | O(n) |
| Delete at front | O(1) | O(n) |
| Delete at back | O(n) | O(1) |
| Delete at position | O(n) | O(n) |
| Space | O(n) | O(n) |

**When to use a linked list over an array:**
- Frequent insertions/deletions at the front
- Size is unknown and changes frequently
- You don't need random access (e.g., `arr[i]`)

**When to use an array over a linked list:**
- You need fast random access
- Memory efficiency matters (no extra pointer overhead)
- Cache performance is important (arrays are contiguous in memory)

---

## Full Reference Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }

        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
};

// Utility: print the list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Utility: free all nodes
void deleteList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    // Manual construction
    Node* z = new Node(10);
    Node* y = new Node(20, z);
    Node* x = new Node(30, y);
    printList(x);   // 30 20 10
    deleteList(x);

    // From array
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    Node* head = new Node(arr[0]);
    Node* previous = head;
    for (int i = 1; i < len; i++) {
        Node* current = new Node(arr[i]);
        previous->next = current;
        previous = current;
    }

    printList(head);   // 1 2 3 4 5
    deleteList(head);

    return 0;
}
```