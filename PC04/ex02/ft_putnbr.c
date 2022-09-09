/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:27:56 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/08 11:15:15 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_rec(long nb)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbr_rec(nb / 10);
		ft_putnbr_rec(nb % 10);
	}
	else
	{
		c = '0' + nb;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	long	ln;

	ln = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_rec(ln * -1);
	}
	else
		ft_putnbr_rec(nb);
}
