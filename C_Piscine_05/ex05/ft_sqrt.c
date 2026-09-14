/*

• Escreva uma função que retorne a raiz quadrada inteira de um número se ela existir,
e 0 se a raiz quadrada for um número irracional.

• Ela deverá ser prototipada da seguinte maneira:
int ft_sqrt(int nb);

*/

#include <stdio.h>

int ft_sqrt(int nb)
{
    int guess;

    guess = 1;

    if (nb < 0)
        return (0);

    while (guess * guess < nb)
    {
        guess++;
    }
        
    if (guess * guess == nb)
        return (guess);
    else
        return (0);
}

int main(void)
{
    printf("Sqrt(0) = %d\n", ft_sqrt(0));
    printf("Sqrt(1) = %d\n", ft_sqrt(1));
    printf("Sqrt(4) = %d\n", ft_sqrt(4));
    printf("Sqrt(9) = %d\n", ft_sqrt(9));
    printf("Sqrt(10) = %d\n", ft_sqrt(10));
    printf("Sqrt(25) = %d\n", ft_sqrt(25));
    printf("Sqrt(49) = %d\n", ft_sqrt(49));
    printf("Sqrt(100) = %d\n", ft_sqrt(100));
    printf("Sqrt(-1) = %d\n", ft_sqrt(-1));
    return (0);
}