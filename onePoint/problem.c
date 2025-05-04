#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int arr[] = {1, 0, 0, 2, 0, 3, 4};
    swap(arr + 1, arr + 3);
    swap(arr + 2, arr + 5);
    swap(arr + 3, arr + 6);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 1;
}