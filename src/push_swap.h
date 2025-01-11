/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:13:26 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/11 21:35:04 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

// node structure 
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// stack structure (we will be using two linked lists - one for each stack)
typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

// for normalization
typedef struct s_pair
{
	int	value;
	int	original_index;
}	t_pair;

// structures inicialization and handling
t_stack	*init_stack(void);
t_node	*create_node(int data);
void	push(t_stack *stack, int data);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);

// operations
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);


// error
int		error(void);

#endif