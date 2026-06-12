#include <stdio.h>
#include <math.h>
void main()
{
    int a, r, n;
    printf("Enter the first element and common difference and no. of terms : ");
    scanf("%d%d%d", &a, &r, &n);
    printf("AP seires is \n");
    for (int i = 1; i <= n; i++)
    {
        int terms = a + (i - 1) * r;
        printf("%d ", terms);
    }
    printf("\nThe GP is \n");
    for (int i = 1; i <= n; i++)
    {
        int terms = (int)a * pow(r, i - 1);
        printf("%d ", terms);
    }
}