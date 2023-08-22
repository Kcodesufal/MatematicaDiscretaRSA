#include <stdio.h>

int ehPrimo(int n)
{
    int primo = 1;
    if (n < 2)
    {
        primo = 0;
    }
    else if (n > 2)
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                primo = 0;
                break;
            }
        }
    }
    return primo;
}

void decompor(int n)
{
    int teste = 2;
    int tamanho = 1;
    int temporaria = n;

    if (ehPrimo(temporaria) == 1)
    {
        tamanho = 1;
    }
    else
    {
        while (ehPrimo(temporaria) == 0)
        {
            if (ehPrimo(teste) == 1)
            {
                if (temporaria % teste == 0)
                {
                    temporaria = temporaria / teste;
                    tamanho++;
                }
                else
                {
                    teste++;
                }
            }
            else
            {
                teste++;
            }
        }
    }

    int lista[tamanho];
    int indice = 0;
    teste = 2;

    if (ehPrimo(n) == 1)
    {
        lista[0] = n;
    }
    else
    {
        while (ehPrimo(n) == 0)
        {
            if (ehPrimo(teste) == 1)
            {
                if (n % teste == 0)
                {
                    lista[indice] = teste;
                    n = n / teste;
                    lista[indice + 1] = n;
                    indice++;
                }
                else
                {
                    teste++;
                }
            }
            else
            {
                teste++;
            }
        }
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\n", lista[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    decompor(n);
    return 0;
}