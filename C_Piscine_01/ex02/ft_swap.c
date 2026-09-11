#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int x = 5;
	int y = 2;

	printf("Antes da troca: \n%d\n%d\n", x, y);

	ft_swap(&x, &y);

	printf("Depois da troca:\n%d\n%d\n", x, y);
	return (0);
}
