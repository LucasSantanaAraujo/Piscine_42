/*

• Escreva uma função ft_fibonacci que retorne o n-iésimo elemento da sequência
de Fibonacci, sendo o primeiro elemento com índice 0. Vamos considerar que a
sequência de Fibonacci começa por 0, 1, 1, 2.

• Não deve gerir o "int overflow", o retorno da função será indefinido.

• Ela deverá ser prototipada da seguinte maneira:
int ft_fibonacci(int index);

• Evidentemente, ft_fibonacci deverá ser recursiva.

• Se index for inferior a 0, a função retornará -1.

*/

#include <stdio.h>

int ft_fibonacci(int index)
{
    int result;

    result = 1;
    
    if (index < 0)
        return (-1);
    if (index <= 1)
        return (index);
    
    result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);

    return (result);
}

int main(void)
{
    printf("Fibonacci(0) = %d\n", ft_fibonacci(0));
    printf("Fibonacci(1) = %d\n", ft_fibonacci(1));
    printf("Fibonacci(2) = %d\n", ft_fibonacci(2));
    printf("Fibonacci(3) = %d\n", ft_fibonacci(3));
    printf("Fibonacci(4) = %d\n", ft_fibonacci(4));
    printf("Fibonacci(5) = %d\n", ft_fibonacci(5));
    printf("Fibonacci(6) = %d\n", ft_fibonacci(6));
    printf("Fibonacci(7) = %d\n", ft_fibonacci(7));
    printf("Fibonacci(8) = %d\n", ft_fibonacci(8));
    printf("Fibonacci(9) = %d\n", ft_fibonacci(9));
    printf("Fibonacci(10) = %d\n", ft_fibonacci(10));
    printf("Fibonacci(-1) = %d\n", ft_fibonacci(-1));
    return (0);
}