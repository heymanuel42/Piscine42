/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:47:03 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/14 17:21:43 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->size != 0)
	{
		ft_putstr(par->str);
		ft_putstr("\n");
		ft_putnbr_rec(par->size);
		ft_putstr("\n");
		ft_putstr(par->copy);
		ft_putstr("\n");
		par++;
	}
}
