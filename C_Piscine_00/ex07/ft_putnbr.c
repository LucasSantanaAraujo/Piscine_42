/*

• Escreva uma função que mostre um número, passado como parâmetro. A função
deverá ser capaz de representar todos os valores possíveis de uma variável do tipo
int.

• Deve ser prototipada da seguinte maneira:
void ft_putnbr(int nb);

• Por exemplo:
◦ ft_putnbr(42); mostra 42.

*/

#include <unistd.h>

void ft_putnbr(int nb)
{
    long n;
    char c;

    n = nb;

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }

    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write (1, &c, 1);
}

int main(void)
{
    ft_putnbr(42);
    write(1, "\n", 1);

    ft_putnbr(-42);
    write(1, "\n", 1);

    ft_putnbr(-2147483648);
    write(1, "\n", 1);

    ft_putnbr(2147483647);
    write(1, "\n", 1);

    ft_putnbr(0);
    write(1, "\n", 1);

    return (0);
}