#include "Queue.h"
#include <stdio.h>

/*
The function initializes the queue by allocating an array of 'size' places and setting the queue to be empty.
Input: Queue* q, unsigned int size
Output: None
*/
void initQueue(Queue* q, unsigned int size)
{
    // Allocating the elements array with the specified capacity.
    q->elements = new unsigned int[size];

    // Setting the queue capacity, count, and head index.
    q->capacity = size;
    q->count = 0;
    q->head = 0;
}

/*
The function cleans the queue by freeing the array and resetting all fields.
Input: Queue* q
Output: None
*/
void cleanQueue(Queue* q)
{
    // Freeing the dynamically allocated elements array.
    delete[] q->elements;

    // Resetting the elements pointer, capacity, count, and head index.
    q->elements = NULL;
    q->capacity = 0;
    q->count = 0;
    q->head = 0;
}

/*
The function adds a new value to the end of the queue. If the queue is full, nothing happens.
Input: Queue* q, unsigned int newValue
Output: None
*/
void enqueue(Queue* q, unsigned int newValue)
{
    // Setting up the tail variable.
    unsigned int tail;

    // Checking if the queue is full.
    if (isFull(q))
    {
        return;
    }

    // Calculating the tail position where the new value will be placed.
    // (the % makes us go back to the start of the array when we reach its end)
    tail = (q->head + q->count) % q->capacity;

    // Storing the new value and incrementing the count.
    q->elements[tail] = newValue;
    q->count++;
}

/*
The function removes the element at the front of the queue and returns it. If the queue is empty, returns -1.
Input: Queue* q
Output: int (the removed value or -1 if empty)
*/
int dequeue(Queue* q)
{
    // Setting up the value variable.
    int value;

    // Checking if the queue is empty.
    if (isEmpty(q))
    {
        return -1;
    }

    // Retrieving the value from the front of the queue.
    value = (int)q->elements[q->head];

    // Moving the head index to the next element and decrementing the count.
    q->head = (q->head + 1) % q->capacity;
    q->count--;

    // Returning the dequeued value.
    return value;
}

/*
The function returns true if the queue has no elements.
Input: Queue* s
Output: bool (true if empty, false otherwise)
*/
bool isEmpty(Queue* s)
{
    // Checking if the count of elements is zero.
    return s->count == 0;
}

/*
The function returns true if the queue has no free places left.
Input: Queue* s
Output: bool (true if full, false otherwise)
*/
bool isFull(Queue* s)
{
    // Checking if the count of elements equals the capacity.
    return s->count == s->capacity;
}