/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:59:17 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 19:20:26 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stacks->stack_a->head;
	current_b = stacks->stack_b->head;
	ft_printf("stack a:\n");
	while (current_a)
	{
		ft_printf("%d, ", current_a->data);
		current_a = current_a->next;
	}
	ft_printf("\nstack b:\n");
	while (current_b)
	{
		ft_printf("%d, ", current_b->data);
		current_b = current_b->next;
	}
	ft_printf("\n");
}
