/*

• Escreva uma função iterativa que retorne um número. Esse número deve ser o
resultado da operação fatorial a partir do número passado como parâmetro.

• Se o argumento não for válido, a função deve retornar 0.

• Não deve gerir o "int overflow", o retorno da função será indefinido.

• Ela deverá ser prototipada da seguinte maneira:
int ft_iterative_factorial(int nb);

*/

#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int result ;
    int i;

    result = 1;
    i = 1;

    if (nb < 0)
        return (0);
    while (i <= nb)
    {
        result = result * i;
        i++;
    }
    return (result);
}

int main(void)
{
    printf("5! = %d\n", ft_iterative_factorial(5));
    printf("1! = %d\n", ft_iterative_factorial(1));
    printf("0! = %d\n", ft_iterative_factorial(0));
    printf("-5! = %d\n", ft_iterative_factorial(-5));
    return (0);
}