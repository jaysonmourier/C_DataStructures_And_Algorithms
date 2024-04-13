/**
 * File: bubble_sort.c
 * Author: Jayson Mourier
 *
 * Description:
 * This file provides a simple implementation of the bubble sort algorithm to sort an array of integers in ascending order.
 * The array elements are initialized with random values, constrained by a maximum value defined by MAX_VALUE.
 * This implementation is specifically designed to demonstrate sorting algorithms in a straightforward and educational manner.
 *
 * Key features:
 * - sort: Sorts the array using the bubble sort algorithm. This function iterates over the array, comparing adjacent elements and swapping them if they are in the wrong order. The sorting process stops early if no swaps are needed during a full pass through the array, indicating the array is already sorted.
 * - print_table: Outputs the content of the array to the standard output, providing a way to visualize the array's state before and after sorting.
 * - fill_table: Fills the array with random integers ranging from 0 to MAX_VALUE-1. This function uses the C standard library's rand function, seeded with the current time to ensure different outputs on each execution.
 *
 * The program demonstrates the usage of these functions by sorting a statically sized array of 64 integers. It provides an example of basic array manipulations, random number generation, and sorting algorithms in C.
 *
 * Usage:
 * Compile and run this program to see how an unsorted array of random numbers is sorted into ascending order. The size of the array and the maximum random number value can be adjusted by changing the size variable and MAX_VALUE definition, respectively.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 150

static inline void sort(int *restrict table, const int size)
{
    if (table == NULL)
        return;
    int sorted, tmp;
    for (int i = size - 1; i > 0; --i)
    {
        sorted = 1;
        for (int j = 0; j < i; ++j)
        {
            if (table[j + 1] < table[j])
            {
                tmp = table[j + 1];
                table[j + 1] = table[j];
                table[j] = tmp;
                sorted = 0;
            }
        }
        if (sorted > 0)
            break;
    }
}

void print_table(int *restrict table, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        fprintf(stdout, "%d ", table[i]);
    }
    printf("\n");
}

/*
 * fill table with random numbers
 */
void fill_table(int *restrict table, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        table[i] = rand() % MAX_VALUE;
    }
}

int main(void)
{
    srand(time(NULL));

    const int size = 64;

    int table[size];

    fill_table(table, size);

    print_table(table, size);

    sort(table, size);

    print_table(table, size);

    return 0;
}