/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:38 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/06 16:47:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_tobin(unsigned int nbr, char *base)
{
	if (nbr >= 2)
	{
		ft_tobin(nbr / 2, base);
		ft_tobin(nbr % 2, base);
	}
	else
	{
		write(1, &base[nbr], 1);
	}
}

void	ft_tooct(int nbr, char *base)
{
	if (nbr >= 8)
	{
		ft_tooct(nbr / 8, base);
		ft_tooct(nbr % 8, base);
	}
	else
	{
		write(1, &base[nbr], 1);
	}	
}

void	ft_tohex(int nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_tohex(nbr / 16, base);
		ft_tohex(nbr % 16, base);
	}
	else
	{
		write(1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!ft_strcmp(base, "0123456789ABCDEF"))
	{
		ft_tohex(nbr, base);
	}
	else if (!ft_strcmp(base, "01"))
	{
		ft_tobin(nbr, base);
	}
	else if (!ft_strcmp(base, "poneyvif"))
	{
		ft_tooct(nbr, "01234567");
	}
}
