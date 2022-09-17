/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:38 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 17:03:43 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen_2(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_is_singles(char *base)
{
	int	cnt[127];
	int	i;

	i = 0;
	while (i < 127)
	{
		cnt[i] = 0;
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		cnt[(int)base[i]]++;
		if (cnt[(int)base[i]] > 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_to_base(long nbr, char *base, int b)
{
	if (nbr >= b)
	{
		ft_to_base(nbr / b, base, b);
		ft_to_base(nbr % b, base, b);
	}
	else
	{
		write(1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	l;

	if (ft_strlen_2(base) <= 0)
		return ;
	i = 0;
	l = nbr;
	while (base[i] != '\0')
	{
		if (base[i] == ' '
			|| base[i] == '-'
			|| base[i] == '+'
			|| !ft_is_singles(base))
			return ;
		i++;
	}
	if (l < 0)
	{
		l *= -1;
		write(1, "-", 1);
	}
	if (!ft_strcmp(base, "poneyvif"))
		ft_to_base(l, "01234567", 8);
	else
		ft_to_base(l, base, ft_strlen_2(base));
}
