/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:40:17 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/28 22:25:07 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cheapest(t_stacks *stacks, t_ops *ops)
{
	int		i;
	int		oper_count;
	t_node	*current;
	t_ops	*temp_ops;

	i = 0;
	temp_ops = init_operations();
	current = stacks->stack_a->head;
	oper_count = get_oper_count(stacks, current->data, i, ops);
	if (!oper_count)
	{
		free_operations(temp_ops);
		return ;
	}
	while (i++ < stacks->stack_a->size - 1)
	{
		current = current->next;
		if (oper_count > get_oper_count(stacks, current->data, i, temp_ops))
			oper_count = get_oper_count(stacks, current->data, i, ops);
	}
	free_operations(temp_ops);
}
