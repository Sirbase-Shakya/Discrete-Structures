#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 64
char *ptr;

void skipSpaces()
{
    while (*ptr && isspace(*ptr))
        ptr++;
}

int parseExpression(int p, int q);

int parseFactor(int p, int q)
{
    skipSpaces();

    if (*ptr == '!')
    {
        ptr++;
        return !parseFactor(p, q);
    }

    if (*ptr == '(')
    {
        ptr++;
        int value = parseExpression(p, q);

        skipSpaces();
        if (*ptr == ')')
            ptr++;

        return value;
    }

    if (*ptr == 'p')
    {
        ptr++;
        return p;
    }

    if (*ptr == 'q')
    {
        ptr++;
        return q;
    }

    if (*ptr == '1')
    {
        ptr++;
        return 1;
    }

    if (*ptr == '0')
    {
        ptr++;
        return 0;
    }

    return 0;
}

int parseTerm(int p, int q)
{
    int value = parseFactor(p, q);

    while (1)
    {
        skipSpaces();

        if (*ptr == '&')
        {
            ptr++;
            value = value && parseFactor(p, q);
        }
        else
        {
            break;
        }
    }

    return value;
}

int parseExpression(int p, int q)
{
    int value = parseTerm(p, q);

    while (1)
    {
        skipSpaces();

        if (*ptr == '|')
        {
            ptr++;
            value = value || parseTerm(p, q);
        }
        else
        {
            break;
        }
    }

    return value;
}

int eval(char *expr, int p, int q)
{
    ptr = expr;
    return parseExpression(p, q);
}

int main()
{
    char expr1[MAX], expr2[MAX];
    int p, q;
    int equivalent = 1;

    printf("Enter first Expression: ");
    fgets(expr1, sizeof(expr1), stdin);
    expr1[strcspn(expr1, "\n")] = '\0';

    printf("Enter second Expression: ");
    fgets(expr2, sizeof(expr2), stdin);
    expr2[strcspn(expr2, "\n")] = '\0';
    printf("p q exp1 exp2\n");
    for (p = 0; p <= 1; p++)
    {
        for (q = 0; q <= 1; q++)
        {
            int val1 = eval(expr1, p, q);
            int val2 = eval(expr2, p, q);
            printf("%d %d  %d    %d\n", p, q, val1, val2);
            if (val1 != val2)
                equivalent = 0;
        }
    }

    if (equivalent)
        printf("Logically Equivalent\n");
    else
        printf("Not Logically Equivalent\n");

    return 0;
}