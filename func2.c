#include <stdio.h>
int fact(int num)
{
    if (num == 0)
    {
        return 1;
    }
    if (num == 1)
    {
        return 1;
    }
    return num * fact(num - 1);
}
int fibo(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    return fibo(num - 1) + fibo(num - 2);
}
void main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The factorical is : %d\n", fact(num));
    printf("The fibonacci series is \n");
    for (int i = 0; i <= num; i++)
    {
        printf("%d ", fibo(i));
    }
}