#include <stdio.h>

int mdc(int primeiro, int segundo)
{
    if (segundo == 0)
    {
        return primeiro;
    }

    return mdc(segundo, primeiro % segundo);
}

int val(int primeiro, int segundo, int y, int um)
{
    int x = (um - segundo * y);
    if (x % primeiro == 0)
    {
        int divisaoXPrimeiro = x / primeiro;

        while (divisaoXPrimeiro < 0)
        {
            divisaoXPrimeiro += segundo;
        }

        return divisaoXPrimeiro;
    }
    else if (x % primeiro != 0 && y > 0)
    {
        return val(primeiro, segundo, y * -1, um);
    }

    return val(primeiro, segundo, y * (-1) + 1, um);
}

int main()
{
    int x, y;
    printf("Digite o valor do primeiro algarismo: ");
    scanf("%d", &x);
    printf("Digite o valor do segundo algarismo: ");
    scanf("%d", &y);

    int coprimo = mdc(x, y);

    if (coprimo != 1 || y <= 1)
    {
        printf("Não existe inverso de %d mod %d\n", x, y);
    }
    else
    {
        int res = val(x, y, 2, 1);
        printf("Inverso %d mod %d = %d\n", x, y, res);
    }

    return 0;
}