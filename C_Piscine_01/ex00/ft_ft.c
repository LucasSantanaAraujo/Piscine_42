/*

• Escreva uma função que receba um ponteiro para inteiro como parâmetro e coloque
no inteiro o valor "42".

• Deverá ser prototipada da seguinte maneira:
void ft_ft(int *nbr);

*/


#include <stdio.h>

void ft_ft(int *nbr)
{
		*nbr = 42;
}

int main(void)
{
		int x = 10;

		ft_ft(&x);

		printf("%d\n", x);

		return 0;
}
