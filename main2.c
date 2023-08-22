#include <stdio.h>

void mdc_euclides(int a, int b)
{
    if (b == 0)
    {
        printf("%d\n", a);
    }
    else
    {
        mdc_euclides(b, a % b);
    }
}

void decompor_fatores_primos(int n)
{
    int flag = 0;

    for (int i = 2; i <= n; ++i)
    {
        if (ehprimo(i) == 1)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                {
                    n = n / i;
                }

                if (flag == 0)
                    flag = 1;

                flag == 0 ? printf("%d", i) : printf(" %d", i);
            }
        }
    }
    printf("\n");
}

void primossequencial(int n)
{
    int flag = 0;

    for (int i = 2; i <= n; ++i)
    {
        if (ehprimo(i) == 1 && flag == 1)
        {
            printf(" %d", i);
        }
        if (ehprimo(i) == 1 && flag == 0)
        {
            printf("%d", i);
            flag = 1;
        }
    }
    printf("\n");
}

int ehprimo(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void opcoes()
{
    printf("Escolha uma op��o:\n--------------------------------------\n");
    printf("1 - Verificar se um n�mero � primo.\n");
    printf("2 - Listar primos at� X n�mero.\n");
    printf("3 - Listar todos fatores primos unicos de um n�mero.\n");
    printf("5 - C�lculo do MDC entre dois n�meros pelo Algoritmo de Euclides.\n");
    printf("0 - SAIR\n");
}

int main()
{
    int op, n, a, b;

    opcoes();

    scanf("%d", &op);

    while (op != 0)
    {
        switch (op)
        {
        case 1:
            printf("Digite o n�mero para verificar primalidade:\n");
            scanf("%d", &n);
            ehprimo(n) == 1 ? printf("EH PRIMO\n") : printf("N�O EH PRIMO\n");
            break;

        case 2:
            printf("Digite um n�mero para ser o limite da listagem:\n");
            scanf("%d", &n);
            primossequencial(n);
            break;

        case 3:
            printf("Digite um n�mero para decompor em seus fatores primos unicos:\n");
            scanf("%d", &n);
            decompor_fatores_primos(n);
            break;

        case 5:
            printf("Digite a e b para c�lculo do MDC pelo Algoritmo de Euclides\n");
            scanf("%d%d", &a, &b);
            mdc_euclides(a, b);
            break;

        default:
            printf("Invalido..\n");
        }
        printf("Aperte qualquer bot�o para continuar.\n");
        getchar();
        getchar();

        opcoes();

        scanf("%d", &op);
    }

    printf("Finalizado.\n");

    return 0;
}