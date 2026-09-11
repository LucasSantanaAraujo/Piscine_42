#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int i = 0;
	int j = size - 1;
	int temp = 0;

	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

int main(void)
{
	int size = 5;
	int tab[size];
	int i = 0;

	tab[0] = 10;
	tab[1] = 20;
	tab[2] = 30;
	tab[3] = 40;
	tab[4] = 50;
	
	printf("Original array :");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_rev_int_tab(tab, size);
	printf("Reversed array :");
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
