/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:04:41 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/23 15:28:10 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 4)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == argv[2][0])
			{
				argv[1][i] = argv[3][0];
				write(1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
