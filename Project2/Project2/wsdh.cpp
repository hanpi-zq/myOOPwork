#include <stdio.h>
#include <string.h>
#include <math.h>
void print(int x)
{
    if (x <= 9)
        printf("%d", x);
    else
        printf("%c", x - 10 + 'A');
}
void change(int c, int b)
{
    if (c)
    {
        change(c / b, b);
        print(c % b);
    }
}
void f(int a, char n[], int b)
{
    int k = strlen(n);
    int x[100] = { 0 };
    int i = 0, j = 0, c = 0;
    for (i = 0; i < k; i++)
    {
        if ((n[i] >= 'a') && (n[i] <= 'f'))
        {
            x[i] = n[i] - 'a' + 10; continue;
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            x[i] = n[i] - 'A' + 10; continue;
        }
        else if (n[i] >= '0' && n[i] <= '9')
        {
            x[i] = (int)(n[i] - '0'); continue;
        }
    }
    for (j = k - 1; j >= 0; j--)
    {
        c += x[j] * pow(a, k - 1 - j);
    }
    change(c, b);
}

int main()
{
    int a, b;
    char n[100];
    scanf_s("%d %s %d", &a, &n, &b);
    f(a, n, b);
    return 0;
}
