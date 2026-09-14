/*

• Escreva uma função recursiva que retorne o fatorial do número passado como parâmetro.

• Se o argumento não for válido, a função deve retornar 0.

• Não deve gerir o "int overflow", o retorno da função será indefinido.

• Ela deverá ser prototipada da seguinte maneira:
int ft_recursive_factorial(int nb);

*/

#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    int result;

    result = 1;

    if (nb < 0)
        return (0);
    
    if (nb == 0 || nb == 1)
        return (1);

    result = nb * ft_recursive_factorial(nb - 1);

    return (result);
}

int main(void)
{
    printf("5! = %d\n", ft_recursive_factorial(5));
    printf("1! = %d\n", ft_recursive_factorial(1));
    printf("0! = %d\n", ft_recursive_factorial(0));
    printf("-5! = %d\n", ft_recursive_factorial(-5));
    return (0);
}