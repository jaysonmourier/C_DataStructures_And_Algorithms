/**
 * File: linked_list.c
 * Author: Jayson Mourier
 *
 * Description:
 * This file contains the implementation of a singly linked list in C. It includes functions for creating nodes, appending elements,
 * printing the list, and freeing the allocated memory. This implementation is aimed at demonstrating fundamental operations
 * on linked lists such as insertion at the end, traversal, and deletion of the entire list.
 *
 * Functions:
 * - create_cell: Allocates and returns a new node with a given value. Returns NULL if memory allocation fails.
 * - tail: Returns the last node of the linked list. Used internally to find the end of the list for appending new elements.
 * - add: Appends a new element to the end of the list. If the list is empty, it creates a new head node. Returns the head of the list.
 * - print_linked_list: Prints all elements of the list to standard output in a formatted manner, showing the linkage between nodes.
 * - destroy_linked_list: Frees all nodes of the linked list to avoid memory leaks, effectively destroying the list.
 *
 * The main function demonstrates how to use these functions by creating a linked list, appending several elements, printing the list,
 * and finally destroying the list to free the allocated memory.
 *
 * Usage:
 * This implementation can be used as a learning tool for understanding how linked lists work in C. It can be extended to include
 * more complex operations such as insertion at specific positions, deletion of nodes, and searching for elements.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkedList
{
    int value;
    struct LinkedList *next;
};

struct LinkedList *create_cell(const int value)
{
    struct LinkedList *cell = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if (cell == NULL)
    {
        return NULL;
    }
    cell->value = value;
    cell->next = NULL;
    return cell;
}

inline struct LinkedList *tail(struct LinkedList *head)
{
    if (head == NULL)
        return NULL;
    struct LinkedList *cell = head;
    while (cell->next != NULL)
    {
        cell = cell->next;
    }
    return cell;
}

/**
 * Adds a new element to the end of a linked list.
 *
 * This function handles appending a new element to a linked list. If the list is initially empty
 * (head is NULL), a new node is created and becomes the new head of the list. If the list already
 * has elements, the new element is added to the end.
 *
 * Parameters:
 *   - head : A pointer to the first node of the linked list. Can be NULL
 *            if the list is empty.
 *   - value : The value to be added to the list.
 *
 * Returns:
 *   - A pointer to the head of the list. If the list was initially empty and
 *     the creation of the new node is successful, a pointer to this new node is
 *     returned. If a memory allocation error occurs, NULL is returned and an error
 *     message is printed to stderr.
 *
 * Example of use:
 *   struct LinkedList *list = NULL;  // Create an empty list.
 *   list = add(list, 10);            // Add an element to the list.
 *   list = add(list, 20);            // Add a second element to the list.
 */
struct LinkedList *add(struct LinkedList *head, const int value)
{
    if (head == NULL)
    {
        head = create_cell(value);

        return (head == NULL) ? NULL : head;
    }

    struct LinkedList *last_node = tail(head);

    last_node->next = create_cell(value);

    if (last_node->next == NULL)
    {
        fprintf(stderr, "unable to allocate memory...\n");
        return NULL;
    }

    return head;
}

void destroy_linked_list(struct LinkedList *head)
{
    struct LinkedList *tmp = NULL;
    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

void print_linked_list(struct LinkedList *head)
{
    struct LinkedList *p = head;
    while (p != NULL)
    {
        fprintf(stdout, "%d", p->value);
        if (p->next != NULL)
        {
            fprintf(stdout, " -> ");
        }
        p = p->next;
    }
    putchar('\n');
}

int main(void)
{
    struct LinkedList *head = NULL;

    head = add(head, 12);
    head = add(head, 23);
    head = add(head, 16);
    head = add(head, 8);

    print_linked_list(head);

    destroy_linked_list(head);
    return 0;
}