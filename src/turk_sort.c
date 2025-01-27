/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:39:51 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 19:45:01 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stacks *stacks, t_ops *ops)
{
	int	max_index;

	max_index = 0;
	get_max_value(stacks->stack_b, &max_index);
	if (max_index > (stacks->stack_b->size) / 2)
	{
		ops->rb = 0;
		ops->rrb = stacks->stack_b->size - max_index;
	}
	else
	{
		ops->rb = max_index;
		ops->rrb = 0;
	}
	while (ops->rb--)
	{
		rotate(stacks->stack_b);
		ft_printf("rb\n");
	}
	while (ops->rrb--)
	{
		reverse_rotate(stacks->stack_b);
		ft_printf("rrb\n");
	}
}

void	single_rotations(t_stacks *stacks, t_ops *ops)
{
	while (ops->ra--)
	{
		rotate(stacks->stack_a);
		ft_printf("ra\n");
		(stacks->operation_count)++;
	}
	while (ops->rb--)
	{
		rotate(stacks->stack_b);
		ft_printf("rb\n");
		(stacks->operation_count)++;
	}
	while (ops->rra--)
	{
		reverse_rotate(stacks->stack_a);
		ft_printf("rra\n");
		(stacks->operation_count)++;
	}
	while (ops->rrb--)
	{
		reverse_rotate(stacks->stack_b);
		ft_printf("rrb\n");
		(stacks->operation_count)++;
	}
}

void	double_rotations(t_stacks *stacks, t_ops *ops)
{
	while (ops->rr--)
	{
		rotate(stacks->stack_a);
		rotate(stacks->stack_b);
		ft_printf("rr\n");
		(stacks->operation_count)++;
	}
	while (ops->rrr--)
	{
		reverse_rotate(stacks->stack_a);
		reverse_rotate(stacks->stack_b);
		ft_printf("rrr\n");
		(stacks->operation_count)++;
	}
}

void	push_all_to_a(t_stacks *stacks)
{
	while (stacks->stack_b->size)
	{
		push_a(stacks);
		ft_printf("pa\n");
		(stacks->operation_count)++;
	}
}

void	sort_stack(t_stacks *stacks)
{
	int		i;
	t_ops	*ops;

	i = 0;
	ops = init_operations();
	while (i++ < 2)
	{
		push_b(stacks);
		ft_printf("pb\n");
		(stacks->operation_count)++;
	}
	while (stacks->stack_a->size)
	{
		get_cheapest(stacks, ops);
		single_rotations(stacks, ops);
		double_rotations(stacks, ops);
		push_b(stacks);
		ft_printf("pb\n");
		(stacks->operation_count)++;
	}
	sort_b(stacks, ops);
	push_all_to_a(stacks);
	free_operations(ops);
}
