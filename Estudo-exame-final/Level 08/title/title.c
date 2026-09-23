/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:32:42 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/22 17:48:19 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if ((argv[i][j] >= 'a' && argv[i][j] <= 'z')
						&& (j == 0 || argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t'))
					argv[i][j] -= 32;
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
