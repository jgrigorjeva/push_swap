/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:49:56 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 19:01:53 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack *stack, int *position)
{
	int		min_value;
	int		pos;
	int		min_pos;
	t_node	*current;

	if (!stack || stack->size == 0)
		return (-1);
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
		return (-1);
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

int	get_index_inbetween2(t_node *cur, t_stack *stack, int num, int max_index)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = 0;
	if (num < cur->data && num > stack->head->data)
	{
		target_index = i;
		return (target_index);
	}
	cur = stack->head;
	while (i++ < max_index)
	{
		if (num < cur->data && num > cur->next->data)
		{
			target_index = i;
			return (target_index);
		}
		cur = cur->next;
	}
	return (target_index);
}

int	get_index_inbetween(t_stack *stack, int num, int max_index)
{
	t_node	*current;
	int		target_index;
	int		i;

	current = stack->head;
	target_index = 0;
	i = 0;
	while (i++ < max_index)
		current = current->next;
	while (i++ < (stack->size))
	{
		if (num < current->data && num > current->next->data)
		{
			target_index = i - 1;
			return (target_index);
		}
		current = current->next;
	}
	target_index = get_index_inbetween2(current, stack, num, max_index);
	return (target_index);
}

int	get_target_index(t_stack *stack, int num)
{
	int		target_index;
	int		max_index;
	int		min_index;
	int		max_value;
	int		min_value;

	max_index = 0;
	min_index = 0;
	if (stack->size < 2)
		return (0);
	max_value = get_max_value(stack, &max_index);
	min_value = get_min_value(stack, &min_index);
	if (num > max_value)
		return (max_index);
	if (num < min_value)
	{
		if (min_index == (stack->size - 1))
			target_index = 0;
		else
			target_index = min_index + 1;
	}
	else
		target_index = get_index_inbetween(stack, num, max_index);
	return (target_index);
}
