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

void destroy_linked_list(struct LinkedList *cell)
{
    struct LinkedList *tmp = NULL;
    while (cell != NULL)
    {
        tmp = cell->next;
        free(cell);
        cell = tmp;
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