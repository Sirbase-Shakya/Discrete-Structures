#include <stdio.h>
int search(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return 1;
        }
    }
    return 0;
}
void main()
{
    int arr[] = {1, 2, 3, 4, 5}, target = 69;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = search(arr, target, size);
    printf("%d\n", result);
}