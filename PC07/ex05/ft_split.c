/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:44 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/12 19:52:55 by ejanssen         ###   ########.fr       */
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

int	ft_strlen(char *str)
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
	charset_len = ft_strlen(charset);
	while (ft_strncmp(charset, (str+i), charset_len) != 0)
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		nwords;
	int		widx;
	int		i;

	i = 0;
	nwords = 0;
	while (str[i] != '\0')
	{
		if (ft_strncmp((str+i), charset, 1) == 0)
			nwords++;
		i++;
	}
	printf("%d\n", nwords);

	widx = 0;
	nwords = i;
	array = malloc(nwords * sizeof(char *));
	i = 0;
	while (i < nwords)
	{
		printf("%d\n",getnextsep(str,charset));
		i++;
	}

	return (array);
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc > 1)
	{
		char **tab = ft_split(argv[1],",");

	}
	return 0;
}
