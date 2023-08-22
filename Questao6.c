#include <stdio.h>

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

int val(int primeiro, int segundo, int y, int um)
{
    int x = (um - segundo * y);
    if (x % primeiro == 0)
    {
        printf("%d * s = %d * %d\n", primeiro, primeiro, x / primeiro);
        printf("%d * t = %d * %d\n", segundo, segundo, y);
        printf("s = %d\n", x / primeiro);
        printf("t = %d\n", y);
        return x;
    }
    else if (x % primeiro != 0 && y > 0)
    {
        return val(primeiro, segundo, y * -1, um);
    }

    return val(primeiro, segundo, y * (-1) + 1, um);
}

void bora(int primeiro, int segundo, int y, int um)
{
    int d = val(primeiro, segundo, y, um);
    if (d > 0 && d < primeiro)
    {
        return;
    }
}

int main()
{
    int x, y;
    printf("Digite o valor do primeiro algarismo: ");
    scanf("%d", &x);
    printf("Digite o valor do segundo algarismo: ");
    scanf("%d", &y);
    bora(x, y, 2, mdc(x, y));
    return 0;
}