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