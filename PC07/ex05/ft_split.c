/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:44 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/13 23:42:08 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*substring(char *s, int start, int end)
{
	char	*sub;
	char	*begin;
	int		i;

	sub = malloc(sizeof(end - start +1) * sizeof (char));
	begin = sub;
	i = start;
	while (i < end)
	{
		*sub = s[i];
		i++;
		sub++;
	}
	*sub = '\0';
	return (begin);
}

int	getnextsep(char *str, char *charset)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (charset[j] != '\0')
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int	ft_isspace(char *str)
{
	while (*str == '\t'
		|| *str == '\n'
		|| *str == '\v'
		|| *str == '\f'
		|| *str == '\r'
		|| *str == ' ')
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

int	count_words(char *str, char *charset)
{
	int		i;
	int		j;
	int		nwords;

	i = 0;
	j = 0;
	nwords = 0;
	while (charset[j] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] == charset[j])
					++nwords;
			i++;
		}
		i = 0;
		j++;
	}
	return (++nwords);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		nwords;
	int		i;
	int		sepidx;

	nwords = count_words(str, charset);
	array = malloc((nwords + 1) * sizeof(char *));
	i = 0;
	while (*str != '\0')
	{
		sepidx = getnextsep(str, charset);
		if (!ft_isspace(substring(str, 0, sepidx)))
		{
			array[i] = substring(str, 0, sepidx);
			i ++;
		}
		str += 1 + sepidx;
	}
	array[i] = NULL;
	while (i < nwords)
	{
		free(array[i]);
		i++;
	}
	return (array);
}
