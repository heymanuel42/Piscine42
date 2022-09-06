/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:41 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/01 11:14:25 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(char *c1, char *c2)
{
	if ((c1[0] < c2[0])
		|| (c1[0] == c2[0] && c1[1] < c2[1]))
	{
		write(1, c1, 2);
		write(1, " ", 2);
		write(1, c2, 2);
		if (!(c1[0] == '9'
				&& c1[1] == '8'
				&& c2[0] == '9'
				&& c2[1] == '9'))
			write(1, ", ", 2);
		else
			write(1, "\n", 1);
	}
}

void	reset(char *c)
{
	c[0] = '0';
	c[1] = '0';
}

void	increment(char *c)
{
	if (c[1] >= '9')
	{
		c[1] = '0';
		c[0]++;
	}
	c[1]++;
}

void	ft_print_comb2(void)
{
	char	l_comb[2];
	char	r_comb[2];

	reset(l_comb);
	while (!(l_comb[0] == '9' && l_comb[1] == '8'))
	{
		increment(l_comb);
		reset(r_comb);
		while (!(r_comb[0] == '9' && r_comb[1] == '9'))
		{
			increment(r_comb);
			print_comb(l_comb, r_comb);
		}
	}
}
