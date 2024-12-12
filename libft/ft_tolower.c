/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:39:39 by jgrigorj          #+#    #+#             */
/*   Updated: 2024/07/19 17:50:51 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

// #include <stdio.h>
// int main(void)
// {
// 	char ch[] = {'a', 'B', 'c', 'Y', 'z', '1', '!'};
// 	int i = 0;
// 	while (i < 7)
// 	{
// 		printf("%c,", ft_tolower(ch[i]));
// 		i++;
// 	}
// 	return (0);
// }