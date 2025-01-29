/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:13:26 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/29 21:29:00 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

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

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		operation_count;
}	t_stacks;

// to store operations for the current node
typedef struct s_operations
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	combined_ops;
}	t_ops;

// handling input array
typedef struct s_pair
{
	int	value;
	int	original_index;
}	t_pair;
int			normalize_array(int *array, int size);
void		populate_array(char **argv, int *array, int size);

// structures inicialization and handling
t_stacks	*init_stacks(void);
t_stack		*init_stack(void);
t_node		*create_node(int data);
int			push(t_stack *stack, int data);
int			pop(t_stack *stack);
void		free_stacks(t_stacks *stacks);
void		free_stack(t_stack *stack);
t_ops		*init_operations(void);
void		free_operations(t_ops *ops);

// operations
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		swap(t_stack *stack);

// checks
void		check_duplicates(int size, int *array);
void		check_input(int argc, char **argv, int *array, int *size);
int			check_stack_order(t_stack *stack);

// error
int			error(void);

// utils
void		print_stacks(t_stacks *stacks);
int			get_min_value(t_stack *stack, int *position);
int			get_max_value(t_stack *stack, int *position);
int			get_target_index(t_stack *stack, int num);
void		get_cheapest(t_stacks *stacks, t_ops *ops);
int			get_oper_count(t_stacks *stacks, int num, \
			int orig_index, t_ops *ops);

// main processes
void		populate_array(char **argv, int *array, int size);
int			populate_stack(int *array, t_stack *stack, int size);
void		init_and_sort_stack(int *array, int size);
void		sort_stack(t_stacks *stacks);
void		sort_small(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		get_cheapest(t_stacks *stacks, t_ops *ops);
void		sort_b(t_stacks *stacks, t_ops *ops);
void		push_all_to_a(t_stacks *stacks);

// bonus
void		init_stacks_and_execute(int *array, int size);


#endif