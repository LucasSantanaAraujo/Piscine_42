/*

Esta função responde a uma pergunta simples: 
"posso colocar o número "num" nesta célula da grelha, sem violar as regras do jogo?"

As regras do puzzle dizem que cada número (1 a 4) só pode aparecer uma vez em cada linha 
e uma vez em cada coluna. Por isso, antes de colocarmos um número numa célula, precisamos 
de confirmar que esse número ainda não foi usado nem na mesma linha, nem na mesma coluna, 
nas células que já preenchemos até agora.

A função faz isto em dois passos: primeiro percorre as colunas anteriores da mesma linha 
à procura desse número; depois percorre as linhas anteriores da mesma coluna, também à procura 
dele. Se o encontrar em qualquer um dos dois sítios, devolve 0 (não pode) imediatamente. 
Se não encontrar em lado nenhum, devolve 1 (pode).

Esta função não verifica as pistas de visibilidade (os números à volta da grelha). 
Isso só será verificado mais tarde, quando a grelha inteira estiver preenchida. 
Esta função trata só da regra "sem repetir número na linha/coluna", que verificamos 
célula a célula, à medida que vamos preenchendo o puzzle.

*/

int check_all(int grid[4][4], int *clues);

int is_valid(int grid[4][4], int row, int col, int num)
{
    int i;

    i = 0;

    /* Verifica se o valor do numero "num" já existe na mesma LINHA,
	   olhando só para as colunas já preenchidas antes desta */
    while (i < col)
    {
        if (grid[row][i] == num)
            return (0);
        i++;
    }

    i = 0;
    /* Verifica se o valor do numero "num" já existe na mesma COLUNA,
	   olhando só para as linhas já preenchidas antes desta */
    while (i < row)
    {
        if (grid[i][col] == num)
            return (0);
        i++;
    }
    /* Não houve conflito nem na linha nem na coluna:
	   o valor "num" pode ser colocado nesta célula */

    return (1);
}


/*

Esta é a função central do puzzle, implementa o "tentar e recuar" de célula a célula. 
Recebe a grelha (ainda a ser preenchida), as 16 pistas, e a posição atual (row, col) 
onde deve tentar colocar um valor.

A função funciona de forma recursiva: depois de colocar um valor válido na célula atual, 
ela chama-se a si própria para tratar da célula seguinte. Só quando não há mais nenhuma 
célula por preencher é que verifica, com check_all, se a grelha completa satisfaz as pistas.

A função devolve 1 quando encontra uma solução completa (a partir desta célula em diante), 
e 0 quando esgota todas as tentativas sem sucesso — é esse 1 ou 0 que "avisa" a célula anterior 
se deve continuar com o valor atual, ou desistir e tentar outro.

*/

int	solve(int grid[4][4], int *clues, int row, int col)
{
	int	value;
	int	nrow;
	int	ncol;

	/* já preenchemos as 4 linhas (0,1,2,3): a grelha está completa,
	   é hora de verificar se bate certo com as 16 pistas */
	if (row == 4)
		return (check_all(grid, clues));

	/* calcula qual é a PRÓXIMA célula, para usar mais à frente
	   se o valor atual funcionar: avança uma coluna... */
	ncol = col + 1;
	nrow = row;

	/* ...mas se já passou da última coluna, salta para o início
	   da linha seguinte */
	if (ncol == 4)
	{
		ncol = 0;
		nrow = row + 1;
	}

	value = 1;
	/* tenta cada valor possível, um de cada vez, nesta célula */
	while (value <= 4)
	{
		/* só avança se este valor não repetir na linha/coluna */
		if (is_valid(grid, row, col, value))
		{
			grid[row][col] = value;

			/* chama-se a si própria para preencher a célula seguinte;
			   se essa chamada disser "consegui" (1), este sucesso
			   propaga-se imediatamente para quem nos chamou */
			if (solve(grid, clues, nrow, ncol))
				return (1);

			/* a célula seguinte não conseguiu: desfazemos esta
			   escolha (célula volta a vazio) e tentamos outro valor */
			grid[row][col] = 0;
		}
		value++;
	}
	/* nenhum dos 4 valores funcionou nesta célula:
	   avisa quem nos chamou que também precisa de tentar outra coisa */
	return (0);
}
