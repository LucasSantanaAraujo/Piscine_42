/*

Esta função mostra a grelha resolvida no ecrã, no formato exato pedido pelo enunciado: 
cada linha numa linha própria, números separados por um único espaço, sem espaço a mais no fim. 
Usa write, porque é a única função de escrita autorizada para a entrega final (não podemos usar printf).

*/

#include <unistd.h>

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			/* converte o número (1-4) no caractere correspondente ('1'-'4') */
			c = '0' + grid[i][j];
			write(1, &c, 1);
            
			/* espaço entre números, mas não depois do último da linha */
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}