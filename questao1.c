#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int primo(int x, int n)
{
    if (x == n)
    {
        printf("É PRIMO!");
        return 1;
    }

    if (x % n == 0 || x <= 1)
    {
        printf("NÃO É PRIMO");
        return 0;
    }

    return primo(x, n + 1);
}

int main()
{

    int x;

    scanf("%d", &x);

    primo(x, 2);

    return 0;
}