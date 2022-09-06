/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:14:52 by ejanssen          #+#    #+#             */
/*   Updated: 2022/08/31 17:13:07 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	num_length(int nb)
{
	int	nb_count;

	nb_count = 0;
	while (nb / 10)
	{
		nb_count++;
		nb = nb / 10;
	}
	return (nb_count);
}

int	m_pow(int X, int Y)
{
	int	power;
	int	i;

	power = 1;
	i = 1;
	while (i <= Y)
	{
		power = power * X;
		i++;
	}
	return (power);
}

void	ft_putnbr(int nb)
{
	int		nb_count;
	int		mod;
	int		r ;
	char	c;

	nb_count = num_length(nb);
	mod = m_pow(10, nb_count);
	r = nb;
	while (nb)
	{
		c = '0' + r / mod;
		r = r % mod;
		write(1, &c, 1);
		mod /= 10;
		nb /= 10 ;
	}
	write(1, "\n", 1);
}
