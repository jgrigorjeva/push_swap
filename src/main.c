/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:51:04 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/29 23:48:22 by jgrigorj         ###   ########.fr       */
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
	int		*array;
	char	**temp_array;
	int		size;
	int		i;

	temp_array = get_input(argc, argv, &size);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (1);
	populate_arr(temp_array, array, size);
	check_duplicates(size, array);
	if (!normalize_array(array, size))
		init_and_sort_stack(array, size);
	i = 0;
	while (temp_array[i])
		free(temp_array[i++]);
	free(temp_array);
	free (array);
}
