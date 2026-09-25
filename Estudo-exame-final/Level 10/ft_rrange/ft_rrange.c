/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:48:48 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/24 14:02:10 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*array;
	int	i;
	int	n;
	int	step;

	i = 0;
	if (start >= end)
	{
		n = (start - end) + 1;
		step = -1;
	}
	else
	{
		n = (end - start) + 1;
		step = 1;
	}
	array = (int *) malloc(n * sizeof(int));
	if (array == NULL)
		return (NULL);
	while (i < n)
	{
		array[i] = end;
		end -= step;
		i++;
	}
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*result;
	int	i;

	result = ft_rrange(1,3);
	i = 0;
	if (result == NULL)
	{
		printf("NULL returned");
		return (0);
	}
	while (i < 3)
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");
	free(result);
	return (0);
}
*/
