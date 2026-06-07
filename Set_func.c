#include <stdio.h>
#include <conio.h>
int set_Union[] = {0}, set_Intersection[] = {0}, set_difference_A[] = {0}, set_difference_B[] = {0};
int isPresent(int element, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}
int Intersection(int set_A[], int set_B[], int size_A, int size_B)
{
    int count = 0;
    for (int i = 0; i < size_A; i++)
    {
        if (isPresent(set_A[i], set_B, size_B))
        {
            set_Intersection[count] = set_A[i];
            count++;
        }
    }
    return count;
}
int Union(int set_A[], int set_B[], int size_A, int size_B)
{
    int i, count = 0;
    for (i = 0; i < size_A; i++)
    {
        set_Union[count] = set_A[i];
        count++;
    }
    for (int i = 0; i < size_B; i++)
    {
        if (!isPresent(set_B[i], set_Union, count))
        {
            set_Union[count] = set_B[i];
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (set_Union[i] > set_Union[j])
            {
                int temp = set_Union[i];
                set_Union[i] = set_Union[j];
                set_Union[j] = temp;
            }
        }
    }
    return count;
}
int set_diff_A(int set_A[], int set_B[], int size_A, int size_B)
{
    int count = 0;
    for (int i = 0; i < size_A; i++)
    {
        if (!isPresent(set_A[i], set_B, size_B))
        {
            set_difference_A[count] = set_A[i];
            count++;
        }
    }
    return count;
}
int set_diff_B(int set_A[], int set_B[], int size_A, int size_B)
{
    int count = 0;
    for (int i = 0; i < size_B; i++)
    {
        if (!isPresent(set_B[i], set_A, size_A))
        {
            set_difference_B[count] = set_B[i];
            count++;
        }
    }
    return count;
}
int symm_diff(int set_A[], int set_B[], int size_A, int size_B)
{
    int size_AB = set_diff_A(set_A, set_B, size_A, size_B);
    int size_BA = set_diff_B(set_A, set_B, size_A, size_B);
    int count = Union(set_difference_A, set_difference_B, size_AB, size_BA);
    return count;
}
int Cartesian(int set_A[], int set_B[], int size_A, int size_B)
{
    for (int i = 0; i < size_A; i++)
    {
        for (int j = 0; j < size_B; j++)
        {
            printf("(%d,%d), ", set_A[i], set_B[j]);
        }
    }
    printf("}");
    return 0;
}
void main()
{
    int set_A[] = {5, 8, 9, 67}, set_B[] = {5, 67, 69, 101, 911};
    int size_A = sizeof(set_A) / sizeof(set_A[0]), size_B = sizeof(set_B) / sizeof(set_B[0]);
    int choice;
    char check;
    do
    {
        printf("\n********Set Operations********\n");
        printf("1. Union\n2. Intersection\n3. Set Difference(A-B)\n4. Set Difference(B-A)\n5. Cartesian Product\n6. Symmetric Difference\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int max = Union(set_A, set_B, size_A, size_B);
            printf("The union of the sets is:\n { ");
            for (int i = 0; i < max; i++)
            {
                printf("%d, ", set_Union[i]);
            }
            printf("}");
            break;
        }
        case 2:
        {
            int max = Intersection(set_A, set_B, size_A, size_B);
            printf("The intersection of the sets is:\n { ");
            for (int i = 0; i < max; i++)
            {
                printf("%d, ", set_Intersection[i]);
            }
            printf(" }");
            break;
        }
        case 3:
        {
            int max = set_diff_A(set_A, set_B, size_A, size_B);
            printf("The difference of the sets is:\n { ");
            for (int i = 0; i < max; i++)
            {
                printf("%d, ", set_difference_A[i]);
            }
            printf("}");
            break;
        }
        case 4:
        {
            int max = set_diff_B(set_A, set_B, size_A, size_B);
            printf("The difference of the sets is:\n { ");
            for (int i = 0; i < max; i++)
            {
                printf("%d, ", set_difference_B[i]);
            }
            printf("}");
            break;
        }
        case 5:
        {
            printf("The Cartesian Product of the sets is:\n { ");
            int max = Cartesian(set_A, set_B, size_A, size_B);
            break;
        }
        case 6:
        {
            int max = symm_diff(set_A, set_B, size_A, size_B);
            printf("The symmetric difference of the sets is:\n { ");
            for (int i = 0; i < max; i++)
            {
                printf("%d, ", set_Union[i]);
            }
            printf("}");
            break;
        }

        default:
        {
            printf("Error! Option not available");
        }
        }
        printf("\nDo u want to perform another operation? (y/n)");
        check = getch();
    } while (check != 'n');
}