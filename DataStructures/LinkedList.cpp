#include "LinkedList.h"
#include <stdio.h>

/*
The function adds a new node with the given value to the start of the list. Head is passed as a pointer to a pointer, because the head itself changes.
Input: Node** head, int value
Output: None
*/
void addToHead(Node** head, int value)
{
    // Setting up the new node pointer.
    Node* newNode;

    // Allocating a new node and assigning its value.
    newNode = new Node;
    newNode->value = value;

    // The new node points to the old head.
    newNode->next = *head;

    // The new node becomes the new head.
    *head = newNode;
}

/*
The function removes the first node of the list and puts its value in *value. Returns 1 on success, or 0 if the list is empty. (a return value of -1 would not be clear, because -1 can be stored in the list)
Input: Node** head, int* value
Output: int (1 on success, 0 if empty)
*/
int removeFromHead(Node** head, int* value)
{
    // Setting up the temporary node pointer.
    Node* temp;

    // Checking if the list is empty.
    if (*head == NULL)
    {
        return 0;
    }

    // Storing the head reference and extracting its value.
    temp = *head;
    *value = temp->value;

    // The second node becomes the new head.
    *head = temp->next;

    // Freeing the removed node.
    delete temp;

    // Returning success.
    return 1;
}

/*
The function frees all the nodes of the list and sets the head to null.
Input: Node** head
Output: None
*/
void freeList(Node** head)
{
    // Setting up the temporary node pointer.
    Node* temp;

    // Iterating through the list and freeing each node one by one.
    while (*head != NULL)
    {
        temp = *head;
        *head = temp->next;
        delete temp;
    }
}