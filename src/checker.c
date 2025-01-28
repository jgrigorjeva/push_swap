/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:53:19 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/28 13:53:01 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*array;
	int		size;

	size = argc - 1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (1);
	check_input(argc, argv, array);
	if (!normalize_array(array, size))
		init_stacks_and_execute(array, size);
	free (array);
}
