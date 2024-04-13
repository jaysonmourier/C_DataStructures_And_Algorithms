/**
 * File: hash_map.c
 * Author: Jayson Mourier
 *
 * Description:
 * This file provides a simple implementation of a hash map using chaining for collision resolution. The hash map stores pairs of integers as keys and values. 
 * This implementation supports basic operations such as insertion, deletion, updating values, and retrieving values based on a key.
 *
 * The hash map uses an array of pointers to `struct HashMap` nodes, each of which represents an entry in the hash map. Collisions are handled by linking entries with the same hash index into a linked list.
 *
 * Key Functions:
 * - hash: Computes the hash index for a given key based on the size of the hash table.
 * - create_hashmap: Allocates memory for and initializes a new hash map node with a specified key and value.
 * - add: Adds a new key-value pair to the hash map or updates the value of an existing key. Handles collisions using chaining.
 * - get: Retrieves the value associated with a specified key from the hash map.
 * - destroy_map: Frees all memory associated with the hash map, including all dynamically allocated nodes and the hash table itself.
 *
 * This file also includes a main function to demonstrate the usage of the hash map by adding, updating, and retrieving entries, as well as properly cleaning up memory.
 *
 * Usage:
 * Compile and run this program to see how a simple hash map operates with basic integer keys and values. The program demonstrates the insertion of a key-value pair, updating an existing entry, retrieving an entry, and the cleanup process.
 */

#include <stdio.h>
#include <stdlib.h>

struct HashMap
{
    int key;
    int value;
    struct HashMap *next;
};

int hash(const int key, const int size)
{
    return abs(key) % size;
}

struct HashMap *create_hashmap(const int key, const int value)
{
    struct HashMap *HashMap = (struct HashMap *)malloc(sizeof(struct HashMap));

    if (HashMap == NULL)
    {
        return NULL;
    }

    HashMap->key = key;
    HashMap->value = value;
    HashMap->next = NULL;

    return HashMap;
}

int add(struct HashMap **table, const int size, const int key, const int value)
{
    int h = hash(key, size);
    struct HashMap *node = table[h];
    struct HashMap *prev;

    if (node == NULL)
    {
        table[h] = create_hashmap(key, value);

        if (table[h] == NULL)
            return 1;
        else
            return 0;
    }

    while (node != NULL)
    {
        if (node->key == key)
        {
            node->value = value;
            return 0;
        }

        prev = node;
        node = node->next;
    }

    prev->next = create_hashmap(key, value);
    return (prev->next == NULL) ? 1 : 0;
}

struct HashMap *get(struct HashMap **table, const int size, const int key)
{
    int h = hash(key, size);
    struct HashMap *node = table[h];
    while (node != NULL)
    {
        if (node->key == key)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void destroy_map(struct HashMap **table, const int size)
{
    if (table == NULL)
        return;

    for (int i = 0; i < size; ++i)
    {
        if (table[i] != NULL)
        {
            struct HashMap *node = table[i];
            while (node != NULL)
            {
                struct HashMap *tmp = node->next;
                free(node);
                node = tmp;
            }
        }
        table[i] = NULL;
    }
    free(table);
}

int main(void)
{
    const int size = 10;

    struct HashMap **table = (struct HashMap **)calloc(size * 2, sizeof(struct HashMap *));

    if (table == NULL)
    {
        return 1;
    }

    // add element
    if (add(table, size * 2, 3, 2) > 0)
    {
        fprintf(stderr, "Error: unabke to add the element.\n");
        destroy_map(table, size * 2);
        return 1;
    }

    // update element
    if (add(table, size * 2, 3, 7) > 0)
    {
        fprintf(stderr, "Error: unable to update the element.\n");
        destroy_map(table, size * 2);
        return 1;
    }

    // get element
    struct HashMap *elt = get(table, size * 2, 3);
    if (elt == NULL)
    {
        fprintf(stderr, "element not found\n");
    }
    else
    {
        fprintf(stdout, "value: %d\n", elt->value);
    }

    // free the memory
    destroy_map(table, size * 2);

    return 0;
}