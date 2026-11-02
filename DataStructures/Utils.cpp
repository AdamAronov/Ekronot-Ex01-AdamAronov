#include <stdio.h>
#include "Utils.h"
#include "Stack.h"

/*
The function reverses the array nums (of size 'size'), using a stack.
Input: int* nums, unsigned int size
Output: None
*/
void reverse(int* nums, unsigned int size)
{
	// Declaring the stack structure variable.
	Stack s;

	// Declaring the loop index variable.
	unsigned int i;

	// Initializing the stack.
	initStack(&s);

	// Pushing all the numbers into the stack.
	for (i = 0; i < size; i++)
	{
		// Pushing the current array element onto the stack.
		push(&s, (unsigned int)nums[i]);
	}

	// Popping all the numbers back into the array.
	for (i = 0; i < size; i++)
	{
		// Popping the top element from the stack into the array.
		nums[i] = pop(&s);
	}

	// Cleaning the stack by freeing its nodes.
	cleanStack(&s);
}

/*
The function reads 10 integers from the user, and returns a new array with the numbers in reverse order.
Input: None
Output: int* (new dynamically allocated array)
*/
int* reverse10()
{
	// Allocating a dynamic array of 10 integers.
	int* nums = new int[10];

	// Declaring the loop index variable.
	int i;

	// Loop to read 10 integers from the user.
	for (i = 0; i < 10; i++)
	{
		// Checking if the input reading was successful.
		if (scanf("%d", &nums[i]) != 1)
		{
			// Skipping the invalid token so the next read can succeed.
			scanf("%*s");

			// Setting default value if reading failed.
			nums[i] = 0;
		}
	}

	// Reversing the array using the stack-based reverse function.
	reverse(nums, 10);

	// Returning the reversed array pointer.
	return nums;
}