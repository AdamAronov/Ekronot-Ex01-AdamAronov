#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

// Setting up the structure: A positive-integer value stack, with no size limit.
typedef struct Stack
{
    Node* head;             // Head of the linked list, this is the top of the stack.
} Stack;

// Setting up the functions.
void initStack(Stack* s);
void cleanStack(Stack* s);
void push(Stack* s, unsigned int element);
int pop(Stack* s);          // Return -1 if stack is empty.
bool isEmpty(Stack* s);
bool isFull(Stack* s);

#endif /* STACK_H */