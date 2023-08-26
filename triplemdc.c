#include <stdio.h>
// Esse código serve somente como base, mude o nome da main e troque o printf por return! Teste antes de implementar, se possível. :]

int MDC (int numA, int numB)
{

        while (numB != 0)
        {
 
        int placeholder = numA%numB;
            numA = numB;
            numB = placeholder;

        }
        return numA;

    }

int main(int n1, int n2,int n3)
{
    int varmdc;
    scanf("%d%d%d", &n1, &n2,&n3);
    //Obtém o MDC de n1 e n2
    if ( n1 > n2)  {

    
    varmdc = MDC(n1, n2);
    }
    else
    {
        varmdc = MDC(n2,n1);
    }
    // Faz o mdc geral
    if (varmdc > n3){

    printf("%d",MDC(varmdc,n3));
}
    else 
    {
        printf("%d",MDC(n3,varmdc));
    }

    return 0;
}
