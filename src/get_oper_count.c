/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_oper_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:22:48 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 19:23:52 by jgrigorj         ###   ########.fr       */
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
