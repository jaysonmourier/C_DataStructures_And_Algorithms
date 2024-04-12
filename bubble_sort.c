#include <stdio.h>

void sort(int *table, int size)
{
    int sorted = 1;
    for (int i = size - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (table[j + 1] < table[j])
            {
                int tmp = table[j + 1];
                table[j + 1] = table[j];
                table[j] = tmp;
                sorted = 0;
            }
        }
        if (sorted > 0)
            break;
    }
}

void print_table(int *table, int size)
{
    for (int i = 0; i < size; ++i)
    {
        fprintf(stdout, "%d ", table[i]);
    }
    printf("\n");
}

int main(void)
{
    int table[10] = {
        2, 4, 3, 2, 8, 6, 3, 12, 9, 1};

    print_table(table, 10);

    sort(table, 10);

    print_table(table, 10);

    return 0;
}