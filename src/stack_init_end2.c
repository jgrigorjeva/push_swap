/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_end2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:07:54 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 16:05:14 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = init_stack();
	stacks->stack_b = init_stack();
	stacks->operation_count = 0;
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	free(stacks);
}

t_ops	*init_operations(void)
{
	t_ops	*ops;

	ops = malloc(sizeof(t_ops));
	if (!ops)
		return (NULL);
	ops->ra = 0;
	ops->rb = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rr = 0;
	ops->rrr = 0;
	ops->combined_ops = 0;
	return (ops);
}

void	free_operations(t_ops *ops)
{
	if (!ops)
		return ;
	free (ops);
}
