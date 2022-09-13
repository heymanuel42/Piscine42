/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:44 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/13 12:14:23 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (n - 1 > 0 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	ft_strlen2(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*substring(char *s, int start, int end)
{
	char	*sub;
	char	*begin;
	int		i;

	sub = malloc(sizeof(end - start) * sizeof (char));
	begin = sub;
	i = start;
	while (i < end)
	{
		*sub = s[i];
		i++;
		sub++;
	}
	return (begin);
}

int	getnextsep(char *str, char *charset)
{
	int	i;
	int	charset_len;

	i = 0;
	charset_len = ft_strlen2(charset);
	while (ft_strncmp(charset, (str + i), charset_len) != 0 && str[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		nwords;
	int		i;
	int		sepidx;

	i = 0;
	nwords = 0;
	while (str[i] != '\0')
	{
		if (ft_strncmp((str + i), charset, ft_strlen2(charset)) == 0)
			nwords++;
		i++;
	}
	nwords++;
	array = malloc((nwords + 1) * sizeof(char *));
	i = 0;
	while (i < nwords)
	{
		sepidx = getnextsep(str, charset);
		array[i] = substring(str, 0, sepidx);
		i ++;
		str += ft_strlen2(charset) + sepidx;
	}
	array[i] = NULL;
	return (array);
}
