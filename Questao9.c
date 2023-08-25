#include <stdio.h>

int euclide(int um, int dois)
{
    if(dois == 0)
    {
        return um;
    }

    return euclide(dois, um % dois);
}

int mdc(int primeiro, int segundo, int terceiro)
{
    int resultado = euclide(primeiro, segundo);

    resultado = euclide(resultado, terceiro);

    return resultado;
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
    int aPrimeira, bPrimeira, mPrimeira;

    printf("Digite o valor de A da PRIMEIRA congruencia: \n");
    scanf("%d", &aPrimeira);
    printf("Digite o valor de B da PRIMEIRA congruencia: \n");
    scanf("%d", &bPrimeira);
    printf("Digite o valor de M da PRIMEIRA congruencia: \n");
    scanf("%d", &mPrimeira);

    int aSegunda, bSegunda, mSegunda;

    printf("Digite o valor de A da SEGUNDA congruencia: \n");
    scanf("%d", &aSegunda);
    printf("Digite o valor de B da SEGUNDA congruencia: \n");
    scanf("%d", &bSegunda);
    printf("Digite o valor de M da SEGUNDA congruencia: \n");
    scanf("%d", &mSegunda);

    int aTerceira, bTerceira, mTerceira;

    printf("Digite o valor de A da TERCEIRA congruencia: \n");
    scanf("%d", &aTerceira);
    printf("Digite o valor de B da TERCEIRA congruencia: \n");
    scanf("%d", &bTerceira);
    printf("Digite o valor de M da TERCEIRA congruencia: \n");
    scanf("%d", &mTerceira);

    int maxDiv = mdc(mPrimeira, mSegunda, mTerceira);

    if (maxDiv == 1 && euclide(aPrimeira, mPrimeira) == 1 && euclide(aSegunda, mSegunda) == 1 && euclide(aTerceira, mTerceira) == 1)
    {
        int inversoPrimeira = val(aPrimeira, mPrimeira, 2, 1) % mPrimeira;
        int inversoSegunda = val(aSegunda, mSegunda, 2, 1) % mSegunda;
        int inversoTerceira =   val(aTerceira, mTerceira, 2, 1) % mTerceira;

        bPrimeira = bPrimeira * inversoPrimeira;
        bSegunda = bSegunda * inversoSegunda;
        bTerceira = bTerceira * inversoTerceira;

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

        printf("RESULTADO UNICO = %d\n", resChines);
    }
    else
    {
        printf("NAO EXISTE POIS OS VALORES NAO SAO COPRIMOS ENTRE SI\n");
    }

    return 0;
}