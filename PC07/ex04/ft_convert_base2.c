/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:02:29 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/14 19:29:10 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	is_in_base(char nb, char*base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (nb == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_singles(char *base)
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

int	base_is_valid(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == ' '
			|| base[i] == '-'
			|| base[i] == '+'
			|| !is_singles(base))
			return (0);
		i++;
	}
	return (1);
}

char	*append(char *str, char a)
{
	char	*res;
	int		length;
	int		i;

	length = ft_strlen(str) + 1 + 1;
	res = malloc(length * sizeof(char));
	i = 0;
	if (ft_strlen(str) > 0)
	{
		while (str[i] != '\0')
		{
			res[i] = str[i];
			i++;
		}
	}
	res[i] = a;
	res[i + 1] = '\0';
	if (*str != '\0' )
		free(str);
	return (res);
}
