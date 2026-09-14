/*

• Escreva uma função que retorne o número primo imediatamente superior ou igual
ao número passado como parâmetro.

• Ela deverá ser prototipada da seguinte maneira:
int ft_find_next_prime(int nb);


*/

#include <stdio.h>

int ft_find_next_prime(int nb)
{
    int i;
    int is_prime;

    i = 3;

    if (nb <= 2)
        return (2);

    if (nb % 2 == 0)
        nb++;

    while (1) // Loop until a prime number is found
    {
        is_prime = 1;
        i = 3;

        while (i * i <= nb) // Check if nb have any divisor
        {
            if (nb % i == 0)
            {
                is_prime = 0; // Exist a divisor, the number is not prime
                break;
            }
            i = i + 2; // Increment by 2 to check only odd numbers
        }

        if (is_prime)
            return (nb);

        nb = nb + 2; // If it wasnt prime, increment by 2 to check only odd numbers
    }

}

int main(void)
{
    printf("Next prime after 0: %d\n", ft_find_next_prime(0));
    printf("Next prime after 1: %d\n", ft_find_next_prime(1));
    printf("Next prime after 2: %d\n", ft_find_next_prime(2));
    printf("Next prime after 3: %d\n", ft_find_next_prime(3));
    printf("Next prime after 4: %d\n", ft_find_next_prime(4));
    printf("Next prime after 5: %d\n", ft_find_next_prime(5));
    printf("Next prime after 6: %d\n", ft_find_next_prime(6));
    printf("Next prime after 7: %d\n", ft_find_next_prime(7));
    printf("Next prime after 8: %d\n", ft_find_next_prime(8));
    printf("Next prime after 9: %d\n", ft_find_next_prime(9));
    printf("Next prime after 10: %d\n", ft_find_next_prime(10));
    return (0);
}