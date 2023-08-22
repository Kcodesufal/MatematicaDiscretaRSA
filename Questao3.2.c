#include <stdio.h>

void decompor(int numero)
{
    for (int i = 2; i <= numero; i++)
    {
        while (numero % i == 0)
        {
            printf("%d\n", i);
            numero = numero / i;
        }
    }
}

int main()
{
    int numero;

    scanf("%d", &numero);

    decompor(numero);

    return 0;
}