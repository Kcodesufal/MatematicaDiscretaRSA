#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int primechecker (unsigned long int N) {


   


    if ( (N%2 == 0 && N != 2) || N <= 1)
    {
    return 0;
    }
        for (int cont = 3; cont <= sqrt(N); cont+= 2)
        {
            if (N%cont == 0)
            {
                return 0;
            }
            
        }
        printf ("%ld\n",N);
        return 1;

    }
int main ()
{

time_t timer;
long int current_number = 3;
long int primes = 1;
timer = time(NULL);
printf ("2\n");
while (time(NULL) - timer <60)
{
if ( primechecker(current_number) == 1)
{
    primes++;

}
current_number += 2;
}

printf("\n%ld primos impressos.",primes);
}
/* A intenção é alcançar os 2.7 milhões.
 Favor fazer o teste nos seus computadores e dizer o último valor printado...
 Alternativamente, podemos remover o contador de primos para aumentar performance...
 Por enquanto, o 2 é printado a parte, por questões de otimização! 
 Visto que ele é uma exceção, creio que não seja um problema fazer isso, mas se sintam livres para
 modificar o código. :]
 */

