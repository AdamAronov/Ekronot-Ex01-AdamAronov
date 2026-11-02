#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Setting up the structure: A node in a linked list of positive and negative integers.
typedef struct Node
{
	int value;              // The data that is stored in the node.
	struct Node* next;      // A pointer to the next node (NULL for the last node).
} Node;

// Setting up the functions.
void addToHead(Node** head, int value);
int removeFromHead(Node** head, int* value);
void freeList(Node** head);

#endif /* LINKEDLIST_H */