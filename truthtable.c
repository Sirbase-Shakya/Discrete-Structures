#include <stdio.h>
#define MAX 16
void negation_table()
{
    printf("P\tP'\n");
    for (int i = 0; i <= 1; i++)
    {
        printf("%d\t%d\n", i, !i);
    }
}
void conjunction_table()
{
    printf("P\tQ\tY\n");
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf("%d\t%d\t%d\n", i, j, i & j);
        }
    }
}
void disjunction_table()
{
    printf("P\tQ\tY\n");
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf("%d\t%d\t%d\n", i, j, i | j);
        }
    }
}
void implication_table()
{
    printf("P\tQ\tY\n");
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf("%d\t%d\t%d\n", i, j, !(i > j));
        }
    }
}
void bimplication_table()
{
    printf("P\tQ\tY\n");
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf("%d\t%d\t%d\n", i, j, !(i ^ j));
        }
    }
}
int main()
{
    int set_A[MAX], set_B[MAX];
    int choice;
    char check;
    do
    {
        printf("******Enter Operations to Perform******\n");
        printf("1. Negation\n2. Conjunction\n3. Disjunction\n4. Implication\n5. Bi-implication\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            negation_table();
            break;
        }
        case 2:
        {
            conjunction_table();
            break;
        }
        case 3:
        {
            disjunction_table();
            break;
        }
        case 4:
        {
            implication_table();
            break;
        }
        case 5:
        {
            bimplication_table();
            break;
        }
        default:
        {
            printf("Error!!! Option Not Available");
        }
        }
        printf("Do you want to perform another operation?(y/n)");
        scanf(" %c", &check);
    } while (check == 'y');
    return 0;
}
