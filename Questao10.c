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

void loop(int nCongruencias)
{
    int b;
    int m;

    int coprimo = 1;

    int valoresB[nCongruencias];
    int valoresM[nCongruencias];

    for (int i = 0; i < nCongruencias; i++)
    {
        printf("Digite o valor de B: ");
        scanf("%d", &b);

        valoresB[i] = b;

        printf("Digite o valor de M: ");
        scanf("%d", &m);

        valoresM[i] = m;
    }

    int resMdc = 1;

    for (int i = 0; i < nCongruencias; i++)
    {
        for (int j = i + 1; j < nCongruencias; j++)
        {
            resMdc *= mdc(valoresM[i], valoresM[j]);
        }
    }

    if (resMdc != 1)
    {
        coprimo = 0;
    }

    if (coprimo)
    {
        int M = 1;

        int divisaoM[nCongruencias];

        for (int i = 0; i < nCongruencias; i++)
        {
            M *= valoresM[i];
        }

        for (int i = 0; i < nCongruencias; i++)
        {
            divisaoM[i] = M / valoresM[i];
        }

        int resultados[nCongruencias];

        for (int i = 0; i < nCongruencias; i++)
        {
            resultados[i] = val(divisaoM[i], valoresM[i], 2, 1);
            resultados[i] = resultados[i] % valoresM[i];
        }

        int soma = 0;

        for (int i = 0; i < nCongruencias; i++)
        {
            soma += divisaoM[i] * resultados[i] * valoresB[i];
        }

        soma = soma % M;

        printf("RESULTADO UNICO = %d", soma);
    }
    else
    {
        printf("NAO EXISTE RESULTADO UNICO\n");
    }
}

int main()
{
    int nCongruencias;

    printf("Quantas congruencias lineares voce vai inserir?\n");
    scanf("%d", &nCongruencias);

    loop(nCongruencias);

    return 0;
}