#include <stdio.h>

void main()
{
    int n;
    float x[20], y[20], term, xp, yp = 0;
    printf("Enter no. of data points :");
    scanf("%d", &n);
    printf("Enter data points:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }
    printf("Enter term of x for y:");
    scanf("%f", &xp);
    for (int i = 0; i < n; i++)
    {
        float term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
                term = term * ((xp - x[j]) / (x[i] - x[j]));
        }
        yp += term;
    }
    printf("The estimated term is %f\n", yp);
}