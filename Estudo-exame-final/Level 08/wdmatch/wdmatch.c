/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:39:17 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/24 11:50:33 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if(argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[2][j] != '\0' && argv[2][j] != argv[1][i])
				j++;
			if (argv[2][j] == '\0')
			{
				write(1, "\n", 1);
				return (0);
			}
			j++;
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
