/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:29:13 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/27 23:08:57 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_num(char *str)
{
	int	sign;
	int	i;
	int	digit;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - 48;
		if (value > (INT_MAX - digit) / 10)
			return (0);
		value = (value * 10) + str[i++] - 48;
	}
    if (str[i] != '\0')
		return (0);
	value *= sign;
	return (value);
}

void	populate_array(char **argv, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = get_num(argv[i + 1]);
		if (get_num(argv[i + 1]) == 0 && \
		!(argv[i + 1][0] == '0' && argv[i + 1][1] == '\0'))
		{
			free(array);
			error();
		}
		i++;
	}
}

int	populate_stack(int *array, t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!push(stack, array[size - i - 1]))
			return (0);
		i++;
	}
	return (1);
}
