#include <stdio.h>

int ehPrimo(int numero)
{
    if (numero <= 1)
    {
        return 0;
    }

    for (int i = 2; (i * i) <= numero; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    while (1)
    {
        for (int i = 2;; i++)
        {
            if (ehPrimo(i))
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}