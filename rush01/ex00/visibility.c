/*

Esta função responde à pergunta: "olhando para esta fila de 4 números, 
a partir de um determinado lado, quantos prédios consigo ver?"

A função percorre a fila de 4 posições, guardando sempre o "maior valor já visto até agora" 
(começa em 0, porque ainda não vimos nenhum). Sempre que encontra um valor maior do que esse 
recorde atual, isso significa que esse prédio consegue ser visto (nada mais alto o tapou até aqui).
Nnesse caso, atualiza o recorde para esse novo valor, e soma mais um ao contador de prédios visíveis. 
Se o valor não for maior que o recorde, esse prédio está escondido atrás de outro mais alto, e a função 
simplesmente avança sem contar nada.

Os parâmetros start e step servem para reutilizar a mesma função nas quatro direções possíveis 
(esquerda, direita, cima, baixo), sem precisarmos de escrever quatro versões diferentes:
    - Para olhar da esquerda ou de cima: start = 0, step = 1 (percorre a fila do início para o fim).
    - Para olhar da direita ou de baixo: start = 3, step = -1 (percorre a fila do fim para o início).

No final, a função devolve o total de prédios visíveis contados, este valor será depois comparado com 
a pista correspondente, dada na entrada do programa, para saber se a disposição da grelha está correta.

*/

int count_visible(int *line, int start, int step)
{
    int position;
    int max;
    int visible;
    int i;

    position = start;
    max = 0;
    visible = 0;
    i = 0;

    /* Percorre os 4 valores da fila, na direção indicada por "step":
	   step=1 percorre da esquerda/cima; step=-1 percorre da direita/baixo */
    while (i < 4)
    {
        /* Se este valor for maior que o maior já visto até agora,
		   ele é visível */
        if (line[position] > max)
        {
            max = line[position];
            visible++;
        }
        position = position + step;
        i++;
    }
    return (visible);
}


/*

Esta função resolve um problema prático: a função count_visible só sabe trabalhar 
com uma fila simples de 4 números seguidos (um array). Isto já funciona diretamente 
para as linhas da grelha (grid[1], por exemplo, já se comporta como um array de 4 valores), 
mas não funciona para as colunas — os valores de uma coluna estão espalhados pela grelha, 
um em cada linha diferente, não seguidos na memória.

A função get_column resolve isto copiando os 4 valores de uma coluna específica 
(indicada pelo parâmetro col) para um array novo (out), percorrendo as 4 linhas da grelha, 
uma a uma. Depois desta cópia, o array out já pode ser passado diretamente a count_visible, 
exatamente como se fosse uma linha.

*/

void get_column(int grid[4][4], int col, int *out)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		out[i] = grid[i][col];
		i++;
	}
}


/*

Esta função responde à pergunta final do puzzle: "esta grelha, já completamente preenchida, 
satisfaz todas as 16 pistas dadas na entrada?"

Ela percorre as 4 linhas e as 4 colunas da grelha, uma de cada vez, e para cada uma calcula as 
visibilidades nos dois sentidos possíveis (esquerda/direita para linhas, cima/baixo para colunas), 
usando a função count_visible que já construímos. Cada valor calculado é comparado com a pista 
correspondente, guardada no array clues.

Como as 16 pistas vêm todas juntas num único array, a função precisa de saber exatamente onde está cada uma. 
Seguindo a ordem definida no enunciado: as posições 0 a 3 guardam as pistas de cima das colunas 
(col1top a col4top); as posições 4 a 7 guardam as pistas de baixo das colunas; as posições 8 a 11 guardam 
as pistas da esquerda das linhas; e as posições 12 a 15 guardam as pistas da direita das linhas.

Assim que uma única comparação falhar, a função devolve 0 imediatamente, não faz sentido continuar 
a verificar o resto, já sabemos que esta grelha não é válida. Só devolve 1 (grelha correta) 
se conseguir percorrer as 4 linhas e as 4 colunas inteiras, com todas as 16 comparações a bater certo.

*/

int check_all(int grid[4][4], int *clues)
{
    int i;
    int col[4];

    i = 0;
    /* "i" representa, ao mesmo tempo, o número da linha E o número
	   da coluna que estamos a verificar nesta volta do ciclo */
    while (i < 4)
    {
        /* grid[i] já é a linha "i" inteira (4 valores seguidos).
		   Vemos da esquerda (start=0, step=1) e comparamos com a
		   pista "row(i+1)left", guardada na posição 8+i do array */
        if (count_visible(grid[i], 0, 1) != clues[8 + i])
            return (0);

        /* mesma linha, mas vista da direita (start=3, step=-1).
		   A pista "row(i+1)right" está na posição 12+i */
        if (count_visible(grid[i], 3, -1) != clues[12 + i])
            return (0);
        
        /* uma coluna não está seguida na memória como uma linha,
		   por isso copiamos os seus 4 valores para "col" primeiro */
        get_column(grid, i, col);

        /* coluna "i" vista de cima. A pista "col(i+1)top"
		   está na posição i (as 4 primeiras posições do array) */
        if (count_visible(col, 0, 1) != clues[i])
            return (0);

        /* mesma coluna, vista de baixo. A pista "col(i+1)bottom"
		   está na posição 4+i */
        if (count_visible(col, 3, -1) != clues[4 + i])
            return (0);
        i++;
    }

    /* chegámos até aqui sem nenhum "return (0)" ter disparado:
	   todas as 16 pistas bateram certo, a grelha está correta */
    return (1);
}