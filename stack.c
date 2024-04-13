/**
 * File: stack.c
 * Author: Jayson Mourier
 *
 * Description:
 * This file contains the implementation of a stack data structure that exclusively manages natural numbers (non-negative integers).
 * The stack is implemented using an array of unsigned integers to ensure that only natural numbers are stored.
 * This stack supports basic operations such as initialization, destruction, pushing, popping, and checking if it is full or empty.
 *
 * The stack ensures that no negative integers are accepted by using the unsigned int data type for storage.
 * Each function is robustly designed to handle edge cases, such as operations on empty or full stacks, as well as on NULL stack pointers.
 *
 * Functions provided:
 * - init_stack: Initializes and allocates memory for the stack.
 * - destroy_stack: Frees all allocated memory and properly handles null pointers.
 * - push: Adds a natural number to the stack if there is space available.
 * - pop: Removes and returns the top element of the stack if it is not empty.
 * - is_empty: Checks if the stack is empty.
 * - is_full: Checks if the stack is full.
 * - get_top: Retrieves the top element of the stack without removing it.
 * - print_stack: Prints the current content of the stack for debugging purposes.
 *
 * This implementation is designed for educational and practical purposes, providing a clear example of how to manage memory and error handling in a stack structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int size;
    int depth;
    unsigned int *data;
};

struct Stack *init_stack(const int size)
{
    if (size <= 0)
        return NULL;
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL)
        return NULL;

    stack->size = size;
    stack->depth = 0;
    stack->data = (unsigned *)calloc(size, sizeof(unsigned));
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

void destroy_stack(struct Stack *stack)
{
    if (stack != NULL)
    {
        if (stack->data != NULL)
        {
            free(stack->data);
        }
        free(stack);
    }
}

inline bool is_empty(struct Stack *restrict stack)
{
    if (stack == NULL)
        return true;
    return (stack->depth == 0) ? true : false;
}

inline bool is_full(struct Stack *restrict stack)
{
    if (stack == NULL)
        return false;
    return (stack->depth >= stack->size) ? true : false;
}

inline int get_top(struct Stack *restrict stack)
{
    if ((stack == NULL) || (is_empty(stack)))
    {
        fprintf(stderr, "the stack is either NULL or empty...\n");
        return -1;
    }

    return stack->data[stack->depth - 1];
}

void push(struct Stack *restrict stack, const unsigned int value)
{
    if (stack == NULL)
    {
        fprintf(stderr, "the stack is NULL...\n");
        return;
    }

    if (is_full(stack))
    {
        fprintf(stderr, "the stack is full...\n");
        return;
    }

    stack->data[stack->depth] = value;
    stack->depth += 1;
}

int pop(struct Stack *restrict stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "the stack is NULL...\n");
        return -1;
    }

    if (is_empty(stack))
    {
        fprintf(stderr, "the stack is empty...\n");
        return -1;
    }

    return stack->data[stack->depth-- - 1];
}

void print_stack(struct Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "the stack is NULL...\n");
        return;
    }

    if (is_empty(stack))
    {
        fprintf(stderr, "the stack is empty...\n");
        return;
    }

    fprintf(stdout, "--- STACK INFO ---\n");
    fprintf(stdout, ":::SIZE => %d\n", stack->size);
    fprintf(stdout, ":::DEPTH => %d\n", stack->depth);
    putchar('\n');
    for (int i = 0; i < stack->depth; ++i)
    {
        fprintf(stdout, "%d", stack->data[i]);

        if (i < stack->depth - 1)
        {
            fprintf(stdout, " -> ");
        }
    }

    putchar('\n');
}

int main(void)
{
    struct Stack *stack = init_stack(10);

    if (stack == NULL)
    {
        fprintf(stderr, "unable to allocate memory...\n");
    }

    push(stack, 22);
    push(stack, 5);
    push(stack, 12);
    push(stack, 2);
    push(stack, 63);

    fprintf(stdout, "pop -> %u\n", pop(stack));

    push(stack, 199);

    print_stack(stack);

    destroy_stack(stack);

    return 0;
}