#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = temp / *b;
	*b = temp % *b;
}

int main(void)
{
	int x = 17;
	int y = 5;

	ft_ultimate_div_mod(&x, &y);
	printf("div = %d,  mod = %d\n", x, y);
	return (0);
}
