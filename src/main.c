/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:51:04 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/24 00:09:34 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	populate_array(char **argv, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		if (ft_atoi(argv[i + 1]) == 0 && \
		!(argv[i + 1][0] == '0' && argv[i + 1][1] == '\0'))
		{
			free(array);
			error();
		}
		i++;
	}
}

int	populate_stack(int *array, t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!push(stack, array[size - i - 1]))
			return (0);
		i++;
	}
	return (1);
}

void	init_and_sort_stack(int *array, int size)
{
	t_stacks *stacks;

	stacks = init_stacks();
	if (!stacks)
		return ;
	if (!populate_stack(array, stacks->stack_a, size))
		free_stacks(stacks);
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
	check_input(argc, argv, array);
	normalize_array(array, size);

	// // // see the array
	// int i = 0;
	// while (i < size)
	// {
	// 	ft_printf("%i, ", array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	init_and_sort_stack(array, size);

	free (array);
}