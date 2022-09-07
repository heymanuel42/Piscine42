/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:14:52 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/07 09:30:49 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_rec(int nb)
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
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_rec(nb * -1);
	}
	else
		ft_putnbr_rec(nb);
}
