#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return mdc(y, x % y);
    }
}

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);

    printf("%d", mdc(x, y));

    return 0;
}