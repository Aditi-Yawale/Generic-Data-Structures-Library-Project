# Generic Data Structures Library in C++

**Author:** Aditi Yawale  
**Language:** C++ (Template-based)  
**Category:** Data Structures

---

## 📌 Description

This project is a generic, object-oriented library in C++ that implements essential linear and non-linear data structures using templates. It is designed for reusability and type independence.

---

## 📚 Data Structures Implemented

- Singly Linked List
- Doubly Linked List
- Singly Circular Linked List
- Doubly Circular Linked List
- Stack (LIFO)
- Queue (FIFO)
- Binary Search Tree (BST)

---

## ⚙️ Features

- Generic (template-based) structure support
- Modular and reusable class-based design
- All core operations: Insert, Delete, Display, Count, Search, and Traversals (for BST)

---

## 💡 Sample Usage

### Singly Linked List

SinglyLL<int> sll;
sll.InsertFirst(10);
sll.InsertLast(20);
sll.Display(); 
// Output: | 10 |-> | 20 |-> NULL

### Binary Search Tree
BST<int> bst;
bst.Insert(50);
bst.Insert(30);
bst.Insert(70);
bst.DisplayInorder();  
// Output: 30 50 70

## 📥 Using as a Header Library
You can directly reuse this data structure library in your own C++ projects.

### Step 1: Include the file
Rename or copy Generic_Data_Structures_Library.cpp as GenericDS.h.

Add in your own code:

#include "GenericDS.h"

int main() {
    SinglyLL<float> list;
    list.InsertFirst(1.5);
    list.InsertLast(2.5);
    list.Display();

    BST<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(20);
    tree.DisplayInorder();

    return 0;
}

### Step 2: Compile as usual

g++ -o my_project main.cpp

No need to compile the data structure file separately as it will be compiled together with your main.cpp.
