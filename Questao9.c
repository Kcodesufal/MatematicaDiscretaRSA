#include <stdio.h>

int mdc(int primeiro, int segundo, int terceiro)
{
    if (primeiro < segundo)
    {
        int aux = primeiro;
        primeiro = segundo;
        segundo = aux;
    }

    if (primeiro < terceiro)
    {
        int aux = primeiro;
        primeiro = terceiro;
        terceiro = aux;
    }

    if (segundo < terceiro)
    {
        int aux = segundo;
        segundo = terceiro;
        terceiro = aux;
    }

    int mdc = 1;

    for (int i = 2; i < primeiro; i++)
    {
        while (primeiro % i == 0 && segundo % i == 0 && terceiro % i == 0)
        {
            mdc *= i;
            primeiro /= i;
            segundo /= i;
            terceiro /= i;
        }
    }

    return mdc;
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
    int bPrimeira, mPrimeira;

    printf("Digite o valor de B da PRIMEIRA congruencia: ");
    scanf("%d", &bPrimeira);
    printf("Digite o valor de M da PRIMEIRA congruencia: ");
    scanf("%d", &mPrimeira);

    int bSegunda, mSegunda;

    printf("Digite o valor de B da SEGUNDA congruencia: ");
    scanf("%d", &bSegunda);
    printf("Digite o valor de M da SEGUNDA congruencia: ");
    scanf("%d", &mSegunda);

    int bTerceira, mTerceira;

    printf("Digite o valor de B da TERCEIRA congruencia: ");
    scanf("%d", &bTerceira);
    printf("Digite o valor de M da TERCEIRA congruencia: ");
    scanf("%d", &mTerceira);

    int maxDiv = mdc(mPrimeira, mSegunda, mTerceira);

    if (maxDiv == 1)
    {
        int M = mPrimeira * mSegunda * mTerceira;

        int mUm = M / mPrimeira;
        int mDois = M / mSegunda;
        int mTres = M / mTerceira;

        int resUm = val(mUm, mPrimeira, 2, 1);
        int x1 = resUm * 1;

        int resCongruenciaUm = x1 % mPrimeira;

        int resDois = val(mDois, mSegunda, 2, 1);
        int x2 = resDois * 1;

        int resCongruenciaDois = x2 % mSegunda;

        int resTres = val(mTres, mTerceira, 2, 1);
        int x3 = resTres * 1;

        int resCongruenciaTres = x3 % mTerceira;

        int multiUm = mUm * resCongruenciaUm * bPrimeira;
        int multiDois = mDois * resCongruenciaDois * bSegunda;
        int multiTres = mTres * resCongruenciaTres * bTerceira;

        int resChines = multiUm + multiDois + multiTres;

        resChines = resChines % M;

        printf("RESULTADO UNICO = %d", resChines);
    }
    else
    {
        printf("NAO EXISTE");
    }

    return 0;
}