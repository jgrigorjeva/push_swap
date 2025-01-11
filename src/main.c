/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:51:04 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/01/11 22:03:29 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

// only considering the input in the form of separate numbers, no single string is accepted
void	check_input(int argc, char **argv)
{
	if (argc < 3)
		error();
	ft_printf("OK\n");
	(void)argv;
}

int main(int argc, char **argv)
{
	check_input(argc, argv);
}