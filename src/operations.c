/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:45:32 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/22 19:25:28 by jgrigorj         ###   ########.fr       */
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
void	push_a(t_stacks *stacks)
{
	int	data;

	if (stacks->stack_b->head == NULL)
		return ;
	data = pop(stacks->stack_b);
	push(stacks->stack_a, data);
}

// push b (i.e. move node from top of stack a to top of stack b)
void	push_b(t_stacks *stacks)
{
	int	data;

	if (stacks->stack_a->head == NULL)
		return ;
	data = pop(stacks->stack_a);
	push(stacks->stack_b, data);
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->tail = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
}
