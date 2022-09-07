/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:38 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/07 16:37:22 by ejanssen         ###   ########.fr       */
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

void	ft_to_base(unsigned int nbr, char *base, unsigned int b)
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
	int	b;
	int i;
	int error;
	int cnt[127];

	error = 0;
	i = 0;
	while (i < 127)
	{
		cnt[i] = 0;
		i++;
	}
	b = ft_strlen_2(base);
	if(b > 0)
	{
		i = 0;
		while (base[i] != '\0')
		{
			if (base[i] == '-' || base[i] == '+')
				error = 1;
			cnt[(int)base[i]]++;
			if (cnt[(int)base[i]] > 1)
				error = 1;
			i++;
		}
		if (!error)
			ft_to_base(nbr, base, b);
	}
}
