/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_end2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:07:54 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/22 19:15:09 by jgrigorj         ###   ########.fr       */
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