#include <stdio.h>
#include <stdlib.h>

void addOne(int *a, int b)
{

    int arr[] = {1, 0, 0, 2, 0, 3, 4};
    for (int i = 0; i < n; i++)
    {
        *(arr + 1) += 1;
    }
    return arr;
}

int main(void)
{

    // int arr[] = {1, 0, 0, 2, 0, 3, 4};

    int *arr = (int *)malloc(sizeof(int) * 7);
    *(arr + 0) = 1;
    *(arr + 3) = 2;
    *(arr + 5) = 3;
    *(arr + 6) = 4;

    for (int i = 0; i < 7; i++)
    {
        printf("%d ,", *(arr + i));
    }

    free(arr);

    return 0;
}