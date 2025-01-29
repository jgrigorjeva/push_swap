/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:29:13 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/30 00:08:56 by jgrigorj         ###   ########.fr       */
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
	return (value * sign);
}

void	populate_arr(char **temp_arr, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = get_num(temp_arr[i]);
		if (get_num(temp_arr[i]) == 0 && \
		!(temp_arr[i][0] == '0' && temp_arr[i][1] == '\0'))
		{
			free(array);
			i = 0;
			while (temp_arr[i])
				free(temp_arr[i++]);
			free(temp_arr);
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

char	**parse_input(char *argv, int *size)
{
	char	**temp_array;
	int		i;

	temp_array = ft_split(argv, ' ');
	if (!temp_array)
		exit (1);
	*size = 0;
	while (temp_array[*size])
		(*size)++;
	if (*size < 2)
	{
		i = 0;
		while (temp_array[i])
			free(temp_array[i++]);
		free(temp_array);
		error();
	}
	return (temp_array);
}

char	**get_input(int argc, char **argv, int *size)
{
	char	**temp_array;
	int		i;

	temp_array = NULL;
	if (argc < 2)
		error();
	else if (argc == 2)
		temp_array = parse_input(argv[1], size);
	else
	{
		temp_array = malloc(sizeof(char *) * argc);
		if (!temp_array)
			exit (1);
		i = 0;
		while (i < argc - 1)
		{
			temp_array[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		temp_array[i] = NULL;
		*size = argc - 1;
	}
	return (temp_array);
}
