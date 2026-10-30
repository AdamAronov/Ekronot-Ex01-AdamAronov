#ifndef QUEUE_H
#define QUEUE_H

// Setting up the structure: A queue containing positive integer values.
typedef struct Queue
{
    unsigned int* elements; // Dynamically allocated circular array.
    unsigned int capacity;  // Maximum number of elements.
    unsigned int count;     // Current number of elements.
    unsigned int head;      // Index of the front element.
} Queue;

// Setting up the functions.
void initQueue(Queue* q, unsigned int size);
void cleanQueue(Queue* q);
void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q);      // Return element in top of queue, or -1 if empty.
bool isEmpty(Queue* q);
bool isFull(Queue* q);

#endif /* QUEUE_H */