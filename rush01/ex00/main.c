/*

• Crie um programa que resolva o seguinte problema:

• Num mapa 4 x 4, coloque caixas de tamanho 1 a 4 de modo que cada linha e
cada coluna veja o número de caixas correto de todos os pontos de vista possíveis
(esquerda/direita para as linhas; cima/baixo para as colunas)

• Exemplo: a caixa de tamanho 3 esconde a caixa de tamanho 1, o que significa que
existem apenas 3 caixas visíveis da esquerda. Da direita, a caixa de tamanho 4
esconde todas as outras caixas, portanto tem somente uma caixa visível.

• Cada uma das vistas (duas por linha e duas por coluna) terá um dado valor. O seu
programa deve colocar as caixas corretamente, prestando atenção para ter apenas
uma caixa de cada altura em cada linha e coluna.

• Se existirem muitas soluções, deve exibir a primeira que encontrar.

• O programa será iniciado da seguinte maneira:
    > ./rush01 "col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom row1left
        row2left row3left row4left row1right row2right row3right row4right"

• col1top corresponde ao valor para o ponto de vista da parte superior da coluna da
esquerda. Cada valor deve estar entre 1 e 4.

• Este é o único input aceitável para o seu programa. Qualquer outro input deve ser
considerado um erro.

• Deverá exibir um output da seguinte forma:
    >./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
        1 2 3 4$
        2 3 4 1$
        3 4 1 2$
        4 1 2 3$

*/


#include <unistd.h>

int		parse_input(char *str, int *clues);
int		solve(int grid[4][4], int *clues, int row, int col);
void	print_grid(int grid[4][4]);

/* prepara a grelha vazia (todas as células a 0) antes de o
   backtracking começar a tentar preenchê-la */
void init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	/* aceita-se apenas 1 argumento (a string com as 16 pistas) */
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	/* lê e valida as pistas; se algo estiver errado, sai já */
	if (!parse_input(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_grid(grid);
    
	/* tenta resolver o puzzle a partir da primeira célula (0,0) */
	if (!solve(grid, clues, 0, 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_grid(grid);
	return (0);
}