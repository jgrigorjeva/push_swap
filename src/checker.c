/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:53:19 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/29 23:54:20 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*array;
	char	**temp_array;
	int		size;
	int		i;

	temp_array = get_input(argc, argv, &size);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (1);
	populate_arr(temp_array, array, size);
	check_duplicates(size, array);
	if (!normalize_array(array, size))
		init_stacks_and_execute(array, size);
	i = 0;
	while (temp_array[i])
		free(temp_array[i++]);
	free(temp_array);
	free (array);
}
