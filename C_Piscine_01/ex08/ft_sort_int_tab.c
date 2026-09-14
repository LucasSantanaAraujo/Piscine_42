/*

• Escreva uma função que ordene um array de inteiros em ordem crescente.

• Os parâmetros são um ponteiro para inteiro e o número de inteiros no array.

• A função deverá ser prototipada da seguinte maneira:
void ft_sort_int_tab(int *tab, int size);

*/


#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
		int i = 0;
		int temp;

		while (i < size)
			{
					int j = 0;

					while (j < size - 1 - i)
					{
							if (tab[j] > tab[j + 1])
							{
									temp = tab[j];
									tab[j] = tab[j + 1];
									tab[j + 1] = temp;
							}
							j++;
					}
					i++;
			}
}

int main(void)
{
		int size = 10;
		int arr[size];

		int i = 0;

		do
		{
				printf("Valor %d: ", i + 1);
				scanf("%d", &arr[i]);
				i++;
		} while (i < size);

		ft_sort_int_tab(arr, size);

		printf("Array ordenado: ");

		i = 0;
		while (i < size)
		{
				printf("%d ", arr[i]);
				i++;
		}
		
		printf("\n");

		return 0;
}
