/*

• Escreva uma função que mostre todas as diferentes combinações de n números em
ordem crescente.

• n será tal que: 0 < n <10.

• Se n = 2, o resultado esperado seria:
$>./a.out | cat -e
01, 02, 03, ..., 09, 12, ..., 79, 89$>

• Deve ser prototipada da seguinte maneira:
void ft_print_combn(int n);


*/

#include <unistd.h>

void ft_print_combn_rec(int n, int depth, char *combo, int *first)
{
	int	start;
	int	i;

	if (depth == 0)
		start = 0;
	else
		start = (combo[depth - 1] - '0') + 1;
	i = start;
	while (i <= 9 - (n - depth - 1))
	{
		combo[depth] = '0' + i;
		if (depth == n - 1)
		{
			if (*first == 0)
				write(1, ", ", 2);
			write(1, combo, n);
			*first = 0;
		}
		else
			ft_print_combn_rec(n, depth + 1, combo, first);
		i++;
	}
}

void ft_print_combn(int n)
{
	char	combo[9];
	int		first;

	first = 1;
	ft_print_combn_rec(n, 0, combo, &first);
}
int main(void)
{
    ft_print_combn(2);
    write(1, "\n", 1);

    return (0);
}