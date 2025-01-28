/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:52:47 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/28 13:53:07 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(t_stacks *stacks, int *array)
{
	free_stacks(stacks);
	free(array);
	error();
}

void	instr_2letter(char *instr, t_stacks *stacks, size_t len, int *array)
{
	if (!ft_strncmp(instr, "sa\n", len) && stacks->stack_a->size >= 2)
		swap(stacks->stack_a);
	else if (!ft_strncmp(instr, "sb\n", len) && stacks->stack_b->size >= 2)
		swap(stacks->stack_b);
	else if (!ft_strncmp(instr, "ra\n", len) && stacks->stack_a->size >= 2)
		rotate(stacks->stack_a);
	else if (!ft_strncmp(instr, "rb\n", len) && stacks->stack_b->size >= 2)
		rotate(stacks->stack_b);
	else if (!ft_strncmp(instr, "rr\n", len) && \
	stacks->stack_a->size >= 2 && stacks->stack_b->size >= 2)
	{
		rotate(stacks->stack_a);
		rotate(stacks->stack_b);
	}
	else if (!ft_strncmp(instr, "pa\n", len) && stacks->stack_b->size >= 1)
		push_a(stacks);
	else if (!ft_strncmp(instr, "pb\n", len) && stacks->stack_a->size >= 1)
		push_b(stacks);
	else
		handle_error(stacks, array);
}

void	instr_3letter(char *instr, t_stacks *stacks, size_t len, int *array)
{
	if (!ft_strncmp(instr, "rra\n", len) && stacks->stack_a->size >= 2)
		reverse_rotate(stacks->stack_a);
	else if (!ft_strncmp(instr, "rrb\n", len) && stacks->stack_b->size >= 2)
		reverse_rotate(stacks->stack_b);
	else if (!ft_strncmp(instr, "rrr\n", len) && \
	stacks->stack_a->size >= 2 && stacks->stack_b->size >= 2)
	{
		reverse_rotate(stacks->stack_a);
		reverse_rotate(stacks->stack_b);
	}
	else
		handle_error(stacks, array);
}

void	execute_instruction(char *instr, t_stacks *stacks, int *array)
{
	size_t	len;

	len = ft_strlen(instr);
	if (len == ft_strlen("sa\n"))
		instr_2letter(instr, stacks, len, array);
	else if (len == ft_strlen("rra\n"))
		instr_3letter(instr, stacks, len, array);
	else if (!ft_strncmp(instr, "Error\n", ft_strlen("Error\n")))
		return ;
	else
		handle_error(stacks, array);
}

void	init_stacks_and_execute(int *array, int size)
{
	char		*line;
	t_stacks	*stacks;

	stacks = init_stacks();
	if (!stacks)
		return ;
	if (!populate_stack(array, stacks->stack_a, size))
	{
		free_stacks(stacks);
		return ;
	}
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		execute_instruction(line, stacks, array);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	if (!stacks->stack_b->size && check_stack_order(stacks->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(stacks);
}
