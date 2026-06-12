#include <stdio.h>
void main()
{
    int x, n, f = 1;
    printf("Enter a number and its power: ");
    scanf("%d%d", &x, &n);
    for (int i = 1; i <= n; i++)
    {
        f *= x;
    }
    printf("The function returned %d\n", f);
}