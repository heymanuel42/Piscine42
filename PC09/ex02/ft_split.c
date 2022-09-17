/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:44 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 09:42:17 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*substring(char *s, int start, int end)
{
	char	*sub;
	char	*begin;
	int		i;

	sub = malloc((end - start +1) * sizeof (char));
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
	char	*sub;
	int		nwords;
	int		i;
	int		sepidx;

	nwords = count_words(str, charset);
	array = (char **)malloc((nwords + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (nwords > 0)
	{
		sepidx = getnextsep(str, charset);
		sub = substring(str, 0, sepidx);
		if (!ft_isspace(sub))
		{
			array[i] = sub;
			i ++;
		}
		str += 1 + sepidx;
		nwords--;
	}
	array[i] = NULL;
	return (array);
}

/*void test(char *sentence, char *charset)
{
	char **splited_sentence;
	int split_cnt = 0;

	splited_sentence  = ft_split(sentence,charset);
	while (splited_sentence[split_cnt] != NULL)
	{
		printf("%s\n",splited_sentence[split_cnt]);
		if(splited_sentence[split_cnt] != NULL)
			free(splited_sentence[split_cnt]);
		splited_sentence[split_cnt] = NULL;
		split_cnt++;
	}
	if(splited_sentence != NULL)
		free(*splited_sentence);
	*splited_sentence = NULL;
	printf("-------------------------------------------------------------\n\n");
}
int main()
{
	char *sentence = "9dVrHZVwABy WdktOjh674RNnAlmPO5";
	char *sentece2 = "ipk6jYCcRiipPoC9MKPsEyBoZ4s	AuuD7B6	kn";
	char *sentence3 =  "	OqQCX0cya4agR0Gq	R77YCMIKByH3ChIRKX1oLT";
	char *sentence4 = "t3bLBVnMbda7QG2wC0K	H4fQurfJdte0";

	test(sentence,"Ex Ga");
	test(sentece2,"AmiW Nyg");
	test(sentence3,"bQo");
	test(sentence4,"");

	return 0;
}*/
