#include "Stack.h"
#include <stdio.h>

/*
The function initializes the stack by setting its head to null.
Input: Stack* s
Output: None
*/
void initStack(Stack* s)
{
    // Setting the stack head to null.
    s->head = NULL;
}

/*
The function cleans the stack by freeing all the nodes of the linked list.
Input: Stack* s
Output: None
*/
void cleanStack(Stack* s)
{
    // Freeing all nodes in the stack's linked list.
    freeList(&s->head);
}

/*
The function adds an element to the top of the stack. The top of the stack is the head of the list.
Input: Stack* s, unsigned int element
Output: None
*/
void push(Stack* s, unsigned int element)
{
    // Adding the element to the head of the list.
    addToHead(&s->head, (int)element);
}

/*
The function removes the element at the top of the stack and returns it. If the stack is empty, returns -1.
Input: Stack* s
Output: int (the popped element value, or -1 if empty)
*/
int pop(Stack* s)
{
    // Setting up the value variable.
    int value = 0;

    // Checking if the stack is empty by trying to remove from head.
    if (!removeFromHead(&s->head, &value))
    {
        return -1; // The stack was empty.
    }

    // Returning the popped value.
    return value;
}

/*
The function returns true if the stack has no elements, and false otherwise.
Input: Stack* s
Output: bool (true if empty, false otherwise)
*/
bool isEmpty(Stack* s)
{
    // Checking if the head of the stack is null.
    return s->head == NULL;
}

/*
The function returns true if the stack is full. The stack has no size limit, so it is never full.
Input: Stack* s
Output: bool (always false)
*/
bool isFull(Stack* s)
{
    // The stack has no size limit, so it is never full.
    return false;
}