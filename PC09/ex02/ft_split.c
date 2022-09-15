/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:44 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/15 19:52:57 by ejanssen         ###   ########.fr       */
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
	if (array == NULL)
		return (NULL);
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
	return (array);
}

/*int main()
{
	char *sentence = "Hello this is a sentence with 8 words";

	char **splited_sentence;
	int split_cnt = 0;

	splited_sentence  = ft_split(sentence," ");

	while (splited_sentence[split_cnt] != NULL)
	{
		printf("%s\n",splited_sentence[split_cnt]);
		split_cnt++;
	}
	while (split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);
	splited_sentence = ft_split(sentence,"i");
	while (splited_sentence[split_cnt] != NULL)
	{
		printf("%s\n",splited_sentence[split_cnt]);
		split_cnt++;
	}
	while (split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);
	printf("\n\n");
	char *sentece2 = "there are, a lot of:separators * in this %sentence";
		splited_sentence = ft_split(sentece2,",:*%");
	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s",splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);
	printf("\n\n");
	char *sentence3 = "Hello, , World, Salut";
	splited_sentence = ft_split(sentence3,",Sl");
	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s\n",splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);

	split_cnt = 0;
	printf("\n\n");

	char *sentence4 = "T5J0 	QQPvy4clLORZ	RDjQMoyhc9Xe0GIwJ9oAOo0Af8JXz" ;
	splited_sentence = ft_split(sentence4,"5U6FX");
	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s %p\n",splited_sentence[split_cnt], splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);
	return 0;
}
*/
