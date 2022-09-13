/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PC07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:51:29 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/13 17:30:51 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(char *s1);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size, char **s2, char *sep);
char	**ft_split(char *str, char *charset);
int	main(int argc, char **argv)
{
	char	*s1 = "Hello world";
	char	*cpy = ft_strdup(s1);

	printf("%s\n", s1);
	cpy[3] = 'X';
	printf("%s\n", cpy);
	free(cpy);

	int	*range = ft_range(40,100);
	for(int i = 0; i < 60; i++)
	{
		printf("%d ,", range[i]);
	}

	printf("\n");
	free(range);

	char *test[10000];
	for(int i = 0; i < 10000; i++)
	{
		test[i] = "salut";
	}
	(void) argc;
	(void) argv;
		char	*res;
		res = ft_strjoin(10000, test, ", ");

		printf("%s\n",res);
		free(res);

	char *sentence = "Hello this is a sentence with 8 words";

	char **splited_sentence;
	int split_cnt = 0;

	splited_sentence  = ft_split(sentence," ");

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
	splited_sentence = ft_split(sentence,"i");
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

	char *sentece2 = "Hello espace this espace is espace not espace readable";
		splited_sentence = ft_split(sentece2," espace ");
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

	char *sentence3 = "       	            	    	             ";
	splited_sentence = ft_split(sentence3,"    ");
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

	return 0;
}
