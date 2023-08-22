#include <stdio.h>

int mmc(int numeroUm, int numeroDois)
{
    int res = 1;

    for (int i = 2; i <= numeroUm; i++)
    {
        while (numeroUm % i == 0 && numeroDois % i == 0)
        {
            numeroUm = numeroUm / i;
            numeroDois = numeroDois / i;
            res *= i;
        }

        while (numeroUm % i == 0)
        {
            numeroUm = numeroUm / i;
            res *= i;
        }

        while (numeroDois % i == 0)
        {
            numeroDois = numeroDois / i;
            res *= i;
        }
    }

    return res;
}

int mdc(int numeroUm, int numeroDois)
{
    int res = 1;

    for (int i = 2; i <= numeroUm; i++)
    {
        if (numeroUm % i == 0 && numeroDois % i == 0)
        {
            res *= i;
            numeroUm /= i;
            numeroDois /= i;

            if (i > numeroUm)
            {
                break;
            }
        }
    }

    return res;
}

int main()
{
    int numeroUm, numeroDois;

    scanf("%d%d", &numeroUm, &numeroDois);

    int salvarUm = numeroUm;
    int salvaDois = numeroDois;

    if (numeroDois > numeroUm)
    {
        int aux = numeroUm;
        numeroUm = numeroDois;
        numeroDois = aux;
    }

    int multiplo = mmc(numeroUm, numeroDois);
    int divisor = mdc(numeroUm, numeroDois);

    printf("MMC(%d,%d) = %d\n", salvarUm, salvaDois, multiplo);
    printf("MDC(%d,%d) = %d\n", salvarUm, salvaDois, divisor);
}