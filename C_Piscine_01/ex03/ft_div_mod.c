#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main(void)
{
	int x = 17;
	int y = 3;

	int d;
	int m;

	ft_div_mod(x, y, &d, &m);
	printf("%d / %d = %d\n%d %% %d = %d\n", x, y, d, x, y, m);
	return (0);
}
