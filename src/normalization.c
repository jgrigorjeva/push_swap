/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:20:51 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/20 19:20:51 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_val(t_pair *a, t_pair *b)
{
	t_pair	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	sort_pair_array(t_pair *pairs, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	swapped = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (pairs[j].value > pairs[j + 1].value)
			{
				swap_val(&pairs[j], &pairs[j + 1]);
				swapped++;
			}
			j++;
		}
		i++;
	}
	return (swapped);
}


void	normalize_array(int *array, int size)
{
	t_pair	*pairs;
	int		i;

	pairs = malloc(size * sizeof(t_pair));
	i = 0;
	while (i < size)
	{
		pairs[i].value = array[i];
		pairs[i].original_index = i;
		i++;
	}
	if (!sort_pair_array(pairs, size))
	{
		ft_printf("The input is already ordered. You should terminate the program here.\n");
	}
	i = 0;
	while (i < size)
	{
		array[pairs[i].original_index] = i;
		i++;
	}
	free(pairs);
}