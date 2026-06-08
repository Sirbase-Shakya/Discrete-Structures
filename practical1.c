#include <stdio.h>
int sum_set(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    sum += arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            sum += arr[i];
        }
    }
    return sum;
}
void main()
{
    int arr[] = {5, 2, 4, 1, 3, 2, 1, 3, 4}, size = sizeof(arr) / sizeof(arr[0]);
    int result = sum_set(arr, size);
    printf("The sum of set is : %d\n", result);
}