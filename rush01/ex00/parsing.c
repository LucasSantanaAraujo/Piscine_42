/*

Esta função lê a string recebida na linha de comandos (por exemplo, "4 3 2 1 1 2 2 2...") 
e transforma-a em 16 números reais, guardados no array clues. Ao mesmo tempo, valida se 
a entrada tem o formato correto: só dígitos entre 1 e 4, separados por espaços, 
exatamente 16 números. Se encontrar qualquer coisa fora destas regras, considera a entrada inválida.

A função devolve 1 se tudo estiver correto, ou 0 se encontrar algum problema 
(este valor será usado pelo main para decidir se deve continuar ou mostrar Error).

*/

int	parse_input(char *str, int *clues)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	/* percorre a string toda, caractere a caractere */
	while (str[i] != '\0')
	{
		/* salta espaços entre números */
		while (str[i] == ' ')
			i++;

		/* pode ter sido só um espaço no fim da string */
		if (str[i] == '\0')
			break ;

		/* qualquer caractere que não seja dígito 1-4 é inválido */
		if (str[i] < '1' || str[i] > '4')
			return (0);

		/* exige que o dígito seja seguido de espaço ou fim de string,
		   rejeitando assim números de dois dígitos (ex: "12") */
		if (str[i + 1] != ' ' && str[i + 1] != '\0')
			return (0);

		/* já recolhemos 16 números e ainda há mais? entrada inválida */
		if (count >= 16)
			return (0);

		/* converte o caractere ('1'-'4') no número real (1-4) */
		clues[count] = str[i] - '0';
		count++;
		i++;
	}
    
	/* só é válido se tivermos encontrado exatamente 16 números */
	return (count == 16);
}