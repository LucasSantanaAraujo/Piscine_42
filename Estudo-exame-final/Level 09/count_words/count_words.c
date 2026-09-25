/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:52:20 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/24 12:22:46 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_words(char *str)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", count_words("hello    world"));
	printf("%d\n", count_words(""));
	printf("%d\n", count_words("    "));
	printf("%d\n", count_words("  hello  world  "));
	return (0);
}
*/
