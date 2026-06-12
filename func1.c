#include <stdio.h>
int ceil(float x)
{
    return x + 1;
}
int floor(float x)
{
    return x;
}
void main()
{
    float x = 1.01;
    printf("The ceil of %.2f is %d\n", x, ceil(x));
    printf("The floor of %.2f is %d\n", x, floor(x));
}