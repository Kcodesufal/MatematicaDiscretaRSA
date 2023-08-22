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
    int a, b, m;

    printf("Digite o valor do primeiro algarismo: ");
    scanf("%d", &a);
    printf("Digite o valor do segundo algarismo: ");
    scanf("%d", &b);
    printf("Digite o valor do terceiro algarismo: ");
    scanf("%d", &m);

    int coprimo = mdc(a, m);

    if (coprimo != 1 || b <= 1)
    {

        if (b % coprimo != 0)
        {
            printf("Nao existe solucao para essa congruencia linear.\n");
        }
        else
        {
            int novoA = a / coprimo;
            int novoB = b / coprimo;
            int novoM = m / coprimo;

            int res = val(novoA, novoM, 2, 1);

            int x = res * novoB;

            int resCongruencia = x % novoM;

            printf("A Congruencia Linear tem %d resultados possiveis\n", coprimo);

            int aux = 1;

            for (int i = 0; i < coprimo; i++)
            {
                printf("Resultado %d = %d\n", aux, resCongruencia);
                resCongruencia += novoM;
                aux += 1;
            }
        }
    }
    else
    {
        int res = val(a, m, 2, 1);
        int x = res * b;

        int resCongruencia = x % m;

        printf("Resultado = %d\n", resCongruencia);
    }

    return 0;
}