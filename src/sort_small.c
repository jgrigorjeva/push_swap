/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:53:31 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 19:17:56 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks)
{
	rotate(stacks->stack_a);
	ft_printf("ra\n");
	stacks->operation_count++;
}

void	renorm(t_stack *stack, int i, int sign)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current->data += i * sign;
		current = current->next;
	}
}

static void	remove_min(t_stacks *stacks, t_ops *ops)
{
	while (ops->ra-- > 0)
	{
		rotate(stacks->stack_a);
		ft_printf("ra\n");
	}
	while (ops->rra-- > 0)
	{
		reverse_rotate(stacks->stack_a);
		ft_printf("rra\n");
	}
	push_b(stacks);
	ft_printf("pb\n");
}

void	sort_four_five(t_stacks *stacks)
{
	t_ops	*ops;
	int		min_index;
	int		min_value;
	int		i;

	ops = init_operations();
	min_index = 0;
	min_value = 0;
	i = 0;
	while (stacks->stack_a->size > 3)
	{
		min_value = get_min_value(stacks->stack_a, &min_index);
		if (min_index > (stacks->stack_a->size) / 2)
			ops->rra = stacks->stack_a->size - min_index;
		else
			ops->ra = min_index;
		remove_min(stacks, ops);
		i++;
	}
	renorm(stacks->stack_a, i, -1);
	sort_three(stacks);
	renorm(stacks->stack_a, i, 1);
	push_all_to_a(stacks);
	(void)min_value;
	free_operations(ops);
}

void	sort_small(t_stacks *stacks)
{
	if (stacks->stack_a->size == 2)
		sort_two(stacks);
	if (stacks->stack_a->size == 3)
		sort_three(stacks);
	if (stacks->stack_a->size >= 4)
		sort_four_five(stacks);
}
