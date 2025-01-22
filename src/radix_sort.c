/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:49:05 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/20 15:45:48 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// here, I am using the radix sort algorithm, it is optimized (reduces the number of opertions by cca 20 %), but the result is still far from meeting the benchmark.
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


int	binary_digits(int size)
{
	int	i;

	i = 0;
	while (size)
	{
		size /= 2;
		i++;
	}
	return (i);
}

void	empty_b(t_stack *stack_b, t_stack *stack_a, int *operation_count)
{
	int	stack_size;

	stack_size = stack_b->size;
	while (stack_size)
	{
		push_a(stack_a, stack_b);
		ft_printf("pa\n");
		(*operation_count)++;
		stack_size = stack_b->size;
	}
}

int	pbs_to_avoid(t_stack *stack, int i)
{
	int		not_to_pb;
	t_node	*current;

	current = stack->head;
	not_to_pb = 0;

	while (current)
	{
		if (!(current -> data >> i & 1) && (current -> data >> (i + 1) & 1))
			not_to_pb++;
		else
			not_to_pb = 0;
		current = current->next;
	}
	return (not_to_pb);
}

int	pbs_to_avoid_last(t_stack *stack)
{
	int		not_to_pb;
	int		value;
	t_node	*current;

	current = stack->head;
	not_to_pb = 0;
	value = 0;
	while (current)
	{
		if ((current -> data == value + 1))
			not_to_pb++;
		else
			not_to_pb = 1;
		value = current -> data;
		current = current->next;
	}
	return (not_to_pb);
}

void	select_pb(t_stack *stack_a, t_stack *stack_b, int i, int *operation_count)
{
	int	stack_size;

	stack_size = stack_a->size - pbs_to_avoid(stack_a, i);
	while (stack_size--)
	{
		if (!((stack_a->head->data) >> i & 1) && (!check_stack_order(stack_a)))
		{
			push_b(stack_a, stack_b);
			ft_printf("pb\n");
			(*operation_count)++;
		}
		else if (stack_size >= 0 && (!check_stack_order(stack_a)))
		{
			rotate(stack_a);
			ft_printf("ra\n");
			(*operation_count)++;
		}
		else
			return ;
	}
}

void	select_pb_last(t_stack *stack_a, t_stack *stack_b, int i, int *operation_count)
{
	int	stack_size;

	stack_size = stack_a->size - pbs_to_avoid_last(stack_a);
	while (stack_size--)
	{
		if (!((stack_a->head->data) >> i & 1) && (!check_stack_order(stack_a)))
		{
			push_b(stack_a, stack_b);
			ft_printf("pb\n");
			(*operation_count)++;
		}
		else if (stack_size >= 0 && (!check_stack_order(stack_a)))
		{
			rotate(stack_a);
			ft_printf("ra\n");
			(*operation_count)++;
		}
		else
			return ;
	}
}

int	map_stack(t_stack *stack, int i)
{
	int		one;
	int		two;
	int		three;
	t_node	*current;

	current = stack->head;
	one = 0;
	two = 0;
	three = 0;
	while (current)
	{
		if ((current -> data >> i & 1) && !(current -> data >> (i + 1) & 1))
			one = 1;
		if (!(current -> data >> i & 1) && (current -> data >> (i + 1) & 1))
			two = 10;
		if ((current -> data >> i & 1) && (current -> data >> (i + 1) & 1))
			three = 100;
		current = current->next;
	}
	return (one + two + three);
}


// void	select_push_b2(t_stack *stack_a, t_stack *stack_b, int i, int *operation_count)
// {
// 	int	stack_size;

// 	stack_size = 0;
// 	// select group 00
// 	if (map_stack(stack_a, i) >= 1)
// 		stack_size = stack_a->size;

// 	ft_printf("Select 00\n");
// 	while (stack_size-- && stack_a->head)
// 	{
// 	if (!((stack_a->head->data) >> i & 1) && !((stack_a->head->data) >> (i + 1) & 1))
// 		{
// 			push_b(stack_a, stack_b);
// 			ft_printf("pb\n");
// 			(*operation_count)++;
// 		}
// 		else if (stack_size > 1)
// 		{
// 			rotate(stack_a);
// 			ft_printf("ra\n");
// 			(*operation_count)++;
// 		}
// 		else
// 			return ;
// 	}
// 	// select group 01
// 	if (map_stack(stack_a, i) >= 10)
// 		stack_size = stack_a->size;
// 	ft_printf("Select 01\n");
// 	while (stack_size-- && stack_a->head)
// 	{
// 		if (((stack_a->head->data) >> i & 1) && !((stack_a->head->data) >> (i + 1) & 1))
// 		{
// 			push_b(stack_a, stack_b);
// 			ft_printf("pb\n");
// 			(*operation_count)++;
// 		}
// 		else if (stack_size > 1)
// 		{
// 			rotate(stack_a);
// 			ft_printf("ra\n");
// 			(*operation_count)++;
// 		}
// 		else
// 			return ;
// 	}
// 	// select group 10
// 	if (map_stack(stack_a, i) >= 100 && stack_a->head)
// 		stack_size = stack_a->size;
// 	ft_printf("Select 10\n");
// 	while (stack_size--)
// 	{
// 		if (!((stack_a->head->data) >> i & 1) && ((stack_a->head->data) >> (i + 1) & 1))
// 		{
// 			push_b(stack_a, stack_b);
// 			ft_printf("pb\n");
// 			(*operation_count)++;
// 		}
// 		else if (stack_size > 1)
// 		{
// 			rotate(stack_a);
// 			ft_printf("ra\n");
// 			(*operation_count)++;
// 		}
// 		else
// 			return ;
// 	}
// }


