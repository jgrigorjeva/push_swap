/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:10:24 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/23 23:36:57 by jgrigorj         ###   ########.fr       */
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

// only considering the input in the form of separate numbers, no single string is accepted
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
	ft_printf("stack is in order\n");
	return (1);
}

int	check_stack_order_general(t_stack *stack)
{
	t_node	*current;
	int		expected_value;
	int		smallest_value;

	if (!stack || !stack->head) // Check for NULL stack or empty stack
		return (0);

	// Find the smallest value in the stack
	smallest_value = stack->head->data;
	current = stack->head->next;
	while (current)
	{
		if (current->data < smallest_value)
			smallest_value = current->data;
		current = current->next;
	}

	// Check that values are in order starting from the smallest value
	current = stack->head;
	expected_value = smallest_value;
	while (current)
	{
		if (current->data != expected_value)
			return (0); // Stack is not in order
		current = current->next;
		expected_value++;
	}
	ft_printf("stack is in order");
	return (1); // Stack is in order
}