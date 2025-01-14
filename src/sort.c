/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:49:05 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/13 22:22:25 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current_a = stack_a->head;
	t_node *current_b = stack_b->head;
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

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("After pushing to b\n");
	print_stack(stack_a, stack_b);
	rotate(stack_a);
	print_stack(stack_a, stack_b);

}