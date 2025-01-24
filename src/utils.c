/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:49:56 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/22 23:02:48 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stacks->stack_a->head;
	current_b = stacks->stack_b->head;
	ft_printf("stack a:\n");
	while (current_a)
	{
		ft_printf("%d, ", current_a->data);
		current_a = current_a->next;
	}
	ft_printf("\nstack b:\n");
	while (current_b)
	{
		ft_printf("%d, ", current_b->data);
		current_b = current_b->next;
	}
	ft_printf("\n");
}

int	get_min_value(t_stack *stack, int *position)
{
	int		min_value;
	int		pos;
	int		min_pos;
	t_node	*current;

	if (!stack || stack->size == 0)
	{
		if (position)
			*position = -1;
		return (-1);
	}
	min_value = stack->head->data;
	pos = 0;
	min_pos = 0;
	current = stack->head;
	while (current)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (position)
		*position = min_pos;
	return (min_value);
}

int	get_max_value(t_stack *stack, int *position)
{
	int		max_value;
	int		pos;
	int		max_pos;
	t_node	*current;

	if (!stack || stack->size == 0)
	{
		if (position)
			*position = -1;
		return (-1);
	}
	max_value = stack->head->data;
	pos = 0;
	max_pos = 0;
	current = stack->head;
	while (current)
	{
		if (current->data > max_value)
		{
			max_value = current->data;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (position)
		*position = max_pos;
	return (max_value);
}

int	get_index_inbetween(t_stack *stack, int num, int max_index)
{
	t_node	*current;
	int		target_index;
	int		i;

	// ft_printf("the value is inbetwen\n");
	current = stack->head;
	target_index = -1;
	i = 0;
	while (i++ < max_index)
		current = current->next;
	while (i++ < (stack->size))
	{
	// ft_printf("i %i, current %i, next %i, num %i\n", i, current->data, current->next->data, num);
		if (num < current->data && num > current->next->data)
		{
			target_index = i - 1;
			return (target_index);
		}
		current = current->next;
	}
	i = 0;
	// ft_printf("i %i, current %i, next %i, num %i\n", i, current->data, current->next->data, num);
	if (num < current->data && num > stack->head->data)
	{
		target_index = i;
		return (target_index);
	}
	current = stack->head;
	while (i++ < max_index)
	{
	// ft_printf("i %i, current %i, next %i, num %i\n", i, current->data, current->next->data, num);
		if (num < current->data && num > current->next->data)
		{
			target_index = i;
			return (target_index);
		}
		current = current->next;
	}
	// ft_printf("target index %i\n", target_index);
	return (target_index);
}

// int get_index_inbetween(t_stack *stack, int num, int max_index) {
//     t_node *current;
//     int target_index = -1;
//     int i = 0;

//     // Validate max_index
//     if (max_index < 0 || max_index >= stack->size)
//         return -1; // Invalid max_index

//     current = stack->head;

//     // Traverse the stack
//     while (i < stack->size) {
//         if (num < current->data &&
//             num > (current->next ? current->next->data : stack->head->data)) {
//             target_index = i;
//             break;
//         }
//         current = current->next;
//         i++;
//     }

//     // Debugging output
//     if (target_index != -1)
//         ft_printf("The value %d is in between at index %d\n", num, target_index);
//     else
//         ft_printf("The value %d is not in between any elements\n", num);

//     return target_index;
// }


int	get_target_index(t_stack *stack, int num)
{
	int		target_index;
	int		max_index;
	int		min_index;
	int		max_value;
	int		min_value;

	max_index = 0;
	min_index = 0;
	max_value = get_max_value(stack, &max_index);
	// ft_printf("max value is %i at index %i\n", max_value, max_index);
	min_value = get_min_value(stack, &min_index);
	// ft_printf("min value is %i at index %i, num is %i\n", min_value, min_index, num);

	if (num > max_value)
	{
		// ft_printf("it is new max\n");
		// ft_printf("max index is %i\n", max_index);
		// target_index = max_index;
		return (max_index);
	}
	if (num < min_value)
	{
		// ft_printf("it is new min\n");
		if (min_index == (stack->size - 1))
			target_index = 0;
		else
			target_index = min_index + 1;
	}
	else
		target_index = get_index_inbetween(stack, num, max_index);
	return (target_index);
}