// // working version by chatgpt
// void select_push_b2(t_stack *stack_a, t_stack *stack_b, int i, int *operation_count) {
//     if (!stack_a || !stack_b || !operation_count) // Check for null pointers
//         return;

//     int stack_size;

//     // Select group 00
// 	stack_size = 0;
//     if (stack_a->head && map_stack(stack_a, i) >= 1)
//         stack_size = stack_a->size;

//     ft_printf("Select 00\n");
//     while (stack_size-- && stack_a->head) {
//         if (stack_a->head && !((stack_a->head->data >> i) & 1) && !((stack_a->head->data >> (i + 1)) & 1)) {
//             push_b(stack_a, stack_b);
//             ft_printf("pb\n");
//             (*operation_count)++;
//         } else if (stack_size > 1) {
//             rotate(stack_a);
//             ft_printf("ra\n");
//             (*operation_count)++;
//         }
//     }

//     // Select group 01
// 	stack_size = 0;
//     if (stack_a->head && map_stack(stack_a, i) >= 10)
//         stack_size = stack_a->size;

//     ft_printf("Select 01\n");
//     while (stack_size-- && stack_a->head) {
//         if (stack_a->head && ((stack_a->head->data >> i) & 1) && !((stack_a->head->data >> (i + 1)) & 1)) {
//             push_b(stack_a, stack_b);
//             ft_printf("pb\n");
//             (*operation_count)++;
//         } else if (stack_size > 1) {
//             rotate(stack_a);
//             ft_printf("ra\n");
//             (*operation_count)++;
//         }
//     }

//     // Select group 10
// 	stack_size = 0;
//     if (stack_a->head && map_stack(stack_a, i) >= 100)
//         stack_size = stack_a->size;

//     ft_printf("Select 10\n");
//     while (stack_size-- && stack_a->head) {
//         if (stack_a->head && !((stack_a->head->data >> i) & 1) && ((stack_a->head->data >> (i + 1)) & 1)) {
//             push_b(stack_a, stack_b);
//             ft_printf("pb\n");
//             (*operation_count)++;
//         } else if (stack_size > 1) {
//             rotate(stack_a);
//             ft_printf("ra\n");
//             (*operation_count)++;
//         }
//     }
// }


void	select_pa(t_stack *stack_b, t_stack *stack_a, int i, int *operation_count)
{
	int	stack_size;

	stack_size = stack_b->size;
	while (stack_size--)
	{
		if ((stack_b->head->data) >> i & 1)
		{
			push_a(stack_a, stack_b);
			ft_printf("pa\n");
			(*operation_count)++;
		}
		else if (stack_size >= 0)
		{
			rotate(stack_b);
			ft_printf("rb\n");
			(*operation_count)++;
		}
	}
}



// simple one bit sort, selective push back to a
void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i_max;
	int	i;
	int	operation_count;

	i_max = binary_digits(size - 1);
	i = 0;
	operation_count = 0;
	while (i < i_max - 1)
	{
		ft_printf("iteration %i\n", i);
		print_stack(stack_a, stack_b);
		ft_printf("push to a\n", i);
		if (stack_b->size >= 1)
			select_pa(stack_b, stack_a, i, &operation_count);
		ft_printf("push to b\n", i);
		select_pb(stack_a, stack_b, i, &operation_count);
		i++;
		// if (i == i_max && stack_b->size >= 1)
		// 	empty_b(stack_b, stack_a, &operation_count);
	}
	// last iteration
	ft_printf("iteration %i\n", i);
	print_stack(stack_a, stack_b);
	if (stack_b->size >= 1)
		select_pa(stack_b, stack_a, i, &operation_count);
	select_pb_last(stack_a, stack_b, i, &operation_count);
	ft_printf("empty b\n", i);
	if (stack_b->size >= 1)
		empty_b(stack_b, stack_a, &operation_count);
	print_stack(stack_a, stack_b);
	check_stack_order(stack_a);
	ft_printf("operation count: %i\n", operation_count);

}

// // simple one bit sort, simple push back to a
// void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
// {
// 	int	i_max;
// 	int	i;
// 	int	operation_count;

// 	i_max = binary_digits(size - 1);
// 	i = 0;
// 	operation_count = 0;
// 	while (i < i_max)
// 	{
// 		ft_printf("iteration %i\n", i);
// 		print_stack(stack_a, stack_b);
// 		select_pb(stack_a, stack_b, i, &operation_count);
// 		print_stack(stack_a, stack_b);
// 		if (stack_b->size >= 1)
// 			empty_b(stack_b, stack_a, &operation_count);
// 		i++;
// 	}
// 	print_stack(stack_a, stack_b);
// 	check_stack_order(stack_a);
// 	ft_printf("operation count: %i\n", operation_count);
// }


// // two bit sort simple
// void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
// {
// 	int	i_max;
// 	int	i;
// 	int	operation_count;

// 	i_max = binary_digits(size - 1);
// 	i = 0;
// 	operation_count = 0;
// 	while (i < i_max)
// 	{
// 		ft_printf("iteration %i\n", i);
// 		print_stack(stack_a, stack_b);
// 		if (!check_stack_order_general(stack_a))
// 			select_push_b2(stack_a, stack_b, i, &operation_count);
// 		print_stack(stack_a, stack_b);
// 		if (stack_b->size >= 1)
// 			empty_b(stack_b, stack_a, &operation_count);
// 		i += 2;
// 	}
// 	print_stack(stack_a, stack_b);
// 	check_stack_order(stack_a);
// 	ft_printf("operation count: %i\n", operation_count);
// }