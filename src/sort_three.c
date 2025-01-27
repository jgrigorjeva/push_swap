/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:04:06 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 19:05:38 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_0first(t_stacks *stacks)
{
	if (stacks->stack_a->head->next->data == 1)
	{
		rotate(stacks->stack_a);
		ft_printf("ra\n");
	}
	else
	{
		reverse_rotate(stacks->stack_a);
		swap(stacks->stack_a);
		ft_printf("rra\nsa\n");
		stacks->operation_count++;
	}
}

static void	sort_three_1first(t_stacks *stacks)
{
	if (stacks->stack_a->head->next->data == 2)
	{
		reverse_rotate(stacks->stack_a);
		ft_printf("rra\n");
	}
	else
	{
		swap(stacks->stack_a);
		ft_printf("sa\n");
	}
}

void	sort_three(t_stacks *stacks)
{
	if (stacks->stack_a->head->data == 0)
		sort_three_0first(stacks);
	if (stacks->stack_a->head->data == 1)
		sort_three_1first(stacks);
	else if (stacks->stack_a->head->next->data == 0)
	{
		rotate(stacks->stack_a);
		ft_printf("ra\n");
	}
	else
	{
		swap(stacks->stack_a);
		reverse_rotate(stacks->stack_a);
		ft_printf("sa\nrra\n");
		stacks->operation_count++;
	}
	stacks->operation_count++;
}
