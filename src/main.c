/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:51:04 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/29 21:28:37 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_and_sort_stack(int *array, int size)
{
	t_stacks	*stacks;

	stacks = init_stacks();
	if (!stacks)
		return ;
	if (!populate_stack(array, stacks->stack_a, size))
	{
		free_stacks(stacks);
		return ;
	}
	if (stacks->stack_a->size <= 5)
		sort_small(stacks);
	else
		sort_stack(stacks);
	free_stacks(stacks);
}

int	main(int argc, char **argv)
{
	int	*array;
	int	size;

	size = argc - 1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (1);
	check_input(argc, argv, array, &size);
	if (!normalize_array(array, size))
		init_and_sort_stack(array, size);
	free (array);
}
