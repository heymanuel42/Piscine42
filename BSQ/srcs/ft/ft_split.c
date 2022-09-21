/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:44 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/21 17:29:49 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*substring(char *s, int start, int end)
{
	char	*sub;
	int		i;

	sub = malloc((end - start +1) * sizeof (char));
	i = 0;
	while (i < end)
	{
		sub[i] = s[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
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
		|| *str == 127
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
	char	*sub;
	int		nwords;
	int		i;
	int		sepidx;

	sub = NULL;
	nwords = count_words(str, charset);
	array = (char **)malloc((nwords + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (nwords > 0)
	{
		sepidx = getnextsep(str, charset);
		sub = substring(str, 0, sepidx);
		array[i++] = sub;
		str += 1 + sepidx;
		nwords--;
	}
	array[i] = NULL;
	return (array);
}
