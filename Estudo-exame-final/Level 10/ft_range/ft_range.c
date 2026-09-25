/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:23:10 by lucsanta          #+#    #+#             */
/*   Updated: 2026/09/24 13:48:34 by lucsanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
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
		array[i] = start;
		start += step;
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

	result = ft_range(0,-3);
	i = 0;
	if (result == NULL)
	{
		printf("NULL returned");
		return (0);
	}
	while (i < 4)
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");
	free(result);
	return (0);
}
*/
