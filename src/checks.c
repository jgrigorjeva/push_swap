/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:10:24 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 23:20:10 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(int size, int *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				free (array);
				error();
			}
			j++;
		}
		i++;
	}
}

// only considering the input in the form of separate numbers,
// a single string is not accepted
void	check_input(int argc, char **argv, int *array)
{
	int	size;

	if (argc < 3)
		error();
	size = argc - 1;
	populate_array(argv, array, size);
	check_duplicates(size, array);
}

int	check_stack_order(t_stack *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	while (current)
	{
		if (current->data != i)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
