/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_palindrome.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:32:20 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/22 15:26:33 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	is_pal;

	is_pal = 1;
	if (argc == 2)
	{
		j = 0;
		while (argv[1][j])
			j++;
		j--;
		i = 0;
		while (i < j)
		{
			if (argv[1][i] != argv[1][j])
				is_pal = 0;
			i++;
			j--;
		}
		if (is_pal)
		{
			i = 0;
			while (argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
