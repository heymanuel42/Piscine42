/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:12:18 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/06 17:04:24 by ejanssen         ###   ########.fr       */
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
	while (n - 1 > 0 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	sub_str_len;
	int	i;

	i = 0;
	sub_str_len = ft_strlen_4(to_find);
	if (sub_str_len <= 0)
		return (str);
	while (str[i] != '\0')
	{
		if (!ft_strncmp_4(str + i, to_find, sub_str_len))
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
