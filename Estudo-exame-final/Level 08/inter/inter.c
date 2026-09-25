/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:01:54 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/24 11:19:54 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	array[256] = {0};
	int	i;
	int	j;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			j = (unsigned char)argv[2][i];
			if (array[j] == 0)
				array[j] = 1;
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			j = (unsigned char)argv[1][i];
			if (array[j] == 1)
			{
				write(1, &argv[1][i], 1);
				argv[j] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
