/*

• Escreva uma função iterativa que retorne uma potência de um número. Uma potência inferior a 0 retornará 0.

• Não deve gerir o "int overflow", o retorno da função será indefinido.

• Nós decidimos que a potência de 0 sobre 0 deve retornar 1.

• Ela deverá ser prototipada da seguinte maneira:
int ft_iterative_power(int nb, int power);

*/

#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int result;
    int i;

    result = 1;
    i = 1;

    if (power < 0)
        return (0);
    while (i <= power)
    {
        result = result * nb;
        i++;
    }
    return (result);
}

int main(void)
{
    printf("2^4 = %d\n", ft_iterative_power(2, 4));
    printf("3^3 = %d\n", ft_iterative_power(3, 3));
    printf("5^0 = %d\n", ft_iterative_power(5, 0));
    printf("0^0 = %d\n", ft_iterative_power(0, 0));
    printf("2^-2 = %d\n", ft_iterative_power(2, -2));
    return (0);
}