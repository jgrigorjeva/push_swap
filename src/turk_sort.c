/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:39:51 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/22 19:33:26 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count_rarb(t_stacks *stacks, int num, int orig_index)
{
	int	target_index;
	int	count_ra;
	int	count_rb;
	int	count_ra_rb;

	target_index = get_target_index(stacks->stack_b, num);
	count_ra = orig_index;
	count_rb = target_index;
	if (count_ra > count_rb)
		count_ra_rb = count_ra;
	else
		count_ra_rb = count_rb;
	return (count_ra_rb);
}

int	get_count_rarrb(t_stacks *stacks, int num, int orig_index)
{
	int	target_index;
	int	count_ra;
	int	count_rrb;
	int	count_rarrb;

	target_index = get_target_index(stacks->stack_b, num);
	count_ra = orig_index;
	count_rrb = stacks->stack_b->size - target_index;
	count_rarrb = count_ra + count_rrb;
	return (count_rarrb);
}

int	get_count_rrarb(t_stacks *stacks, int num, int orig_index)
{
	int	target_index;
	int	count_rra;
	int	count_rb;
	int	count_rrarb;

	target_index = get_target_index(stacks->stack_b, num);
	count_rra = stacks->stack_a->size - orig_index;
	count_rb = target_index;
	count_rrarb = count_rra + count_rb;
	return (count_rrarb);
}

int	get_count_rrab(t_stacks *stacks, int num, int orig_index)
{
	int	target_index;
	int	count_rra;
	int	count_rrb;
	int	count_rrab;

	target_index = get_target_index(stacks->stack_b, num);
	count_rra = stacks->stack_a->size - orig_index;
	count_rrb = stacks->stack_b->size - target_index;
	count_rrab = count_rra + count_rrb;
	return (count_rrab);
}

// int	get_oper_count(t_stacks *stacks, int num, int orig_index)
// {
// 	int	oper_count;

// 	oper_count = get_count_ra_rb(stacks, num, orig_index);
// 	if (oper_count > count_ra_rrb())
// 		oper_count = cont_ra_rrb();
// 	return (oper_count);
// }

void	sort_stack(t_stacks *stacks, int size)
{
	int	i;
	int	oper_count;

	i = 0;
	oper_count = 0;
	while (i++ < 2)
	{
		push_b(stacks);
		ft_printf("pb\n");
		oper_count++;
	}
	int next_num = stacks->stack_a->head->data;
	int pos_in_b = get_target_index(stacks->stack_b, next_num);
	print_stacks(stacks);
	ft_printf("target position for number %i is %i\n", next_num, pos_in_b);
	(void)size;
}
