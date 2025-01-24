/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:39:51 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/24 00:07:44 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count_rarb(t_stacks *stacks, int num, int orig_index, t_ops *ops)
{
	int	target_index;
	int	count_ra_rb;

	target_index = get_target_index(stacks->stack_b, num);
	ops->ra = orig_index;
	ops->rb = target_index;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	if (ops->ra > ops->rb)
	{
		count_ra_rb = ops->ra;
		ops->rr = ops->rb;
		ops->ra = count_ra_rb - ops->rr;
		ops->rb = 0;
	}
	else
	{
		count_ra_rb = ops->rb;
		ops->rr = ops->ra;
		ops->rb = count_ra_rb - ops->rr;
		ops->ra = 0;
	}
	ops->combined_ops = count_ra_rb;
	// ft_printf("ra_rb num %i, original index %i, target index %i, operation count %i\n", num, orig_index, target_index, count_ra_rb);
	return (count_ra_rb);
}

int	get_count_rarrb(t_stacks *stacks, int num, int orig_index, t_ops *ops)
{
	int	target_index;
	int	count_rarrb;

	target_index = get_target_index(stacks->stack_b, num);
	ops->ra = orig_index;
	ops->rb = 0;
	ops->rra = 0;
	ops->rrb = stacks->stack_b->size - target_index;
	ops->rr = 0;
	ops->rrr = 0;
	count_rarrb = ops->ra + ops->rrb;
	ops->combined_ops = count_rarrb;
	// ft_printf("rarrb num %i, original index %i, target index %i, operation count %i\n", num, orig_index, target_index, count_rarrb);
	return (count_rarrb);
}

int	get_count_rrarb(t_stacks *stacks, int num, int orig_index, t_ops *ops)
{
	int	target_index;
	int	count_rrarb;

	target_index = get_target_index(stacks->stack_b, num);
	ops->ra = 0;
	ops->rra = stacks->stack_a->size - orig_index;
	ops->rb = target_index;
	ops->rrb = 0;
	ops->rr = 0;
	ops->rrr = 0;
	count_rrarb = ops->rra + ops->rb;
	ops->combined_ops = count_rrarb;
	// ft_printf("rrarb num %i, original index %i, target index %i, operation count %i\n", num, orig_index, target_index, count_rrarb);
	return (count_rrarb);
}

int	get_count_rrab(t_stacks *stacks, int num, int orig_index, t_ops *ops)
{
	int	target_index;
	int	count_rrab;

	target_index = get_target_index(stacks->stack_b, num);
	ops->ra = 0;
	ops->rb = 0;
	ops->rra = stacks->stack_a->size - orig_index;
	ops->rrb = stacks->stack_b->size - target_index;
	ops->rr = 0;
	if (ops->rra > ops->rrb)
	{
		count_rrab = ops->rra;
		ops->rrr = ops->rrb;
		ops->rra = count_rrab - ops->rrr;
		ops->rrb = 0;
	}
	else
	{
		count_rrab = ops->rrb;
		ops->rrr = ops->rra;
		ops->rrb = count_rrab - ops->rrr;
		ops->rra = 0;
	}
	ops->combined_ops = count_rrab;
	// ft_printf("rrab num %i, original index %i, target index %i, operation count %i\n", num, orig_index, target_index, count_rrab);
	return (count_rrab);
}

int	get_oper_count(t_stacks *stacks, int num, int orig_index, t_ops *ops)
{
	int		oper_count;
	t_ops	*temp_ops;

	temp_ops = init_operations();

	oper_count = get_count_rarb(stacks, num, orig_index, ops);
	if (oper_count > get_count_rarrb(stacks, num, orig_index, temp_ops))
		oper_count = get_count_rarrb(stacks, num, orig_index, ops);
	if (oper_count > get_count_rrarb(stacks, num, orig_index, temp_ops))
		oper_count = get_count_rrarb(stacks, num, orig_index, ops);
	if (oper_count > get_count_rrab(stacks, num, orig_index, temp_ops))
		oper_count = get_count_rrab(stacks, num, orig_index, ops);
	free_operations(temp_ops);
	return (oper_count);
}

int	get_next_index(t_stacks *stacks, t_ops *ops)
{
	int		index;
	int		i;
	int		oper_count;
	t_node	*current;
	t_ops	*temp_ops;

	index = 0;
	i = 0;
	temp_ops = init_operations();
	current = stacks->stack_a->head;
	oper_count = get_oper_count(stacks, current->data, i, ops);
	// ft_printf("num %i, index %i, operation count %i, direction %i\n", current->data, i, get_oper_count(stacks, current->data, i, direction), *direction);
	if (!oper_count)
	{
		return (index);
		free_operations(temp_ops);
	}
	while (i++ < stacks->stack_a->size - 1)
	{
		current = current->next;
		// ft_printf("num %i, index %i, operation count %i, direction %i\n", current->data, i, get_oper_count(stacks, current->data, i, direction), *direction);
		if (oper_count > get_oper_count(stacks, current->data, i, temp_ops))
		{
			oper_count = get_oper_count(stacks, current->data, i, ops);
			index = i;
		}
	}
	free_operations(temp_ops);
	return (index);
}


void	sort_stack(t_stacks *stacks)
{
	int		i;
	t_ops	*ops;
	int		max_index;

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
		get_next_index(stacks, ops);
		// ft_printf("new iteration\n");
		// ft_printf("next target index %i\n", get_target_index())
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
		push_b(stacks);
		ft_printf("pb\n");
		(stacks->operation_count)++;
		// print_stacks(stacks);
	}
	max_index = 0;
	int max_value;
	max_value = get_max_value(stacks->stack_b, &max_index);
	if (max_index > (stacks->stack_b->size)/2)
	{
		ops->rb = 0;
		ops->rrb = stacks->stack_b->size - max_index;
	}
	else
	{
		ops->rb = max_index;
		ops->rrb = 0;
	}
		
	// ft_printf("max_index: %i\n", max_index);
	// ft_printf("rb: %i, rrb: %i\n", ops->rb, ops->rrb);
	while (ops->rb--)
	{
		rotate(stacks->stack_b);
		ft_printf("rb\n");
		(stacks->operation_count)++;
	}
	while (ops->rrb--)
	{
		reverse_rotate(stacks->stack_b);
		ft_printf("rrb\n");
		(stacks->operation_count)++;
	}
	while (stacks->stack_b->size)
	{
		push_a(stacks);
		ft_printf("pa\n");
		(stacks->operation_count)++;
	}
	// ft_printf("operation count: %i\n", stacks->operation_count);
	// print_stacks(stacks);
	// check_stack_order(stacks->stack_a);
	free_operations(ops);
	(void)max_value;
}
