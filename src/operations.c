/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:45:32 by jgrigorj          #+#    #+#             */
/*   Updated: 2024/12/11 19:10:29 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move head to tail
void	rotate(t_stack *stack)
{
	t_node	*temp;

	if (stack->size <= 1)
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	temp->next = NULL;
	temp->prev = stack->tail;
	stack->tail->next = temp;
	stack->tail = temp;
}

// move tail to head
void	reverse_rotate(t_stack *stack)
{
	t_node	*temp;

	if (stack->size <= 1)
		return ;
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	temp->prev = NULL;
	temp->next = stack->head;
	stack->head->prev = temp;
	stack->head = temp;
}

// push a (i.e. move node from top of stack b to top of stack a)
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_b->head == NULL)
		return ;
	data = pop(stack_b);
	push(stack_a, data);
}

// push b (i.e. move node from top of stack a to top of stack b)
void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_a->head == NULL)
		return ;
	data = pop(stack_a);
	push(stack_b, data);
}