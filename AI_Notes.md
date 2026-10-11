# Double Linked List

A doubly linked list is a type of linked list where each node stores:
- data
- a pointer to the next node
- a pointer to the previous node

Unlike a singly linked list, which can only move forward, a doubly linked list can move both forward and backward.

## Structure

Each node looks like this conceptually:

```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;
};
```

## Why use it?

- Traversal can be done in both directions.
- Easier to delete a node if you know its pointer.
- Easier to insert before or after a node.

## Example

```cpp
head -> [ data | next | prev ] <-> [ data | next | prev ] <-> [ data | next | prev ] -> tail
```

The `next` pointer points to the next node, and the `prev` pointer points to the previous node.

## Key difference from singly linked list

- Singly linked list: only `next` pointer
- Doubly linked list: both `next` and `prev` pointers

This makes doubly linked lists more flexible, but they use more memory because each node stores an extra pointer.
