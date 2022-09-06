/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:12:18 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 15:12:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen_4(char *s)
{
	char	*start;

	start = s;
	while (*s++)
		;
	return (s - start - 1);
}

int	ft_strncmp_4(char *s1, char *s2, unsigned int n)
{
	while (n - 1
		&& *s1
		&& (*s1 == *s2))
	{
		s1++;
		s2++;
		--n;
	}
	return (*s1 - *s2);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		sub_str_len;

	sub_str_len = ft_strlen_4(to_find);
	while (*str)
	{
		if (!ft_strncmp_4(str, to_find, sub_str_len))
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
