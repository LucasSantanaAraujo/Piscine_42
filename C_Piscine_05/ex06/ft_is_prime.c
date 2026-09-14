/*

• Escreva uma função que retorne 1 se o número recebido for primo e 0 se não for.

• Ela deverá ser prototipada da seguinte maneira:
int ft_is_prime(int nb);

*/

#include <stdio.h>

int ft_is_prime(int nb)
{
    int i;

    i = 3;

    if (nb <= 1)
        return (0);

    if (nb == 2)
        return (1); // 2 is prime

    if (nb % 2 == 0)
        return (0); // If the number is even and greater than 2, it is not prime

    while (i * i <= nb)
    {
        if (nb % i == 0)
            return (0); // If exist a divisor, the number is not prime

        i = i + 2; // Increment by 2 to check only odd numbers
    }

    return (1);
}

int main(void)
{
    printf("Is 0 prime? : %d\n", ft_is_prime(0));
    printf("Is 1 prime? : %d\n", ft_is_prime(1));
    printf("Is 2 prime? : %d\n", ft_is_prime(2));
    printf("Is 3 prime? : %d\n", ft_is_prime(3));
    printf("Is 4 prime? : %d\n", ft_is_prime(4));
    printf("Is 5 prime? : %d\n", ft_is_prime(5));
    printf("Is 6 prime? : %d\n", ft_is_prime(6));
    printf("Is 7 prime? : %d\n", ft_is_prime(7));
    printf("Is 9 prime? : %d\n", ft_is_prime(9));
    printf("Is 11 prime? %d\n", ft_is_prime(11));
    return (0);
}