/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:32:39 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 19:19:49 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		return (0);
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
	return (1);
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		data;

	if (stack->head == NULL)
		return (-1);
	temp = stack->head;
	data = temp->data;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	free(temp);
	stack->size--;
	return (data);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
